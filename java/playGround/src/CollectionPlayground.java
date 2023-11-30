


import ds.implem.BiasInDoubleLinkedList;
import ds.interfaces.Bias;
import ds.interfaces.List;


import auxPackage.smallAlgorithms.CollectionAlgorithms;
public class CollectionPlayground {

	public static void main(String[] args) {

		List<Integer> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randIntArrAux(10000,0,200));

		Bias<Integer> bias= new BiasInDoubleLinkedList<>(5000);
		
		for(int i=0;i<list.size();i++) {
			
			bias.insert(list.get(i));
		}
		
		System.out.println(bias.getBias());
		


		


		}

}
