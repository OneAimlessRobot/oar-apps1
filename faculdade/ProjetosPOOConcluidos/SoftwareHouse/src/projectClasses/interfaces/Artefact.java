package projectClasses.interfaces;

import java.util.Iterator;

import userClasses.interfaces.User;

public interface Artefact {


//	LocalDate getDate();
	String getDate();

	/**
	 * @return the confLevel
	 */
	int getConfLevel();

	/**
	 * @return the name
	 */
	String getName();

	/**
	 * @return the desc
	 */
	String getDesc();
	/**
	 * Returns the User instance that made this artefact
	 * @return
	 */
	User getAuthor();
/**
 * Adds a revision to this Artefact
 * @param date
 * @param description
 * @param author
 * pre: date != null && description != null && author != null
 */
	void addRevision(String date,String description,User author);
	/**
	 * equals method for this Class
	 * @param obj Object to compare this Artefact to
	 * @return
	 * pre: obj != null
	 */
	
	boolean equals(Object obj);
	/**
	 * Produces and returns an iterator of all the revisions in this Artefact instance
	 * @return
	 */
	Iterator<Revision> revisions();
	/**
	 * Returns the date of the latest Revision of this Artefact
	 * @return
	 */
	String getLastdate();
	/**
	 * Produces and returns an iterator of all the revisions in this Artefact instance
	 * 
	 * @return
	 */
	
	Iterator<Revision> sortedRevisions();
	/**
	 * Keeps track of the next number to give the next revision to be added
	 * @return
	 */
	
	int getCurrentRevisionNum();
	/**
	 * Counts the number of revisions this Artefact has
	 * @return
	 */
	
	int getRevisionCount();


}