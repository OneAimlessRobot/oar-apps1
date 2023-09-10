package cloud;
import dataStructures.*;
public interface CloudSharing {
	/**
	 * Partilha um ficheiro entre duas contas
	 * @param src
	 * @param dst
	 * @param name
	 */
	void shareFile(User src,User dst, String name);
/**
 * Acrescenta uma conta á CloudSharing.
 * @param email
 * @param type
 */
	void addUser(String email, String type);
	/**
	 * Devolve true se já existir um utilizador com nome "name". Falso, caso contrário.
	 * @param name
	 * @return
	 */
	boolean hasUser(String name);
	/**
	 * Verifica se um utilizador com nome "userName" já possui um ficheiro com nome "fileName";
	 * @param userName
	 * @param fileName
	 * @return
	 */
	boolean hasOwnedFile(String userName,String fileName);
	/**
	 * Acrescenta um ficheiro com tamanho "fileSize" e nome "fileName" á conta de nome "userName"
	 * @param userName
	 * @param fileName
	 * @param fileSize
	 */
	void addFile(String userName,String fileName,int fileSize);
	/**
	 * Verifica se um ficheiro de tamanho "fileSize" cabe na conta de nome "userName"
	 * @param userName
	 * @param fileSize
	 */
	boolean hasCapacity(String userName,int fileSize);
	/**
	 * verifica se o utilizador é,ou não, premium
	 * @param userName
	 * @return
	 */
	boolean allowsSharing(String userName);
	/**
	 * Verifica se um ficheiro de nome fileName, cujo proprietário (que, em primeiro lugar, tem de ter um ficheiro com esse nome) 
	 * tem nome "owner", foi partilhado com um utilizador cujo nome é "otherUser"
	 * @param owner
	 * @param otherUser
	 * @param fileName
	 * @return
	 */
	
	
	boolean hasSharedFile(String owner,String otherUser,String fileName);
	
	/**
	 * 
	 * @param owner
	 * @param otherUser
	 * @param fileName
	 * @return
	 */
	
	boolean hasSharingCapacity(String owner,String otherUser,String fileName);
	/**
	 * Devolve um iterador que possui todos os utilizadores no seu array interno
	 * @return
	 */
	
	Iterator<User> listAll();
	/**
	 * Devolve um iterador de todos os ficheiros de um Utilizador de nome "userName" que foram enviados para a nuvem por ele.
	 * 
	 * @return
	 */
	
	Iterator<File> listFiles(String userName);
	
	/**
	 * Partilha um ficheiro de nome "file" cujo proprietario tem o nome "owner" com outro utilizador cujo nome e "other"
	 * @param owner
	 * @param other
	 * @param file
	 */
	void shareFile(String owner, String other, String file);
//	/**
//	 * Devolve um iterador de todos os ficheiros de um Utilizador de nome "userName" que lhe foram partilhados
//	 * @param userName
//	 * @return
//	 */
//	Iterator<File> listSharedFiles(String userName);
	int getUserUsedStorage(String user);
	int getUserRemainingStorage(String userName);
	
}
