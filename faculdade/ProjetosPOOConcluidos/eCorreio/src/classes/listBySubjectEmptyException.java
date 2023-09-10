package classes;

@SuppressWarnings("serial")
public class listBySubjectEmptyException extends Exception {

private static final String msg="Nao existem mensagens trocadas com esse assunto.\n";
	public listBySubjectEmptyException() {
		super(msg);
	}
	
	public String getMsg() {
		return msg;
	}
}
