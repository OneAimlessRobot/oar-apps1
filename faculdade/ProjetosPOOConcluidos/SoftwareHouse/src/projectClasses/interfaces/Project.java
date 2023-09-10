package projectClasses.interfaces;

public interface Project {

/**
 * returns the name of this project
 * @return
 */
	String getName();

	/**
	 * Equals method of this class
	 * @param obj
	 * @return
	 */
	boolean equals(Object obj);
	/**
	 * Returns the name of the manager of this project
	 * @return
	 */
	String getManagerName();
	/**
	 * Returns the number of this project
	 * @return
	 */
	
	int getNumber();

}