package cloud;
import dataStructures.*;
public class CloudSharingClass implements CloudSharing{
	
	private Array<User> userBase;
	
	public CloudSharingClass() {
		userBase=new ArrayClass<>();
	}

	@Override
	public void shareFile(User src,User dst, String name) {
		dst.receiveSharedFile(src.getFileWithFileName(name));
	}
//pre: !hasUser(email)
	@Override
	public void addUser(String email, String type) {
		
		if(type.equals("premium")) {
		
		userBase.insertLast(new PremiumUser(email));
		}
		else if(type.equals("basic")) {
			userBase.insertLast(new BasicUser(email));
		}
	}

	@Override
	public boolean hasUser(String name) {
		
		return userBase.searchForward(new PremiumUser(name));
	}

	@Override
	public boolean hasOwnedFile(String userName, String fileName) {
		
		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).hasFile(fileName);
	}

	@Override
	public void addFile(String userName, String fileName, int fileSize) {
		
		userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).addFile(fileName, fileSize);
		
	}

	@Override
	public boolean hasCapacity(String userName, int fileSize) {
		
		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).hasCapacity(fileSize);
	}

	@Override
	public boolean allowsSharing(String userName) {
		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).allowsSharing();
	}

	@Override
	public boolean hasSharedFile(String owner, String otherUser, String fileName) {
		
		return userBase.get(userBase.searchIndexOf(new PremiumUser(owner))).hasExternalFile(otherUser,fileName);
	}

	@Override
	public boolean hasSharingCapacity(String owner, String otherUser, String fileName) {
		
		return userBase.get(userBase.searchIndexOf(new PremiumUser(otherUser))).hasSharingCapacity(
				
				userBase.get(userBase.searchIndexOf(new PremiumUser(owner))).getFileWithFileName(fileName).getSize());
	}

	@Override
	public Iterator<User> listAll() {
		
		return userBase.iterator();
	}

	@Override
	public Iterator<File> listFiles(String userName) {
		
		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).listFiles();
	}

	@Override
	public void shareFile(String owner, String other, String file) {
		
		userBase.get(userBase.searchIndexOf(new PremiumUser(owner))).shareFileWith(
				userBase.get(userBase.searchIndexOf(new PremiumUser(other))), file);
		
	}
	public int getUserUsedStorage(String user) {
		return userBase.get(userBase.searchIndexOf(new PremiumUser(user))).getUsedStorage();
	}
	
	public int getUserRemainingStorage(String userName) {
		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).getRemainingStorage();
	}

//	@Override
//	public Iterator<File> listSharedFiles(String userName) {
//		
//		return userBase.get(userBase.searchIndexOf(new PremiumUser(userName))).sharedFileIterator();
//	}

}
