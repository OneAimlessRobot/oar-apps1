package enums;

public enum Constants {
	
	DATE_FORMAT("yyyy-MM-dd"),
	MSG_LIST_HEADER("data | assunto | email"),
	MSG_LIST_HEADER_EXT("data | assunto | email | texto"),
	PRINT_MSG_EXT("%s | %s | %s | %s\n"),
	PRINT_MSG("%s | %s | %s\n");
	
	private String contents;
	
	private Constants(String e) {
		contents=e;
	}
	
	public String getMsg() {
		return this.contents;
	}

}
