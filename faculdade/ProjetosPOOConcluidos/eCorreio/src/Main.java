
import java.util.*;

import classes.*;
import enums.*;
import smallerClasses.*;
public class Main {

	public static void main(String[] args) {
		Scanner in=new Scanner(System.in);
		EmailApp e=new EmailAppClass();
		String option;
		boolean run=true;
		do {
			option=in.next();
			run=commandReader(in,option,e);
		}while(run);
		
		System.out.println("A terminar.\n");
		
	}
	private static boolean commandReader(Scanner in,String option,EmailApp e) {
		boolean run=true;
		if(option.equals(Commands.SAIR.toString())) {
			run=false;
			
		}
		else if(option.equals(Commands.ENVIAR.toString())) {
			sendMsg(in,e);
			
		}
		else if(option.equals(Commands.RECEBER.toString())) {

			getMsg(in,e);
			
		}
		else if(option.equals(Commands.ENVIADAS.toString())) {
			
			showSent(in,e);			
		}
		else if(option.equals(Commands.RECEBIDAS.toString())) {
			
			showReceived(in,e);			
		}
		else if(option.equals(Commands.EMAIL.toString())) {
			
			showByEmail(in,e);			
		}
		else if(option.equals(Commands.ASSUNTO.toString())) {
			
			showBySubject(in,e);			
		}
		else if(option.equals(Commands.ASSUNTOS.toString())) {
			
			showSubjects(in,e);			
		}
		return run;
		
	}
	
	private static void showSubjects(Scanner in, EmailApp e) {
		Iterator<String> it=e.getMessageSubjects();
		while(it.hasNext()) {
			String r=it.next();
			System.out.println(r);
			}
		System.out.println();
		
	}
	private static void showBySubject(Scanner in, EmailApp e) {
		
		String subject=in.next();
		try {
			Iterator<Message> it=e.getMessagesBySubject(subject);
			System.out.println(Constants.MSG_LIST_HEADER_EXT.getMsg());
			while(it.hasNext()) {
				
				Message r=it.next();//"date | assunto | email | texto"
				System.out.printf(Constants.PRINT_MSG_EXT.getMsg(),r.getDate(),r.getSubject(),r.getEmail(),r.getContents());
				
			}
			System.out.println();
		}
		catch(listBySubjectEmptyException LBSEE) {
			System.out.println(LBSEE.getMessage());
		}
		
	}
	
	private static void showByEmail(Scanner in, EmailApp e) {
		
		String email=in.next();
		try {
			Iterator<Message> it=e.getMessagesByEmail(email);
			System.out.println(Constants.MSG_LIST_HEADER_EXT.getMsg());
			while(it.hasNext()) {
				
				Message r=it.next();
				System.out.printf(Constants.PRINT_MSG_EXT.getMsg(),r.getDate(),r.getSubject(),r.getEmail(),r.getContents());
				
			}
			System.out.println();
		}
		catch(listByEmailEmptyException LBEEE) {
			System.out.println(LBEEE.getMessage());
		}
		
	}
	private static void sendMsg(Scanner in,EmailApp app) {

		in.nextLine();
		String subject=in.nextLine();
		String destination=in.next();
		in.nextLine();
		String contents=in.nextLine();
		String date=in.next();
		try {
			app.send(subject, destination, contents, date);
			System.out.printf("Mensagem registada.\n");
			System.out.println();
		} catch (DuplicateMessageException DME) {
			System.out.println(DME.getMessage());
		}
		
	}

	private static void getMsg(Scanner in,EmailApp app) {
		in.nextLine();
		String subject=in.nextLine();
		String sender=in.next();
		in.nextLine();
		String contents=in.nextLine();
		String date=in.next();
		try {
			app.receive(subject, sender, contents, date);
			System.out.printf("Mensagem registada.\n");
			System.out.println();
		} catch (DuplicateMessageException DME) {
			System.out.println(DME.getMessage());
		}
		
	}
	private static void showSent(Scanner in,EmailApp app) {
		
		Iterator<Message> it=app.getSentMessages();
		System.out.println(Constants.MSG_LIST_HEADER.getMsg());
		while(it.hasNext()) {
			Message r=it.next();
			
			System.out.printf(Constants.PRINT_MSG.getMsg(),r.getDate(),r.getSubject(),r.getEmail());
		}
		System.out.println();
		
	}
	private static void showReceived(Scanner in,EmailApp app) {
		
		Iterator<Message> it=app.getReceivedMessages();
		System.out.println(Constants.MSG_LIST_HEADER.getMsg());
		while(it.hasNext()) {
			Message r=it.next();
			
			System.out.printf(Constants.PRINT_MSG.getMsg(),r.getDate(),r.getSubject(),r.getEmail());
		}
		System.out.println();
		
	}

}
