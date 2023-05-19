package playGround.aux.numeric;

public class AuxNumeric {

	public static int boundedRandNum(int max,int min) {
		
		if(max<min) {
			
			int tmp=max;
			max=min;
			min=tmp;
			
		}
		return (int) Math.round(Math.random()*(max-min)+min);
		
	}
}
