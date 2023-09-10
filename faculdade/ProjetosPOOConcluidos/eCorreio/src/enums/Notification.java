package enums;

public enum Notification {
	//Comando ENVIAR
	DUPLICATE_SEND("Mensagem duplicada.\n"),
	//Comando RECEBER
	//Comando ASSUNTO
	NO_ONE_CARES_ABOUT_SUBJECT("Nao existem mensagens trocadas com esse assunto.\n"),
	//Comando EMAIL
	EMAIL_HAS_NO_FRIENDS("Nao existem mensagens trocadas com esse email.\n");
	private final String message;
	private Notification(String e) {
		message=e;
		
	}
	/**
	 * @return the message
	 */
	public String getMessage() {
		return message;
	}

}
