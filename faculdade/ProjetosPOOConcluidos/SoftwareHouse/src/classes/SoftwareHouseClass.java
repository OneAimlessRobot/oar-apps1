package classes;

import java.util.*;


import classes.addingDevExceptions.*;
import classes.addingArtefactException.*;
import classes.exceptions.*;
import classes.userExceptions.*;
import projectClasses.entities.*;
import projectClasses.interfaces.*;
import userClasses.interfaces.*;
import userClasses.entities.*;


public class SoftwareHouseClass implements SoftwareHouse {

	List<User> users;
	List<Project> projects;

	Map<Manager, List<Project>> managerToProjectList;
	Map<Manager, List<Developer>> managerToDeveloperList;
	Map<Project, List<User>> projectToDevTeam;
//
//	Map<Project, Map<User, List<Artefact>>> projectToDeveloperToArtefactList;
//Mapas tipicamente usados com chaves do tipo string e valores com os objetos que queremos obter. (em vez de listas.)
//Listas dentro de classes sao ok. O que estou a fazer e pouco eficiente.
	Map<Project, List<String>> projectToKeywordList;
	
	Map<Project,List<Artefact>> projectToArtefactList;
	private int currentProject;

//This constructor initializes all collections in this SoftwareHouseApp
	public SoftwareHouseClass() {

		users = new ArrayList<>();
		projects = new ArrayList<>();

		projectToDevTeam = new HashMap<>();
		managerToProjectList = new HashMap<>();
		managerToDeveloperList = new HashMap<>();
		projectToKeywordList = new HashMap<>();
		
		projectToArtefactList= new HashMap<>();
		currentProject=0;
		
	}

	public void addArtefactToProject(String date, int confidentiality, String authorName, String artefactName,
			String description, String projectName) throws NoSuchProjectException, NoSuchMemberException,
			NoSuchUserException, ArtefactExistsException, TooMutchArtefactConfidentialityException {
		
		
		artefactAddingMainChecks(confidentiality, authorName, projectName, artefactName);
		Artefact newArtefact = new ArtefactClass(date, artefactName, confidentiality, description,
				userByName(authorName));
		newArtefact.addRevision(date,description,userByName(authorName));
		projectToArtefactList.putIfAbsent(projectByName(projectName),new ArrayList<>());
		List<Artefact> value=projectToArtefactList.get(projectByName(projectName));


		value.add(newArtefact);
	}

	public void addDeveloper(String name, String managerName, int clearance)
			throws UserExistsException, NoSuchManagerException {

		if (userExists(name)) {
			throw new UserExistsException();
		}
		if (!userExists(managerName)||userByName(managerName) instanceof Developer) {
			throw new NoSuchManagerException();
		}

		User s = new DeveloperClass(name, clearance, managerName);
		Manager mgr =(Manager) userByName(managerName);
		users.add(s);
		managerToDeveloperList.get(mgr).add((Developer) s);

	}
	
	public void addInhouseProject(String projectName, int confidentiality, String managerName,
			Iterator<String> keywords)
			throws NoSuchManagerException, ProjectExistsException, TooMutchConfidentialityException {

		projectAddingMainChecks(projectName, managerName);

		if (confidentiality > userByName(managerName).getClearance()) {
			throw new TooMutchConfidentialityException((Manager)userByName(managerName));
		}

		User s = userByName(managerName);
		Project proj = new InhouseProjectClass(projectName, confidentiality, managerName,currentProject++);

		projects.add(proj);

		projectToDevTeam.putIfAbsent(proj, new ArrayList<>());
		managerToProjectList.get(s).add(proj);
		projectToArtefactList.putIfAbsent(proj,new ArrayList<>());


		addKeywordsToProject(proj, keywords);
	}

	public void addManager(String name, int clearance) throws UserExistsException {
		User s = null;
		if (userExists(name)) {
			throw new UserExistsException();
		} else {
			s = new ManagerClass(name, clearance);
			users.add((Manager) s);

			managerToProjectList.putIfAbsent((Manager) s, new ArrayList<>());
			managerToDeveloperList.putIfAbsent((Manager) s, new ArrayList<>());
		}

	}
	//And this also works normally with indexOf method
	public User userByName(String name) {
		User r = users.get(users.indexOf(new ManagerClass(name, 0)));
		return r;
	}

