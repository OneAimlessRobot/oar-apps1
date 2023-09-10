package classes;

@SuppressWarnings("serial")
public class DuplicateMessageException extends Exception {
private static final String msg="Mensagem duplicada.\n";
	public DuplicateMessageException() {
		super(msg);
	}
}
