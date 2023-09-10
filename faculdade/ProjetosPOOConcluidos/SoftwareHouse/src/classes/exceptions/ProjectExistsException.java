package classes.exceptions;

import java.util.Formatter;

import projectClasses.interfaces.Project;

@SuppressWarnings("serial")
public class ProjectExistsException extends Exception {

	private static final String NOTIFICATION="%s project already exists.";
	@SuppressWarnings("resource")
	public ProjectExistsException (Project e) {
		super(new Formatter().format(NOTIFICATION, e.getName()).toString());
	}
}