	public void addOutsourcedProject(String projectName, String companyName, String managerName,
			Iterator<String> keywords) throws NoSuchManagerException, ProjectExistsException {

		projectAddingMainChecks(projectName, managerName);

		Manager s = (Manager) userByName(managerName);
		Project proj = new OutsourcedProjectClass(projectName, companyName, managerName,currentProject++);

		projects.add(proj);
		managerToProjectList.get(s).add(proj);
		projectToArtefactList.putIfAbsent(proj,new ArrayList<>());

		addKeywordsToProject(proj, keywords);

	}

	public void addRevisionToArtefact(String date, String authorName, String artefactName, String description,
			String projectName) throws NoSuchUserException, NoSuchProjectException, ArtefactDoesNotExistException, NoSuchMemberException {
		revisionAddingChecks(authorName, artefactName, description,projectName);
		getProjectArtefactByName(projectName,artefactName).
		addRevision(date, description, userByName(authorName));
	}

	public void addUserToProject(String projName, String devName, String managerName)
			throws NoSuchUserException, projectAlreadyManagedException, NonOfUrBusinessException,
			NoSuchManagerException, DevAlreadyInProjectException, NoSuchProjectException {

		teamMemberChecks(projName, devName, managerName);

		if (userByName(devName) instanceof Developer) {
			if (userWorksForProject(devName, projName)) {

				throw new DevAlreadyInProjectException();

			}

			projectToDevTeam.get(projectByName(projName)).add(userByName(devName));
			
		} else {

			if (userIsManagingProject(devName, projName)) {

				throw new DevAlreadyInProjectException();

			}

			projectToDevTeam.get(projectByName(projName)).add(userByName(devName));

		}
	}
	public boolean artefactNotExist(String projectName, String artefactName) {
		
		List<Artefact> list = projectToArtefactList.get(projectByName(projectName));
		
		Artefact comparand = new ArtefactClass(null, artefactName, 0, null, null);

		return !list.contains(comparand);

	}
	public int countDevAppearancesInProjects(String devName) {
		Iterator<Map.Entry<Project, List<User>>> it = projectToDevTeam.entrySet().iterator();
		int ammount = 0;
		while (it.hasNext()) {
			Map.Entry<Project, List<User>> entry = it.next();
			List<User> list = entry.getValue();
			if (list.contains(userByName(devName))) {
				ammount++;
			}

		}
		return ammount;
	}
	
	public int countManagerDevelopers(String managerName) {
		Manager mgr = (Manager) userByName(managerName);
		List<Developer> list = managerToDeveloperList.get(mgr);

		return list.size();
	}

	public int countManagerProjectAppearancesAsDev(String managerName) {
		Iterator<Map.Entry<Project, List<User>>> it = projectToDevTeam.entrySet().iterator();
		int ammount = 0;
		while (it.hasNext()) {
			Map.Entry<Project, List<User>> entry = it.next();
			Project p=entry.getKey();
			if (userWorksForProject( managerName, p.getName()) ) {
				ammount++;
			}

		}
		return ammount;
	}

	public int countManagerProjects(String managerName) {
		Manager mgr =(Manager) userByName(managerName);
		List<Project> list = managerToProjectList.get(mgr);

		return list.size();
	}

	public int countProjectArtefacts(String projectName) {

		

		List<Artefact> list = projectToArtefactList.get(projectByName(projectName));
		
		return list.size();

	}

	public int countProjectMembers(String projectName) {
		List<User> list = projectToDevTeam.get(projectByName(projectName));
		return list.size();

	}
// QUICKFIX: USE THE AUTOMATIC IMPLEMENTATION OF EQUALS FROM ECLIPSE
public int countProjectRevisions(String projectName) {
	
	List<Artefact> list=projectToArtefactList.get(projectByName(projectName));
	Iterator<Artefact> it =list.iterator();
	int ammount=0;
	while(it.hasNext()) {
		Artefact r=it.next();
		ammount+=((r.getCurrentRevisionNum()));
		
	}
	return ammount-this.countProjectArtefacts(projectName);
	
}
	public Artefact getProjectArtefactByName(String projectName, String artefactName) {
		List<Artefact> list=projectToArtefactList.get((projectByName(projectName)));
		Artefact comparand = new ArtefactClass(null, artefactName, 0, null, null);
		return list.get(list.indexOf(comparand));
	}


