package cloud;

import dataStructures.Array;
import dataStructures.Iterator;

public class BasicUser extends AbstractUser {

	public BasicUser(String email) {
		super(email);
		// TODO Auto-generated constructor stub
		this.type=BASIC;
		this.capacity=2048;
	}

	@Override
	public int getCapacity() {
		// TODO Auto-generated method stub
		return this.capacity;
	}
	
	public int getUsedStorage() {
		
		return this.getStoredSum(files);
		
	}
		protected int getStoredSum(Array<File> array) {
			Iterator<File> it=files.iterator();
			int total=0;
			while(it.hasNext()) {
				File r= it.next();
				if(r.beingShared()) {
					total+=r.getSize()/2;
				}
				else {

					total+=r.getSize();
				}
			}
			return total;
		}
		
	
	public boolean hasCapacity(int fileSize) {
		
		return (this.capacity-this.getUsedStorage())>=fileSize;
	}
	public boolean hasSharingCapacity(int fileSize) {
		return this.getRemainingStorage()>=(fileSize/2);
	}
	
	public int getRemainingStorage(){
		return this.getCapacity()-this.getUsedStorage();
	}
	

}
