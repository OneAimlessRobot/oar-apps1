package ds.implem;
import java.io.*;

public class ObjectSaverLoader<E> {

	
	private String filepath;
	public ObjectSaverLoader(String filepath) {
		
		this.filepath=filepath;
		System.out.println(filepath);
		
		
	}
	
	public E load() {
		try {
			ObjectInputStream ois= new ObjectInputStream(new FileInputStream(filepath));
			
			E e= (E) ois.readObject();
			ois.close();
			return e;
			
			
			
		}
		catch (IOException e) {
			
			
			
			System.out.println("Non existing serialization file: Creatin new Object.");

			return null;
		}
		catch (ClassNotFoundException e) {
			
			
			
			System.out.println("Problems with class (maybe diferent versions or non existant: Creatin new Object.");

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
