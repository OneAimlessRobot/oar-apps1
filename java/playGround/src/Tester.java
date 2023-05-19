import playGround.adt.*;
import playGround.adt.collections.List;
import playGround.ds.*;
import playGround.aux.smallAlgorithms.AuxAlgorithms;
public class Tester {
	
	public static void main(String[] args) {
		
		Integer[] arr= AuxAlgorithms.randIntArrAux(300,8900, 60);
		Stack<Integer> stack=new StackInArray<>(arr);
		List<Integer> list= AuxAlgorithms.toList(arr);
		System.out.printf("Hello world!!!!\nEsta e a stack:\n%s\nTamanho: %d\nEsta e a lista:\n%s\nTamanho: %d\n",stack,stack.size()+1,list,list.size());
		
	
	}

}
