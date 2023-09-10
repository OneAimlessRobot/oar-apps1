package usefulEnums;

public enum Notification {
	//Comando register
	PROJECT_ADDED("%s project was created.\n"),
	MANAGER_ADDED("User %s was registered as manager with clearance level %d."),
	DEVELOPER_ADDED("User %s was registered as developer with clearance level %d."),
	USER_LIST_EMPTY("No users registered.\n"),
	//Comando create
	NO_PROJECTS("No projects added.\n"),
	TYPE_UNKNOWN("Unknown project type.\n"),
	ARTEFACT_ADDED(".\n");
	
	
	private String message;
	
	Notification(String message){
		
		this.message=message;
	}
	
	public String getMessage() {
		return this.message;
	}

}