	public Iterator<Artefact> getProjectArtefactIterator(String projectName){
		
		Iterator<Artefact> it=projectToArtefactList.get(projectByName(projectName)).iterator();
		List<Artefact>  aux=new ArrayList<>();
		while(it.hasNext()) {
			Artefact r=it.next();
			aux.add(r);
		}
		Collections.sort(aux,new ArtefactComparator());
		return aux.iterator();
		
	}

	public Iterator<Revision> getProjectArtefactRevisionsIterator(String projectName,String artefactName){
		
		return getProjectArtefactByName(projectName,artefactName).sortedRevisions();
		
		
		
	}


	public int getProjectConfidentialityLevel(String projectName) {
		
		return ((InhouseProject)projectByName(projectName)).getConfidentialityLevel();
		
	}

	public String getProjectManager(String projectName, String managerName) {

		Iterator<Map.Entry<Manager, List<Project>>> it = managerToProjectList.entrySet().iterator();
		String name = managerName;
		while (it.hasNext()) {
			Map.Entry<Manager, List<Project>> currentEntry = it.next();
			List<Project> list = currentEntry.getValue();
			if (list.contains(projectByName(projectName))) {
				name = currentEntry.getKey().getName();
			}
		}
		return name;

	}

	@Override
	public Iterator<User> getUserIterator() {
		Collections.sort(users, new UserComparator());
		return users.iterator();
	}
	//I've tried using the contains method, but it just does not work. I had to to this to make the output of my program match the examples
	public boolean hasProject(String projectName) {

		Iterator<Project> it=projects.iterator();
		while(it.hasNext()) {
			Project r=it.next();
			if(r.getName().equals(projectName)) {
				return true;
			}
		}
		return false;
	}
	public boolean noProjects() {
		return projectToDevTeam.isEmpty();
	}

	public boolean noUsers() {
		return users.isEmpty();
	}

	public boolean projectIsOutsourced(String projectName) {

		return projectByName(projectName) instanceof OutsourcedProject;
	}
	
public Iterator<Project> projects() {
		return projects.iterator();
	}
	public Iterator<User> projectTeamMemberIterator(String projectName) {

		Iterator<User> it = projectToDevTeam.get(projectByName(projectName)).iterator();
		return it;

	}
	
	// Threw this into a private method to make the method that adds revisions shorter
private void revisionAddingChecks(String authorName, String artefactName, String description,
			String projectName) throws NoSuchUserException, NoSuchProjectException, NoSuchMemberException, ArtefactDoesNotExistException{
		if (!userExists(authorName)) {
			throw new NoSuchUserException();
		}
		if (!hasProject(projectName)||projectIsOutsourced(projectName)) {

			throw new NoSuchProjectException();
		}
		if (artefactNotExist(projectName, artefactName)) {
			throw new ArtefactDoesNotExistException();
		}
		if (!userWorksForProject(authorName, projectName)&&!authorName.equals(getProjectManager(projectName, authorName))) {
			throw new NoSuchMemberException();
		}
		
	}

//Threw this into a private method to make the method that adds team members shorter
	private void teamMemberChecks(String projName, String devName, String managerName) throws NoSuchUserException,
			NoSuchManagerException, NoSuchProjectException, projectAlreadyManagedException, NonOfUrBusinessException {

		if (!userExists(devName)) {
			throw new NoSuchUserException();
		}
		if (!userExists(managerName)||userByName(managerName) instanceof Developer) {
			throw new NoSuchManagerException();
		}
		if (!hasProject(projName)||projectByName(projName) instanceof OutsourcedProject) {

			throw new NoSuchProjectException();
		}
		if (!managerName.equals(getProjectManager(projName, managerName))) {

			throw new projectAlreadyManagedException(projName, getProjectManager(projName, managerName));

		}
		if (userByName(devName).getClearance() < ((InhouseProject) projectByName(projName)).getConfidentialityLevel()) {
			throw new NonOfUrBusinessException();
		}
	}
	// Threw this into a private method to make the method that adds projects shorter
private void projectAddingMainChecks(String projectName, String managerName)
			throws NoSuchManagerException, ProjectExistsException {

		if (!userExists(managerName) || !((userByName(managerName) instanceof Manager))) {
			throw new NoSuchManagerException();
		}

		if (hasProject(projectName)) {
			throw new ProjectExistsException(projectByName(projectName));
		}
	}
	//Had to avoid using anything that uses equals to get this to work (That includes the contains method)
/**
 * Returns a project with a certain name in this instance's project collection	
 * @param name name to look for
 * @return
 * pre: projectName != null
 */
private Project projectByName(String projectName) {
		Iterator<Project> it=projects.iterator();
		Project s= null;
		while(it.hasNext()) {
			Project r=it.next();
			if(r.getName().equals(projectName)) {
				s=r;
			}
		}
		return s;
	}
		
