package dsFaculdad.implem;
import java.io.*;
@SuppressWarnings("unchecked")
public class ObjectSaverLoader<E> {

	
	private String filepath;
	public ObjectSaverLoader(String filepath) {
		
		this.filepath=filepath;
		
		
	}
	
	public E load() {
		try {
			ObjectInputStream ois= new ObjectInputStream(new FileInputStream(filepath));
			
			E e= (E) ois.readObject();
			ois.close();
			return e;
			
			
			
		}
		catch (IOException e) {
			
			
			

			return null;
		}
		catch (ClassNotFoundException e) {
			
			
			return null;
		}
		
	}
	
	public void save(E intQueue) {
		try {
			ObjectOutputStream oos =new ObjectOutputStream(new FileOutputStream(filepath));
			oos.writeObject(intQueue);
			oos.close();
			
			
		}
		catch(IOException ioe) {
		
			
			System.out.println("Issue in writing...\n"+ioe.getMessage());
			
		}
		
		
		
	}
}
