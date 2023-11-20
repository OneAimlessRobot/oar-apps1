package customClasses.interfaces;


public interface MapExplorer {

	int explore(String mode);

	String printIslands();

	int getNumOfIslands();

	String showShortestPaths();

	String showPaths();
	String printExits();

	int countExits();

	int countValidPaths();

	void showIslands();

	void showMap();

}