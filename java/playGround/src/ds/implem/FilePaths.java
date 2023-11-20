package ds.implem;

public enum FilePaths {

	QUEUEFILE("ola.res"),
	TREEFILE("tree.res"),
	GRAPHFILE("graph.res"),
	MAPFILE("graph.grph"),
	MAPFILE2("graph2.grph"),
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
