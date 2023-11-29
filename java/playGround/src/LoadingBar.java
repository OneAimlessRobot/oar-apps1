import ds.implem.DEqueInCircularArray;
import ds.interfaces.*;

import java.util.concurrent.*;
public class LoadingBar implements Runnable {
 private static Queue<Character> queue;
 	public static void main(String[] args) throws InterruptedException {
 		LoadingBar load= new LoadingBar();
 		Thread t= new Thread(load);
 		t.start();
			Thread.sleep(10000);
 		
 		
 	}
	@Override
	public void run() {
		queue= new DEqueInCircularArray<>(30);
//		for(int i=0;i<10;i++) {
//			
//			queue.enqueue('-');
//		}
//		for(int i=0;i<5;i++) {
//			
//			queue.dequeue();
//		}
		for(int i=0;i<10;i++) {
			
			queue.enqueue('#');
		}
		while(true) {
			queue.enqueue('#');
			queue.dequeue();
			System.out.print("\033[H\033[2J");
			System.out.println(queue);
			try {
				TimeUnit.MICROSECONDS.sleep(50000);
			} catch (InterruptedException e) {
			}
		}
		
	}

}

