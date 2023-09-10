package classes;

import java.util.*;

import smallerClasses.*;

public class EmailAppClass implements EmailApp {
	
	private List<Message> sent,received,all;
	
	
	
	public EmailAppClass() {
		
		sent=new ArrayList<>();
		received =new ArrayList<>();
		all=new ArrayList<>();
		
		
		
	}

	@Override
	public Iterator<Message> getSentMessages() {
		
		
		Collections.sort(sent,new MessageComparator());
		return sent.iterator();
	}

	@Override
	public Iterator<Message> getReceivedMessages() {
		Collections.sort(received,new MessageComparator());
		return received.iterator();
	}

	@Override
	public void send(String subject,String destination, String contents,String date ) throws DuplicateMessageException {
		Message msg=new MessageClass(subject,destination,contents,date);
		if(sent.contains(msg)) {
			 throw new DuplicateMessageException();
		}
		else {
		sent.add(msg);
		all.add(msg);
		}
		
	}

	@Override
	public void receive(String subject,String sender, String contents,String date) throws DuplicateMessageException{
		Message msg= new MessageClass(subject,sender,contents,date);
		if(received.contains(msg)) {
			 throw new DuplicateMessageException();
		}
		else {
		received.add(msg);
		all.add(msg);
		}
		
	}

	@Override
	public Iterator<Message> getMessagesByEmail(String email) throws listByEmailEmptyException{
		
		List<Message> list=new ArrayList<>();
		Iterator<Message> it=all.iterator();
		while(it.hasNext()) {
			Message r=it.next();
			if(r.getEmail().equals(email)) {
				list.add(r);
			}
			
		}
		if(list.size()==0) {
			throw new listByEmailEmptyException();
		}
		return list.iterator();
	}

	@Override
	public Iterator<Message> getMessagesBySubject(String subject)throws listBySubjectEmptyException {
		
		List<Message> list=new ArrayList<>();
		Iterator<Message> it=all.iterator();
		while(it.hasNext()) {
			Message r=it.next();
			if(r.getSubject().equals(subject)) {
				list.add(r);
			}
			
		}
		if(list.size()==0) {
			throw new listBySubjectEmptyException();
		}
		return list.iterator();
	}

	@Override
	public Iterator<String> getMessageSubjects() {
		List<String> subjects=new ArrayList<>();
		Iterator<Message> it=all.iterator();
		while(it.hasNext()) {
			Message r=it.next();
			if(!subjects.contains(r.getSubject())) {
			subjects.add(r.getSubject());
			}
		}
		Collections.sort(subjects,new StringComparator());
		return subjects.iterator();
	}


}
