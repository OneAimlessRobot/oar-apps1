
import java.util.*;

import classes.*;
import classes.addingArtefactException.*;
import classes.addingDevExceptions.*;
import classes.exceptions.*;
import classes.userExceptions.NonExistantPosException;
import classes.userExceptions.UserExistsException;
import projectClasses.entities.*;
import projectClasses.interfaces.*;
import userClasses.interfaces.*;
import usefulEnums.*;

public class Main {

	public static void main(String[] args) {

		// Aqui vamos passar a usar as estruturas de dados do framework do Java. Vamos
		// usar Mapas, ArrayLists, LinkedLists, HashMaps, etc.
		Scanner in = new Scanner(System.in);
		SoftwareHouse house = new SoftwareHouseClass();
		String command;
		boolean exit;
		do {
			command = in.next();
			exit = decodeInstruction(command, in, house);

		} while (!exit);
		System.out.println("Bye!");
		in.close();

	}

	//Help menu command
	private static void helpMenu() {

		System.out.printf("Available commands:\n%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s", Commands.REGISTER.getDesc(),
				Commands.USERS.getDesc(), Commands.CREATE.getDesc(), Commands.PROJECTS.getDesc(),
				Commands.TEAM.getDesc(), Commands.ARTEFACTS.getDesc(), Commands.PROJECT.getDesc(),
				Commands.REVISION.getDesc(), Commands.MANAGES.getDesc(), Commands.KEYWORD.getDesc(),
				Commands.CONFIDENTIALITY.getDesc(), Commands.WORKAHOLICS.getDesc(), Commands.COMMON.getDesc(),
				Commands.HELP.getDesc(), Commands.EXIT.getDesc());
	}
//Command intepreter
	private static boolean decodeInstruction(String cmd, Scanner in, SoftwareHouse house) {
		boolean wantsToExit = false;
		cmd = cmd.toUpperCase();
		if (cmd.equals(Commands.HELP.toString())) {
			helpMenu();
		} else if (cmd.equals(Commands.EXIT.toString())) {
			wantsToExit = true;
		} else if (cmd.equals(Commands.REGISTER.toString())) {
			addUser(in, house);
		} else if (cmd.equals(Commands.USERS.toString())) {
			listUsers(house);
		} else if (cmd.equals(Commands.COMMON.toString())) {
			// TODO
		} else if (cmd.equals(Commands.CREATE.toString())) {
			create(in, house);
		} else if (cmd.equals(Commands.PROJECTS.toString())) {
			listProjects(house);
		} else if (cmd.equals(Commands.PROJECT.toString())) {
			listProjectDetails(house,in);
		} else if (cmd.equals(Commands.REVISION.toString())) {
			addRevisions(house, in);
		} else if (cmd.equals(Commands.MANAGES.toString())) {
			// TODO
		} else if (cmd.equals(Commands.KEYWORD.toString())) {
			// TODO
		} else if (cmd.equals(Commands.CONFIDENTIALITY.toString())) {
			// TODO
		} else if (cmd.equals(Commands.WORKAHOLICS.toString())) {
			listWorkaholics(house);
		} else if (cmd.equals(Commands.ARTEFACTS.toString())) {
			addArtefacts(in, house);
		} else if (cmd.equals(Commands.TEAM.toString())) {
			addTeamMembers(in, house);
		} else {
			System.out.printf("Unknown command. Type help to see available commands.\n", cmd);
		}
		return wantsToExit;

	}
//Method for the project command
	private static void listProjectDetails(SoftwareHouse house, Scanner in) {
		String projectName=in.nextLine().trim();
		
		if(!house.hasProject(projectName)) {
			System.out.printf("%s project does not exist.\n",projectName);
			return;
		}
		if(house.projectIsOutsourced(projectName)) {
			System.out.printf("%s is an outsourced project.\n",projectName);
			return;
		}
		System.out.printf("%s [%d] managed by %s [%d]:\n",projectName,house.getProjectConfidentialityLevel(projectName),house.getProjectManager(projectName,""),house.userByName(house.getProjectManager(projectName, "")).getClearance());
		Iterator<User> it=house.projectTeamMemberIterator(projectName);
		while(it.hasNext()) {
			User next=it.next();
			System.out.printf("%s [%d]\n", next.getName(),next.getClearance());
		}
		Iterator<Artefact> it2=house.getProjectArtefactIterator(projectName);
		while(it2.hasNext()) {
			
			Artefact r=it2.next();
			System.out.printf("%s [%d]\n", r.getName(),r.getConfLevel());
			Iterator<Revision> it3=house.getProjectArtefactRevisionsIterator(projectName,r.getName());
			
			while(it3.hasNext()) {
				
				Revision s=it3.next();
//				int revisionMonth=s.getDate().getMonth().getValue();
//				int revisionDay=s.getDate().
				System.out.printf("revision %d %s %s %s\n", s.getRevisionNumber()+1,s.getAuthorName(),s.getDate(),s.getDescription());
			}
		}
		
	}
//Method for the revisions command
	private static void addRevisions(SoftwareHouse house, Scanner in) {
		String teamMemberName = in.next().trim(), projectName = in.nextLine().trim();
		String artefactName = in.next().trim();
		String date=in.next().trim();
//		String str[] = in.next().split("-");
//		int day = Integer.parseInt(str[0]), month = Integer.parseInt(str[1]), year = Integer.parseInt(str[2]);
//		LocalDate date = LocalDate.of(year, month, day);
		String description = in.nextLine().trim();
		
		try {
			house.addRevisionToArtefact(date, teamMemberName, artefactName, description, projectName);
			System.out.printf("Revision %d of artefact %s was submitted.\n",house.getProjectArtefactByName(projectName, artefactName).getCurrentRevisionNum(),artefactName);

		} catch (NoSuchUserException NSUE) {
			System.out.printf("User %s does not exist.\n", teamMemberName);
		} catch (NoSuchMemberException NSME) {
			System.out.printf(NSME.getMessage(), teamMemberName, projectName);
		} catch (NoSuchProjectException NSPE) {

			System.out.printf(NSPE.getMessage(), projectName);
		} catch (ArtefactDoesNotExistException AEE) {

			System.out.printf(AEE.getMessage(), artefactName);
		}

	}
//Method for the team command
	private static void addTeamMembers(Scanner in, SoftwareHouse house) {
		String managerName = in.next();
		String projectName = in.nextLine().trim();
		int numOfNewTeamMembers = in.nextInt();
		List<String> list = new ArrayList<>();
		String currentDev = null;
		try {
			list.add("Latest team members:");
			for (int i = 0; i < numOfNewTeamMembers; i++) {
				try {
					currentDev = in.next().trim();
					house.addUserToProject(projectName, currentDev, managerName);
					list.add(String.format("%s: added to the team.", currentDev));
				} catch (NoSuchUserException NSUE) {
					list.add(String.format(NSUE.getMessage(), currentDev));
				} catch (NonOfUrBusinessException NOUBE) {
					list.add(String.format(NOUBE.getMessage(), currentDev));
				} catch (DevAlreadyInProjectException DAIPE) {
					list.add(String.format(DAIPE.getMessage(), currentDev));
				}
			}
			Iterator<String> it = list.iterator();
			while (it.hasNext()) {
				System.out.println(it.next());
			}
		}

		catch (projectAlreadyManagedException PAME) {
			System.out.printf(PAME.getMessage());
			in.nextLine();
		} catch (NoSuchManagerException NSME) {
			System.out.printf(NSME.getMessage(), managerName);
			in.nextLine();
		} catch (NoSuchProjectException NSPE) {

			System.out.printf(NSPE.getMessage(), projectName);
			in.nextLine();

		}

	}
//Method for the projects command
	private static void listProjects(SoftwareHouse house) {
		Iterator<Project> it = house.projects();
		if (house.noProjects()) {
			System.out.println("No projects added.");
		} else {
			System.out.println("All projects:");
			while (it.hasNext()) {
				Project r = it.next();
				if (r instanceof OutsourcedProjectClass) {
					System.out.printf(Constants.PRINT_OUTSOURCED.getDesc(), r.getName(), r.getManagerName(),
							((OutsourcedProject) r).getCompanyName());
				} else if (r instanceof InhouseProjectClass) {
					System.out.printf(Constants.PRINT_INHOUSE.getDesc(), r.getName(), r.getManagerName(),
							((InhouseProject) r).getConfidentialityLevel(), house.countProjectMembers(r.getName()),
							house.countProjectArtefacts(r.getName()), house.countProjectRevisions(r.getName()));
				}
			}
		}

	}
//Method for the create command
	private static void create(Scanner in, SoftwareHouse house) {
		String manager = in.next().trim(), type = in.next().trim(), name = in.nextLine().trim(), companyName = null;
		List<String> keywords = new ArrayList<>();
		int confidentiality = 0, ammountOfKeywords = in.nextInt();
		try {
			for (int i = 0; i < ammountOfKeywords; i++) {
				keywords.add(in.next().trim());
			}
			if (type.equals("outsourced")) {
				companyName = in.next().trim();
				house.addOutsourcedProject(name, companyName, manager, keywords.iterator());
				System.out.printf(Notification.PROJECT_ADDED.getMessage(), name);

			} else if (type.equals("inhouse")) {
				confidentiality = in.nextInt();
				house.addInhouseProject(name, confidentiality, manager, keywords.iterator());
				System.out.printf(Notification.PROJECT_ADDED.getMessage(), name);

			} else {
				System.out.println("Unknown project type.");
				in.nextLine();
				in.next();
			}
		} catch (ProjectExistsException PEE) {

			System.out.println(PEE.getMessage());
			in.nextLine();

		} catch (NoSuchManagerException UNEE) {

			System.out.printf(UNEE.getMessage(), manager);
			in.nextLine();

		} catch (TooMutchConfidentialityException TMCE) {

			System.out.printf(TMCE.getMessage(), manager, confidentiality);
			in.nextLine();

		}

	}

