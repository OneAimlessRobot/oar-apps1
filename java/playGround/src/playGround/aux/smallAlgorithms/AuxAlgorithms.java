package playGround.aux.smallAlgorithms;
import playGround.aux.numeric.*;
public class AuxAlgorithms {
	
	
	public static Integer[] randArrAux(int max,int min,int size) {
		Integer[] arr= new Integer[size];
		for(int i=0;i<arr.length;i++) {
			
			arr[i]=AuxNumeric.boundedRandNum(max, min);
			
		}
		return arr;
		
		
	}
	
	public static int sumArr(Integer[] arr,int pos) {
		
		if(pos>=arr.length-1) {
			
			return arr[arr.length-1];
		}
		else {
			
			return sumArr(arr,pos-1)+ arr[pos];
		}
		
		
	}

}
