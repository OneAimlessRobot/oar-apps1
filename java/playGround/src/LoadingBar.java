import ds.exceptions.StackEmptyException;
import ds.implem.BiasInDoubleList;
//import ds.implem.DEqueInCircularArray;
import ds.interfaces.*;

import java.util.concurrent.*;
public class LoadingBar implements Runnable {
 private static Bias<Character> bias;
 	public static void main(String[] args) throws InterruptedException {
 		LoadingBar load= new LoadingBar();
 		Thread t= new Thread(load);
 		t.start();
			Thread.sleep(10000);
 		
 		
 	}
	@Override
	public void run() {
		bias= new BiasInDoubleList<>();
//		for(int i=0;i<10;i++) {
//			
//			queue.enqueue('-');
//		}
//		for(int i=0;i<5;i++) {
//			
//			queue.dequeue();
//		}
		for(int i=0;i<10;i++) {

			bias.pushBack('#');
		}
		while(true) {
			bias.pushBack('#');
			try {
				bias.pop();
			} catch (StackEmptyException e) {
			}
			System.out.print("\033[H\033[2J");
			System.out.println(bias);
			try {
				TimeUnit.MICROSECONDS.sleep(50000);
			} catch (InterruptedException e) {
			}
		}
		
	}

}

