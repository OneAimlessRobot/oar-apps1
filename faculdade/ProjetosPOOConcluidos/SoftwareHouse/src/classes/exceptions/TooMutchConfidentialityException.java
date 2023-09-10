package classes.exceptions;

import java.util.Formatter;

import userClasses.interfaces.*;

@SuppressWarnings("serial")
public class TooMutchConfidentialityException extends Exception {

	private static final String NOTIFICATION="Project manager %s has clearance level %d.\n";
	@SuppressWarnings("resource")
	public TooMutchConfidentialityException(Manager man) {
		super(new Formatter().format(NOTIFICATION, man.getName(),man.getClearance()).toString());
	}

}
