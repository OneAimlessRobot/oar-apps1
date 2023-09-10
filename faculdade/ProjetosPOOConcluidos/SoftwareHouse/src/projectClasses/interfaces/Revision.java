package projectClasses.interfaces;

public interface Revision {

	/**
	 * @return the description
	 */
	String getDescription();

	/**
	 * @return the date
	 */
//	LocalDate getDate();
	String getDate();

	/**
	 * @return the authorName
	 */
	String getAuthorName();

	/**
	 * @return the revisionNumber
	 */
	int getRevisionNumber();

}