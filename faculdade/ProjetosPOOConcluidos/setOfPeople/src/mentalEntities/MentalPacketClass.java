package mentalEntities;

public class MentalPacketClass implements MentalPacket {
	
	private int priority;
	private static final int CONST=1;
	
	public MentalPacketClass(int priority){
		
		this.priority=priority;
		
	}
	
	public void process() {
		
		return;
	}
	public int getPacketPriority() {
		
		return this.priority;
		
		
	}

}
