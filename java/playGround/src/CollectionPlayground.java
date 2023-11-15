


import playGround.auxPackage.smallAlgorithms.CollectionAlgorithms;
import playGround.ds.implem.HashTableBucket;
import playGround.ds.implem.MyHashSet;
import playGround.ds.implem.MyHashSetTreefy;
import playGround.ds.interfaces.Collection;
import playGround.ds.interfaces.List;
public class CollectionPlayground {

	public static void main(String[] args) {

		List<Integer> list= CollectionAlgorithms.toVList(CollectionAlgorithms.randIntArrAux(10000,0,1000));
//
		
		

		System.out.println("List1 tamanho:\n"+" "+list.size()+"\n lista:\n"+list);
		
		Collection<Integer> col= new MyHashSetTreefy<>();
		Collection<Integer> col2= new MyHashSet<>();
		Collection<Integer> col3= new HashTableBucket<>(100);

		col.clear();
		System.out.println("Set1 tamanho:\n"+" "+col.size());
		System.out.println("Set2 tamanho:\n"+" "+col2.size());
		System.out.println("Bucket tamanho:\n"+" "+col3.size());
		for(int i=0;i<list.size();i++) {
			col.add(list.get(i));
			
		}
		for(int i=0;i<list.size();i++) {
			col2.add(list.get(i));
			
		}

		for(int i=0;i<list.size();i++) {
			col3.add(list.get(i));
			
		}
	
		

		System.out.println("Set1 tamanho:\n"+" "+col.size());
		System.out.println("Set2 tamanho:\n"+" "+col2.size());
		System.out.println("Bucket tamanho:\n"+" "+col3.size());
		col.clear();
		col2.clear();
		col3.clear();
		System.out.println("Set1 tamanho:\n"+" "+col.size());
		System.out.println("Set2 tamanho:\n"+" "+col2.size());
		System.out.println("Bucket tamanho:\n"+" "+col3.size());
		for(int i=0;i<list.size();i++) {
			col.add(list.get(i));
			
		}
		for(int i=0;i<list.size();i++) {
			col2.add(list.get(i));
			
		}

		for(int i=0;i<list.size();i++) {
			col3.add(list.get(i));
			
		}
		System.out.println("Set1 tamanho:\n"+" "+col.size());
		System.out.println("Set2 tamanho:\n"+" "+col2.size());
		System.out.println("Bucket tamanho:\n"+" "+col3.size());
		}

}
