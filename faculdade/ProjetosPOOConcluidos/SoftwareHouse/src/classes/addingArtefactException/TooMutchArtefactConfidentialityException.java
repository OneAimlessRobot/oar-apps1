package classes.addingArtefactException;


@SuppressWarnings("serial")
public class TooMutchArtefactConfidentialityException extends Exception {


	private static final String NOTIFICATION="%s: exceeds project confidentiality level.";
	@SuppressWarnings("resource")
	public TooMutchArtefactConfidentialityException() {
		super(NOTIFICATION);
	}

}
