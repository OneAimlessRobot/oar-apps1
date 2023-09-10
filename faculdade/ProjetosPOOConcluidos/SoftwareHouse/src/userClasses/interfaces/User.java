package userClasses.interfaces;

import usefulEnums.Job;

public interface User{
///**
// * Returns true or false for whether the instance that called this method is equal to the one given as a paramenter or not
// * @param o
// * @return True, if equal. False if not
// */
//	boolean equals(User o);
/**
	 * Returns the name of this instance of User
	 * @return the name given to the instance in the constructor
	 */
	String getName();
	/**
	 * Returns whether this user is a manager or not
	 * @return True if it is a manager. False otherwise.
	 */
	boolean isManager();
	/**
	 * Returns the job position of this User
	 * @return
	 */

	Job getPos();
	/**
	 * Returns the clearance level of this User
	 * @return
	 */

	int getClearance();

}
