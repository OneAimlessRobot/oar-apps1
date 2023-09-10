package usefulEnums;

public enum Commands {
	//Each and every command and its respective description
	HELP("help - shows the available commands\n"), //ja ta
	EXIT("exit - terminates the execution of the program\n"), //ja ta
	REGISTER("register - adds a new user\n"), //ja ta
	CREATE("create - creates a new project\n"), 
	COMMON("common - employees with more projects in common\n"),
	USERS("users - lists all registered users\n"),
	PROJECT("project - shows detailed project information\n"),
	PROJECTS("projects - lists all projects\n"),
	REVISION("revision - revises an artefact\n"),
	KEYWORD("keyword - filters projects by keyword\n"),
	CONFIDENTIALITY("confidentiality - filters projects by confidentiality level\n"),
	TEAM("team - adds team members to a project\n"),
	MANAGES("manages - lists developers of a manager\n"),
	WORKAHOLICS("workaholics - top 3 employees with more artefacts updates\n"),
	ARTEFACTS("artefacts - adds artefacts to a project\n");
	
	
	private final String desc;
	Commands (String desc) {
		this.desc=desc;
	}
	public String getDesc() {
		return desc;
	}

}
