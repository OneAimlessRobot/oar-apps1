


import ds.implem.QueueInCircularArray;
import ds.interfaces.Queue;
import java.util.concurrent.*;
public class CollectionPlayground {

	public static void main(String[] args) {
//
//		List<Integer> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randIntArrAux(1000,0,10));
//
//		

		Queue<Integer> queue= new QueueInCircularArray<>();
		System.out.println("Set1 tamanho:\n"+" "+queue.size());
//		for(int i=0;i<list.size();i++) {
//			queue.enqueue(list.get(i));
//			
//		}
		int curr=0;
		while(curr<6) {
			System.out.println(queue);
			try {
				TimeUnit.MICROSECONDS.sleep(1000000);
			} catch (InterruptedException e) {
			}
			queue.enqueue(5);
			curr++;
		}
		curr=0;
		while(true) {
			queue.dequeue();
			System.out.println(queue);
			try {
				TimeUnit.MICROSECONDS.sleep(500000);
			} catch (InterruptedException e) {
			}
			queue.enqueue(5);
			System.out.println(queue);
			try {
				TimeUnit.MICROSECONDS.sleep(500000);
			} catch (InterruptedException e) {
			}
		}


		


		}

}
