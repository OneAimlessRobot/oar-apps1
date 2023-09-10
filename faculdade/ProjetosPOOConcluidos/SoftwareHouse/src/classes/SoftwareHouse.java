package classes;

import java.time.LocalDate;
import java.util.Iterator;

import classes.exceptions.ProjectExistsException;
import classes.exceptions.ThatIsNotAManagerException;
import classes.exceptions.TooMutchConfidentialityException;
import classes.exceptions.projectAlreadyManagedException;
import classes.userExceptions.NonExistantPosException;
import classes.userExceptions.UserExistsException;
import projectClasses.interfaces.Artefact;
import projectClasses.interfaces.Project;
import projectClasses.interfaces.Revision;
import classes.addingArtefactException.ArtefactDoesNotExistException;
import classes.addingArtefactException.ArtefactExistsException;
import classes.addingArtefactException.NoSuchMemberException;
import classes.addingArtefactException.ProjectIsOutsourcedException;
import classes.addingArtefactException.TooMutchArtefactConfidentialityException;
import classes.addingDevExceptions.DevAlreadyInProjectException;
import classes.addingDevExceptions.NonOfUrBusinessException;
import classes.exceptions.NoSuchManagerException;
import classes.exceptions.NoSuchProjectException;
import classes.exceptions.NoSuchUserException;
import userClasses.interfaces.Developer;
import userClasses.interfaces.User;

public interface SoftwareHouse {
	/**
	 * 
	 * @return an iterator with all users registered in this instance of SoftwareHouse
	 */
	Iterator<User> getUserIterator();
	/**
	 * 
	 * @return true if there are no users registered. False otherwise
	 */
	boolean noUsers();
	/**
	 * adds an InHouse Project to this SoftwareHouse object
	 * @param name the name of the project
	 * @param confidentiality the confidentiality level of it
	 * @param managerName the name of its manager
	 * 
	 * pre: managerName!=null && name!=null && userExists(name)
	 */
	public void addInhouseProject(String projectName, int confidentiality, String managerName,Iterator<String> keywords)throws  NoSuchManagerException, ProjectExistsException,TooMutchConfidentialityException ;

	/**
	 * adds an Outsourced Project to this instance of SoftwareHouse
	 * @param name the name of the project
	 * @param companyName the name of the company to which it is outsourced
	 * @param managerName the name of its manager
	 * 
	 * pre: managerName!=null && name!=null && userExists(name)
	 */
	void addOutsourcedProject(String projectName,String companyName,String managerName,Iterator<String> keywords) throws NoSuchManagerException,ProjectExistsException;
	/**
	 * @return true if the project list is empty. False otherwise
	 */
	boolean noProjects();
	/**
	 * Counts the number of developers of this manager
	 * @param managerName
	 * <pre> managerName != null </pre>
	 * @return
	 */
	int countManagerDevelopers(String managerName);
	/**
	 * Returns an iterator of all projects sorted by insertion order
	 * @return
	 */
	Iterator<Project> projects();
	/**
	 * counts the number of project this manager manages
	 * @param name
	 * @return
	 * pre: name != null
	 */
	int countManagerProjects(String name);
	/**
	 * Adds a new user to a project
	 * @param projName Name of the project
	 * @param devName Name of the developer (in case the user to be added is a Developer, the next Parameter does not matter)
	 * @param managerName Name of the manager 
	 * @throws NoSuchUserException
	 * @throws projectAlreadyManagedException
	 * @throws NonOfUrBusinessException
	 * @throws NoSuchManagerException
	 * @throws DevAlreadyInProjectException
	 * @throws NoSuchProjectException
	 * pre: projName !=null && devName!=null && managerName !=null
	 */
	void addUserToProject(String projName,String devName,String managerName)throws NoSuchUserException,projectAlreadyManagedException,NonOfUrBusinessException,NoSuchManagerException,DevAlreadyInProjectException,NoSuchProjectException;int countProjectMembers(String projectName);
	/**
	 * Counts the ammount of projects the developer is involved in
	 * @param devName
	 * @return
	 * pre: devName != null
	 */
	int countDevAppearancesInProjects(String devName);
	/**
	 * Adds a new Manager to this project
	 * @param name name of the manager to be added
	 * @param clearance level of clearance this manager has
	 * @throws UserExistsException
	 * pre: name!= null
	 */
	 void addManager(String name, int clearance)throws UserExistsException;
	 /**
	  * Adds a new developer. 
	  * @param name Name of the developer
	  * @param managerName Name of the manager responsible for this developer
	  * @param clearance level of clearance of this developer
	  * 
	  * @throws UserExistsException
	  * @throws NoSuchManagerException
	  * @throws ThatIsNotAManagerException
	  * pre: name!=null && managerName !=null
	  */
	 void addDeveloper(String name, String managerName, int clearance)
				throws UserExistsException, NoSuchManagerException, ThatIsNotAManagerException;
	 /**
	  * Adds a new revision to a project's artefact.
	  * @param date Date the revision was made
	  * @param authorName Name of the author of the revision
	  * @param artefactName Name of the artefact to be updated
	  * @param description Description of the update
	  * @param projectName Name of the project to be modified
	  * @throws NoSuchUserException
	  * @throws NoSuchProjectException
	  * @throws ArtefactDoesNotExistException
	  * @throws NoSuchMemberException
	  * 
	  * pre: date != null && authorName != null && artefactName !=null && description !=null && projectName !=null
	  */
	 void addRevisionToArtefact(String date, String authorName,String artefactName,String description,String projectName) throws NoSuchUserException, NoSuchProjectException,ArtefactDoesNotExistException,  NoSuchMemberException;
	 /**
	  * Adds an artefact to a project.
	  * @param date Date of creation of the artefact.
	  * @param confidentiality level of clearance a project's team member has to have to edit the artefact
	  * @param authorName Name of the artefact's author
	  * @param artefactName Name of the artefact to be added
	  * @param description Description of the artefact
	  * @param projectName Name of the project
	  * @throws NoSuchProjectException
	  * @throws NoSuchMemberException
	  * @throws NoSuchUserException
	  * @throws ArtefactExistsException
	  * @throws TooMutchArtefactConfidentialityException
	  * @throws ProjectIsOutsourcedException
	  * 
	  * pre: date!=null && authorName != null && artefactName != null && description != null && projectName != null
	  */
	 void addArtefactToProject(String date, int confidentiality, String authorName,String artefactName,String description,String projectName) throws NoSuchProjectException, NoSuchMemberException, NoSuchUserException, ArtefactExistsException, TooMutchArtefactConfidentialityException;
	 /**
	  * Gets the number of artefacts this projects has and returns it as an int
	  * @param projectName the name of the project
	  * @return
	  * pre: projectName != null && hasProject(projectName)
	  */
	 
