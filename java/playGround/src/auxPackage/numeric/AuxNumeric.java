package auxPackage.numeric;

public class AuxNumeric {

	public static int boundedRandNum(int max,int min) {
		
		if(max<min) {
			
			int tmp=max;
			max=min;
			min=tmp;
			
		}
		return (int) Math.round(Math.random()*(max-min)+min);
		
	}
	public static String randString(int size) {
		
		String result="";
		for(int i=0;i<size;i++) {
			
			char c= (char) boundedRandNum(95, 121);
			result+=c;
		}
		return result;
	}
}
