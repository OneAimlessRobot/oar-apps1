package classes;
import smallerClasses.*;
import java.util.*;

public interface EmailApp {
	
	Iterator<Message> getSentMessages();
	
	Iterator<Message> getReceivedMessages();
	
	Iterator<Message> getMessagesByEmail(String email)throws listByEmailEmptyException;
	
	Iterator<Message> getMessagesBySubject(String subject) throws listBySubjectEmptyException ;
	
	Iterator<String> getMessageSubjects();
	
	void send(String subject,String destination, String contents,String date ) throws DuplicateMessageException;
	
	void receive(String subject,String sender, String contents,String date) throws DuplicateMessageException;
	

}
