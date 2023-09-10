package smallerClasses;

import java.util.Objects;

public class MessageClass implements Message {

	private String email,subject,contents,date;
	
	public MessageClass(String subject,String email, String contents,String date ) {
		this.date=date;
		this.subject=subject;
		this.email=email;
		this.contents=contents;
	}
	@Override
	public String getContents() {
		return contents;
	}

	@Override
	public String getEmail() {
		return email;
	}
	
	public String getDate() {
		return date;
	}
	public String getSubject() {
		return subject;
	}
	@Override
	public int hashCode() {
		return Objects.hash(contents, date, email, subject);
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof MessageClass)) {
			return false;
		}
		MessageClass other = (MessageClass) obj;
		return Objects.equals(date, other.date)
				&& Objects.equals(email, other.email) && Objects.equals(subject, other.subject);
	}
	

}