	 int countProjectArtefacts(String projectName);
	 /**
	  * Gets the clearance level of this project
	  * @param projectName The name of the project
	  * @return
	  * 
	  * pre: projectName != null && hasProject(projectName)
	  */
	 int getProjectConfidentialityLevel(String projectName);
	 /**
	  * Gets the name of the project 
	  * @param projectName The name of the project
	  * @param managerName The name of the manager
	  * @return
	  * pre: projectName != null && hasProject(projectName) && managerName != null && userExists(managerName)
	  */
	 String getProjectManager(String projectName, String managerName);
	 /**
	  * Returns the user instance with the name "name"
	  * @param name name of the user
	  * @return
	  * pre: userExists(name) && name != null
	  */
	 User userByName(String name);
	 /**
	  * Returns an iterator of every single one of a project's Artefacts
	  * @param projectName The name of the project
	  * @return
	  * pre: projectName !=null && hasProject(projectName)
	  */
	 Iterator<Artefact> getProjectArtefactIterator(String projectName);
	 /**
	  * Iterator of a project's team members
	  * @param projectName Name of the project
	  * @return
	  * pre: projectName !=null && hasProject(projectName)
	  */
	 Iterator<User> projectTeamMemberIterator(String projectName);
	 /**
	  * Returns an iterator of the revisions of a particular Project's artefact
	  * @param projectName the name of the project to search on
	  * @param name Name of the Artefact to search for
	  * @return
	  * pre: projectName != null && hasProject(projectName) && name != null
	  */
	Iterator<Revision> getProjectArtefactRevisionsIterator(String projectName, String name);
	/**
	 * Returns true if there is a project with name "projectName".
	 * False otherwise
	 * @param projectName
	 * @return
	 */
	boolean hasProject(String projectName);
	/**
	 * Returns true or false whether or not the project named projectName is an Outsourced project
	 * @param projectName Name of the project to search for
	 * @return
	 * pre: hasProject(projectName) && projectName !=null
	 */
	boolean projectIsOutsourced(String projectName);
	/**
	 * Returns the artefact instance at project with name "projectName" and with name "artefactName"
	 * @param projectName Name of the project to look for
	 * @param artefactName Name of the artefact to look for
	 * @return
	 * pre: projectName !=null && hasProject(projectName) && artefactName != null
	 */
	Artefact getProjectArtefactByName(String projectName, String artefactName);
	/**
	 * Counts the number of revisions of a certain project. (Not counting the initial ones of when artefacts
	 * are added for the first time
	 * )
	 * @param projectName Name of the project to look for
	 * @return
	 * pre: hasProject(projectName) && projectName != null
	 */
	int countProjectRevisions(String projectName);
	/**
	 * Counts in many times a manager named "managerName" appears as a member 
	 * @param managerName Name of the manager to look for
	 * @return
	 * userByName(managerName).isManager() && userExists(managerName) && managerName != null
	 */
	int countManagerProjectAppearancesAsDev(String managerName);
}