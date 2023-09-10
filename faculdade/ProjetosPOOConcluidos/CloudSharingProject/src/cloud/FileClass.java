package cloud;

public class FileClass implements File {
	
	private int fileSize;
	private String fileName;
	private User owner;
	private boolean beingShared;
	
	public FileClass(User owner,String fileName,int fileSize) {
		this.fileSize=fileSize;
		this.fileName=fileName;
		this.owner=owner;
		beingShared=false;
		
	}
	public FileClass(User owner,String fileName,int fileSize,boolean beginsAsShared) {
		this.fileSize=fileSize;
		this.fileName=fileName;
		this.owner=owner;
		beingShared=beginsAsShared;
		
	}
	
	public String getName() {
		return fileName;
	}
	public String getOwnerName() {
		return owner.getName();
	}
	public User getOwner() {
		return owner;
	}

	@Override
	public void setOwner(User newOwner) {
		
		this.owner=newOwner;
		
	}
	@Override
	public int getSize() {
		// TODO Auto-generated method stub
		return fileSize;
	}

	@Override
	public boolean equals(Object e) {
		
		boolean isEqual=false;
		if(e instanceof FileClass) {
			
			if(((FileClass) e).getOwner().equals(this.getOwner())) {
				if(((FileClass) e).getName().equals(this.getName())) {
					isEqual=true;
				}
			}
		}
	return isEqual;
	}
	
	public boolean beingShared() {
		return beingShared;
	}
	public void setShared() {
		beingShared=true;
	}

}
