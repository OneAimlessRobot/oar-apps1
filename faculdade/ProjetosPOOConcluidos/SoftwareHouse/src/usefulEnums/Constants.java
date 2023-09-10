package usefulEnums;

public enum Constants {
	

	DATE_FORMAT("yyyy-MM-dd"),
	PRINT_INHOUSE("in-house %s is managed by %s [%d, %d, %d, %d]\n"),
	PRINT_OUTSOURCED("outsourced %s is managed by %s and developed by %s\n"),
	TIME_FORMAT("HH'h'mm");
	
	private String desc;
	private Constants(String str) {
		desc=str;
		
	}
	
	public String getDesc() {
		return desc;
	}

}
