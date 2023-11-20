package ds.exceptions;

public class QueueEmptyException extends RuntimeException {

	
	private static final long serialVersionUID = -8356813091943757539L;

	public QueueEmptyException() {
		
		super("Queue vazia!!!!");
		
	}
	
	
}