	// Threw this into a private method to make the method that adds artefacts shorter
	/**
	 * Checks for diferent unexpected situations in the method that adds artefacts to projects
	 * @param confidentiality The confidentiality of the artefact to add
	 * @param authorName The artefact's author
	 * @param projectName The name of the project to look for
	 * @param artefactName The name of the artefact
	 * @throws NoSuchProjectException
	 * @throws NoSuchMemberException
	 * @throws NoSuchUserException
	 * @throws ArtefactExistsException
	 * @throws TooMutchArtefactConfidentialityException
	 * @throws ProjectIsOutsourcedException
	 * pre: projectName != null && authorName!= null
	 */
	private void artefactAddingMainChecks(int confidentiality, String authorName, String projectName,
			String artefactName) throws NoSuchProjectException, NoSuchMemberException, NoSuchUserException,
			ArtefactExistsException, TooMutchArtefactConfidentialityException{
		if (!userExists(authorName)) {
			throw new NoSuchUserException();
		}
		if (!hasProject(projectName)||projectByName(projectName) instanceof OutsourcedProject ) {
			throw new NoSuchProjectException();
		}
		if (!userWorksForProject(authorName, projectName)&&!authorName.equals(getProjectManager(projectName, authorName))) {
			throw new NoSuchMemberException();
		}

		if (!artefactNotExist(projectName, artefactName)) {
			throw new ArtefactExistsException();
		}

		if (confidentiality > ((InhouseProject) projectByName(projectName)).getConfidentialityLevel()) {
			throw new TooMutchArtefactConfidentialityException();
		}
	}
//Method that adds keywords to a project
	/**
	 * Adds a bunch of keywords to a project contained in a String iterator
	 * @param proj The project to add the keywords to
	 * @param it The iterator that contains the keywords
	 * pre: proj != null && it != null && projects.contains(proj)
	 */
	private void addKeywordsToProject(Project proj, Iterator<String> it) {

		projectToKeywordList.putIfAbsent(proj, new ArrayList<>());
		while (it.hasNext()) {
			String i = it.next();
			projectToKeywordList.get(proj).add(i);

		}
	}

	//But this works, for some reason. This is the private method that keeps getting mentioned in the interface
	private boolean userExists(String name) {
		User r = new ManagerClass(name, 0);
		return users.contains(r);
	}
//Auxiliary method for the checks auxilary methods
	/**
	 * Method that checks if a user is the manager of a project 
	 * @param managerName Name of the manager to look for
	 * @param projectName Name of the project to look for
	 * @return
	 * pre: managerName != null && projectName != null
	 */
	private boolean userIsManagingProject(String managerName, String projectName) {

		return managerToProjectList.get(userByName(managerName)).contains(projectByName(projectName));
	}
	//Auxiliary method that checks if a dev named devName is a team member of a project name projectName
	private boolean userWorksForProject(String devName, String projectName) {

		return projectToDevTeam.get(projectByName(projectName)).contains(userByName(devName));

	}

}


//Just in case I need this code

//private boolean mgrExists(String managerName) {
//	return users.indexOf(new ManagerClass(managerName, 0)) >= 0;
//}

//private Developer devByName(String name) {
//	Developer r = (Developer) users.get(users.indexOf(new DeveloperClass(name, 0, null)));
//	return r;
//}
//
//private Manager mgrByName(String name) {
//	Manager r = (Manager) users.get(users.indexOf(new ManagerClass(name, 0)));
//	return r;
//}
//
//public Artefact getProjectArtefactByNameAndAuthor(String projectName, String authorName, String artefactName) {
//
//	List<Artefact> list = projectToDeveloperToArtefactList.get(projectByName(projectName))
//			.get(userByName(authorName));
//	Artefact comparand = new ArtefactClass(null, artefactName, 0, null, null);
//	Artefact value = list.get(list.indexOf(comparand));
//	return value;
//}
//
