package smallerClasses;

import java.util.Comparator;

public class MessageComparator implements Comparator<Message> {

	public int compare(Message a,Message o) {
		if(a.getDate().compareTo(o.getDate())>0) {
			
			return 1;
			
		}
		else if(a.getDate().compareTo(o.getDate())<0) {
			return -1;
		}
		else {
			if(a.getSubject().compareTo(o.getSubject())>0) {
				return 1;
				
			}
			else if(a.getSubject().compareTo(o.getSubject())<0) {
				return -1;
				
			}
			else {
				if(a.getEmail().compareTo(o.getEmail())>0) {
					return 1;
					
				}
				else if(a.getEmail().compareTo(o.getEmail())<0) {
					return -1;
					
				}
				else {
					
					return 0;
					
				}
			}
		}
	}
	
}
