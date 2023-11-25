package dsFaculdad;

public enum FilePaths {

	QUEUEFILE("ola.res"),
	TREEFILE("tree.res"),
	GRAPHFILE("graph.res"),
	MAPFILE("graph.grph"),
	EXPLOREDFILE("graphexp.grph"),
	QUEUEFILETWO("bomDia.res");

	private String resourcesPath=System.getProperty("user.dir")+"/resources/";
	
	private String value; 

	FilePaths(String filename) {
		
		value=resourcesPath+filename;
		
	}
	
	public String getValue() {
		
		
		return value;
		
		
	}
	

}
