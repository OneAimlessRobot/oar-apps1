package projectClasses.entities;


import projectClasses.interfaces.Revision;
import userClasses.interfaces.User;

public class RevisionClass implements Revision{
//	private final LocalDate date;
	private final String description,date;
	private final User author;
	private final int revisionNumber;
	public RevisionClass(String date, String description,User author,int revisionNumber) {
		this.date=date;
		this.description=description;
		this.author=author;
		this.revisionNumber=revisionNumber;
	}
	/**
	 * @return the description
	 */
	@Override
	public String getDescription() {
		return description;
	}
	/**
	 * @return the date
	 */
//	@Override
//	public LocalDate getDate() {
//		return date;
//	}
	public String getDate() {
		return date;
	}
	/**
	 * @return the date
	 */
	@Override
	public String getAuthorName() {
		return author.getName();
	}
	/**
	 * @return the revisionNumber
	 */
	@Override
	public int getRevisionNumber() {
		return revisionNumber;
	}
	
	
	

}
