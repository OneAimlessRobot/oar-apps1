package projectClasses.entities;

import userClasses.interfaces.User;
import projectClasses.interfaces.*;
import java.util.*;

public class ArtefactClass implements Artefact{
//	private final LocalDate date;
	private final String name,desc,date;
	private final int confLevel;
	private int currentRevision;
	private final User author;
	private List<Revision> revisions;

	public ArtefactClass(String date,String name,int confLevel,String desc,User author) {
		this.date=date;
		this.name=name;
		this.confLevel=confLevel;
		this.desc=desc;
		this.author=author;
		currentRevision=0;
		this.revisions= new ArrayList<>();
	}
//	@Override
//	public LocalDate getDate() {
//		// TODO Auto-generated method stub
//		return date;
//	}
	public String getDate() {
		return date;
	}
	/**
	 * @return the confLevel
	 */
	@Override
	public int getConfLevel() {
		return confLevel;
	}
	/**
	 * @return the name
	 */
	@Override
	public String getName() {
		return name;
	}
	/**
	 * @return the desc
	 */
	@Override
	public String getDesc() {
		return desc;
	}
	
	@Override
	public User getAuthor() {
		return author;
	}
	
	@Override
	public void addRevision(String date,String description,User author) {
		
		revisions.add(new RevisionClass(date,description,author,currentRevision++));
	}
	public int getCurrentRevisionNum() {
		return this.currentRevision;
	}
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (!(obj instanceof ArtefactClass)) {
			return false;
		}
		ArtefactClass other = (ArtefactClass) obj;
		return Objects.equals(name, other.name);
	}
	
	public Iterator<Revision> revisions(){
		return revisions.iterator();
	}
	public Iterator<Revision> sortedRevisions(){
		List<Revision> aux=new ArrayList<>();
		aux.addAll(0, revisions);
		Collections.sort(aux,new RevisionComparator());
		return aux.iterator();
	}
	public int getRevisionCount() {
		return getCurrentRevisionNum()+1;
	}
	
	public String getLastdate() {
		
		Collections.sort(revisions,new RevisionComparator());
		return revisions.get(0).getDate();
	}

}
