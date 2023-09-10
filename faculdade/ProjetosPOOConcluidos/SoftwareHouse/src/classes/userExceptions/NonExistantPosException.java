/**
 * 
 */
package classes.userExceptions;

/**
 * @author oneaimlessrobot
 *
 */
@SuppressWarnings("serial")
public class NonExistantPosException extends Exception {

	private static final String NOTIFICATION="Unknown job position.";
	public NonExistantPosException() {
		
		super(NOTIFICATION);
	}

}
