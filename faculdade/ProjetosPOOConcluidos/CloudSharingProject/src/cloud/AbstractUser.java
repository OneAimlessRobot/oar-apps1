package cloud;
import dataStructures.*;

public abstract class AbstractUser implements User {
	
	protected static final String PREMIUM="Premium",
								BASIC="Basic";
	protected int capacity;
	protected Array<File> files,sharedFiles;
	protected String name,type;
	
	
	protected AbstractUser(String name) {
		files= new ArrayClass<>();
		sharedFiles= new ArrayClass<>();
		this.name=name;
	}
	
	public String getName() {
		
		
		return name;
		
		
		
	}
	public String getType() {
		return this.type;
	}
	
	public void setName(String newName) {
		name=newName;
	}
	public void addFile(String fileName,int fileSize) {
		files.insertLast(new FileClass(this,fileName,fileSize));
	}
	
	public int getCapacity() {
		return this.capacity;
	}
	
	public boolean hasFile(String fileName) {
		
		return files.searchForward(new FileClass(this,fileName,0));
		
	}
	
	public boolean hasExternalFile(String otherUser,String fileName) {
		
		return files.searchForward(new FileClass(new PremiumUser(otherUser),fileName,0));
	}
	
	public boolean equals(Object e) {
		 boolean isEqual=false;
		if(e instanceof AbstractUser) {
				if(this.getName().equals(((AbstractUser)e).getName())) {
					isEqual= true;
				}
			}
		return isEqual;
		
	}
	public File getFileWithFileName(String fileName) {
		
		return files.get(files.searchIndexOf(new FileClass(this,fileName,0)));
	}
	public Iterator<File> listFiles(){
		return files.iterator();
	}
	
	public boolean allowsSharing() {
		
		return type.equals(PREMIUM);
	}
	public abstract int getUsedStorage();

	protected abstract int getStoredSum(Array<File> array);
	public abstract boolean hasSharingCapacity(int fileSize);
	
	public void receiveSharedFile(File file) {
		
		files.insertLast(file);
		files.get(files.searchIndexOf(new FileClass(file.getOwner(),file.getName(),file.getSize()))).setShared();
		
	}
	public void shareFileWith(User other,String fileName) {
		other.receiveSharedFile(this.getFileWithFileName(fileName));
	}
	public int sumOfSharedFiles() {
		Iterator<File> it=files.iterator();
		int total=0;
		while(it.hasNext()) {
			File r= it.next();
			if(r.beingShared()) {
				total+=r.getSize();
		}
		}
		return total;
	}
	
	public abstract int getRemainingStorage();
//	
//	public Iterator<File> sharedFileIterator(){
//		return sharedFiles.iterator();
//	}
	
}
