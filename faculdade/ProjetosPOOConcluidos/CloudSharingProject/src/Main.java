import java.util.Scanner;
import cloud.*;
import dataStructures.*;

public class Main {
	
	/** 
	 * Comandos do utilizador.
	 */
	private static final String ADD = "ADD";
	private static final String UPLOAD = "UPLOAD";
	private static final String SHARE = "SHARE";
	private static final String LISTALL = "LISTALL";
	private static final String LISTFILES = "LISTFILES";
	private static final String EXIT = "EXIT";
	
	/**
	 * Feedback dado pelo programa.
	 */
	private static final String EXITING = "Exiting...\n";
	private static final String ACCOUNT_EXISTS = "Account already exists.\n";
	private static final String ACCOUNT_DOES_NOT_EXIST = "Account does not exist.\n";
	private static final String ACCOUNT_ADDED = "Account was added.\n";
	private static final String FILE_ALREADY_EXISTS = "File already exists in the account.\n";
	private static final String FILE_EXCEEDS_CAPACITY = "File size exceeds account capacity.\n";
	private static final String FILE_UPLOADED = "File uploaded into account.\n";
	private static final String FILE_DOES_NOT_EXIST = "File does not exist.\n";
	private static final String SHARING_NOT_ALLOWED = "Account does not allow file sharing.\n";
	private static final String FILE_ALREADY_SHARED = "File already shared.\n";
	private static final String FILE_SHARED = "File was shared.\n";
	private static final String HEADER_LIST_FILES = "Account files:";
	private static final String SHARED_FILE_INFO = "%s (%d MB) (shared)\n";
	private static final String OWNED_FILE_INFO = "%s (%d MB)\n"; 
	private static final String HEADER_LIST_ACCOUNTS = "All accounts:";
	private static final String ACCOUNT_INFO = "%s (%s)\n";
	
	/**
	 * Programa principal. Invoca interpretador de comandos.
	 * @param args - argumentos para execucao da aplicacao. Nao sao usados neste programa.
	 */
	public static void main(String[] args) {
		Main.commands();
	}

	/**
	 * Interpretador de comandos.
	 */
	private static void commands() {
		CloudSharing dropbox = new CloudSharingClass();
		Scanner input = new Scanner(System.in);
		String c = input.next().toUpperCase();
		while (!c.equals(EXIT)) {
			switch (c) {
			case ADD:
				addAccount(input,dropbox);
				break;
			case UPLOAD:
				upload(input,dropbox);
				break;
			case SHARE:
				share(input,dropbox);
				break;
			case LISTFILES:
				listFiles(input,dropbox);
				break;
			case LISTALL:
				listAccounts(dropbox);
				break;
			default: 
				break; 
			}
			c = input.next().toUpperCase();
		}
		System.out.println(EXITING);
		input.close();
	}

	/**
	 * Adiciona uma nova conta, se a conta ainda nao existir. Se ja existir, nao faz nada.
	 * @param in - o input de onde os dados vao ser lidos.
	 * @param dropbox - o CloudSharing no qual se vai adicionar a nova conta.
	 */
	private static void addAccount(Scanner in, CloudSharing dropbox) {
		String email = in.next();
		String type = in.next();
		if (dropbox.hasUser(email)) 
			System.out.println(ACCOUNT_EXISTS);
		else {
			dropbox.addUser(email, type);
			System.out.println(ACCOUNT_ADDED);
		}
	}

	/**
	 * Adiciona um novo ficheiro a uma conta nova conta.
	 * @param in - o input de onde os dados vao ser lidos.
	 * @param dropbox - o CloudSharing no qual se vai adicionar o novo ficheiro.
	 */
	private static void upload(Scanner in, CloudSharing dropbox) {
		String user = in.next();
		String file = in.next();
		int size = in.nextInt(); in.nextLine();
		if (!dropbox.hasUser(user))
			System.out.println(ACCOUNT_DOES_NOT_EXIST);
		else if (dropbox.hasOwnedFile(user, file))
			System.out.println(FILE_ALREADY_EXISTS);
		else if (!dropbox.hasCapacity(user,size))
			System.out.println(FILE_EXCEEDS_CAPACITY);
		else {
			dropbox.addFile(user, file, size);
			System.out.println(FILE_UPLOADED);
		}
	}

	/**
	 * Partilha de um ficheiro entre duas contas.
	 * @param in - o input de onde os dados vao ser lidos.
	 * @param dropbox - o CloudSharing no qual vai ser partilhado um ficheiro.
	 */
	private static void share(Scanner in, CloudSharing dropbox) {
		String owner = in.next();
		String other = in.next();
		String file = in.next();

		if (!dropbox.hasUser(owner) || !dropbox.hasUser(other))
			System.out.println(ACCOUNT_DOES_NOT_EXIST);
		else if (!dropbox.hasOwnedFile(owner, file))
			System.out.println(FILE_DOES_NOT_EXIST);
		else if (!dropbox.allowsSharing(owner))
			System.out.println(SHARING_NOT_ALLOWED);
		else if (dropbox.hasSharedFile(owner, other, file))
			System.out.println(FILE_ALREADY_SHARED);
		else if (!dropbox.hasSharingCapacity(owner,other,file))
			System.out.println(FILE_EXCEEDS_CAPACITY);
		else { 
			dropbox.shareFile(owner, other, file);
			System.out.println(FILE_SHARED);
		}
	}
	
	/**
	 * Lista todos os ficheiros proprietarios e partilhados de uma conta.
	 * @param in - o input de onde os dados vao ser lidos.
	 * @param dropbox - o CloudSharing a listar a informacao de uma conta.
	 */
	private static void listFiles(Scanner in, CloudSharing dropbox) {
		String user = in.next();
		if (!dropbox.hasUser(user))
			System.out.println(ACCOUNT_DOES_NOT_EXIST);
		else {
			System.out.println(HEADER_LIST_FILES);
			Iterator<File> it = dropbox.listFiles(user);
			while (it.hasNext()) {
				File file = (File) it.next();
				if (!file.getOwnerName().equals(user)) {
					System.out.printf(SHARED_FILE_INFO, file.getName(), file.getSize());
				}
				
				else {
					System.out.printf(OWNED_FILE_INFO, file.getName(), file.getSize());	

				}
				}
			System.out.println();
		}
	}

	/**
	 * Lista todas as contas.
	 * @param dropbox - o CloudSharing a listar as contas.
	 */
	private static void listAccounts(CloudSharing dropbox) {
		Iterator<User> it =  dropbox.listAll();
		System.out.println(HEADER_LIST_ACCOUNTS);
		while (it.hasNext()) {
			User user = (User) it.next();
			System.out.printf(ACCOUNT_INFO, user.getName(), user.getType());
		}
		System.out.println();

	}
}
