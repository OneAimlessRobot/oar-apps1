package classes;

@SuppressWarnings("serial")
public class listByEmailEmptyException extends Exception {

private static final String msg="Nao existem mensagens trocadas com esse email.\n";
	public listByEmailEmptyException() {
		super(msg);
	}
	public String getMsg() {
		return msg;
	}
}
