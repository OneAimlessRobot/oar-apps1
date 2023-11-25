package dsFaculdad;

public enum FilePaths2 {

	GENTREEFILE("gentree.res");

	private String resourcesPath=System.getProperty("user.dir")+"/resources/";
	
	private String value; 

	FilePaths2(String filename) {
		
		value=resourcesPath+filename;
		
	}
	
	public String getValue() {
		
		
		return value;
		
		
	}
	

}
