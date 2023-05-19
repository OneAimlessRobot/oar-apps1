import playGround.adt.*;
import playGround.ds.*;
import playGround.aux.*;
import playGround.aux.smallAlgorithms.AuxAlgorithms;
public class Tester {
	
	public static void main(String[] args) {
		
		String[] arr= AuxAlgorithms.randStringArrAux(3,10, 60);
		Stack<String> stack=new StackInArray<>(arr);
		System.out.printf("Hello world!!!!\nEsta e a stack:\n    %s\n",stack);
	}

}
