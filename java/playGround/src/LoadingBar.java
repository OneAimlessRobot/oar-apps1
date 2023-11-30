import ds.exceptions.StackEmptyException;
import ds.implem.DEStackInDoubleList;
//import ds.implem.DEqueInCircularArray;
import ds.interfaces.*;

import java.util.concurrent.*;
public class LoadingBar implements Runnable {
 private static DEStack<Character> dEStack;
 	public static void main(String[] args) throws InterruptedException {
 		LoadingBar load= new LoadingBar();
 		Thread t= new Thread(load);
 		t.start();
			Thread.sleep(10000);
 		
 		
 	}
	@Override
	public void run() {
		dEStack= new DEStackInDoubleList<>();
//		for(int i=0;i<10;i++) {
//			
//			queue.enqueue('-');
//		}
//		for(int i=0;i<5;i++) {
//			
//			queue.dequeue();
//		}
		for(int i=0;i<10;i++) {

			dEStack.pushBack('#');
		}
		while(true) {
			dEStack.pushBack('#');
			try {
				dEStack.pop();
			} catch (StackEmptyException e) {
			}
			System.out.print("\033[H\033[2J");
			System.out.println(dEStack);
			try {
				TimeUnit.MICROSECONDS.sleep(50000);
			} catch (InterruptedException e) {
			}
		}
		
	}

}

