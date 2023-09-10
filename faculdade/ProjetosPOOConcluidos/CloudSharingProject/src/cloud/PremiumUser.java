package cloud;

import dataStructures.Array;
import dataStructures.Iterator;

public class PremiumUser extends AbstractUser {

	public PremiumUser(String email) {
		super(email);
		this.type=PREMIUM;
		this.capacity=1024*5;
	}

	@Override
	public int getCapacity() {
		// TODO Auto-generated method stub
		return capacity;
	}

	public int getUsedStorage() {
		
		return this.getStoredSum(files);
		
	}

	public boolean hasCapacity(int fileSize) {
		
		return (this.capacity-this.getUsedStorage())>=fileSize;
	}
	
	public boolean hasSharingCapacity(int fileSize) {
		
		return true;
	}
	public int getRemainingStorage() {
		return this.getStoredSum(files);		
	}
	protected int getStoredSum(Array<File> array) {
		Iterator<File> it=files.iterator();
		int total=0;
		while(it.hasNext()) {
			File r= it.next();
			if(r.beingShared()) {
				total+=0;
			}
			else {

				total+=r.getSize();
			}
		}
		return total;
	}
}