	private static void listWorkaholics(SoftwareHouse house) {
//Incomplete
	}
//Method for the artefacts command
	private static void addArtefacts(Scanner in, SoftwareHouse house) {
		String teamMemberName = in.next().trim(), projectName = in.nextLine().trim(), artefactName = null,
				description = null;
		String date = in.next().trim();
//		int day = Integer.parseInt(str[0]), month = Integer.parseInt(str[1]), year = Integer.parseInt(str[2]);
//		LocalDate date = LocalDate.of(year, month, day);		
		int confidentiality = 0;
		in.nextLine();
		int numOfArtefacts = in.nextInt(), i = 0;
		
		List<String> list = new ArrayList<>();
		try {
			list.add("Latest project artefacts:");
			for (i = 0; i < numOfArtefacts; i++) {
				try {
					artefactName = in.next().trim();
					confidentiality = in.nextInt();
					description = in.nextLine().trim();
					house.addArtefactToProject(date, confidentiality, teamMemberName, artefactName, description,
							projectName);
					list.add(String.format("%s: added to the project.", artefactName));
				} catch (ArtefactExistsException AEE) {
					list.add(String.format(AEE.getMessage(), artefactName));
				} catch (TooMutchArtefactConfidentialityException TMACE) {
					list.add(String.format(TMACE.getMessage(), artefactName));
				}
			}
			Iterator<String> it = list.iterator();
			while (it.hasNext()) {
				System.out.println(it.next());
			}
		}

		catch (NoSuchUserException NSUE) {
			System.out.printf("User %s does not exist.\n", teamMemberName);
			for (int j = 0; j < numOfArtefacts - i - 1; j++) {
				in.nextLine();
			}
		} catch (NoSuchMemberException NSME) {
			System.out.printf(NSME.getMessage(), teamMemberName, projectName);
			for (int j = 0; j < numOfArtefacts - i - 1; j++) {
				in.nextLine();
			}
		} catch (NoSuchProjectException NSPE) {

			System.out.printf(NSPE.getMessage(), projectName);
			for (int j = 0; j < numOfArtefacts - i - 1; j++) {
				in.nextLine();
			}
		}

	}
//Method for the register command
	private static void addUser(Scanner in, SoftwareHouse house) {
		String managerName = null, name = null;
		String pos;
		try {
			pos = in.next().toUpperCase();

			if (pos.equals(Job.DEVELOPER.toString())) {
				name = in.next();
				managerName = in.next();
				int clearance = in.nextInt();
				house.addDeveloper(name, managerName, clearance);
				System.out.printf(Notification.DEVELOPER_ADDED.getMessage() + "\n", name, clearance);
			} else if (pos.equals(Job.MANAGER.toString())) {
				name = in.next();
				int clearance = in.nextInt();
				house.addManager(name, clearance);
				System.out.printf(Notification.MANAGER_ADDED.getMessage() + "\n", name, clearance);
			} else {
				in.nextLine();
				throw new NonExistantPosException();
			}
		} catch (NonExistantPosException NEPE) {
			System.out.println(NEPE.getMessage());
		} catch (UserExistsException UEE) {

			System.out.printf(UEE.getMessage(), name);
		} catch (NoSuchManagerException NSME) {
			System.out.printf(NSME.getMessage(), managerName);
		} catch (ThatIsNotAManagerException INME) {
			System.out.printf(INME.getMessage(), managerName);
		}

	}
//Method for the users command
	private static void listUsers(SoftwareHouse house) {
		if (!house.noUsers()) {
			Iterator<User> it = house.getUserIterator();
			System.out.printf("All registered users:\n");
			while (it.hasNext()) {
				User r = it.next();
				if (r.isManager()) {
					System.out.printf("manager %s [%d, %d, %d]\n", r.getName(),
							house.countManagerDevelopers(r.getName()), house.countManagerProjects(r.getName()),
							house.countManagerProjects(r.getName())
									+ house.countManagerProjectAppearancesAsDev(r.getName()));
				} else {
					System.out.printf("developer %s is managed by %s [%d]\n", r.getName(),
							((Developer) r).getManagerName(),
							house.countDevAppearancesInProjects(r.getName()));

				}
			}
		} else {
			System.out.printf(Notification.USER_LIST_EMPTY.getMessage());
		}

	}

}
