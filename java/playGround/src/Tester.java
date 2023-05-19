import playGround.adt.*;
import playGround.ds.*;
import playGround.aux.*;
import playGround.aux.smallAlgorithms.AuxAlgorithms;
public class Tester {
	
	public static void main(String[] args) {
		
		Integer[] arr= AuxAlgorithms.randArrAux(1000, 420, 60);
		Stack<Integer> stack=new StackInArray<>(arr);
		System.out.printf("Hello world!!!!Esta e a stack:\n %s\n",stack);
	}

}
