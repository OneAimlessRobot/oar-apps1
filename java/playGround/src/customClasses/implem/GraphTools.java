package customClasses.implem;

import java.io.Serializable;

import ds.interfaces.Graph;

public class GraphTools implements Serializable {

	private static final long serialVersionUID = 1L;


public static int sumDegreesGraph(Graph<?> graph) {
	 return graph.sumDegrees();
	 
}
public static boolean hasCyclesGraph(Graph<?> graph) {
	 
	return graph.hasCycles();
	 
}


public static  Graph<?> getGraphClone(Graph<?> graph) {
	 
	 
	 return graph.getGraphClone();
	 
	 
}
}