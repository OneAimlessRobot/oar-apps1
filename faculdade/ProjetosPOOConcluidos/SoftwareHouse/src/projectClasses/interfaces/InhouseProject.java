package projectClasses.interfaces;

public interface InhouseProject extends Project{
/**
 * Returns the necessary clearance a user must have to be added to this project
 * @return
 */
	int getConfidentialityLevel();

}