package playGround.adt.collections;

import playGround.adt.Collection;

public interface Set<T extends Comparable<T>> extends Collection<T> {

	/*Em sets nao ha indexacao. So consegues acrescentar coisas e transformar em array. Nada de procuras. There is no point em algoritmos de pesquisa. So se for para verificar se ja existe, o que e importante num set porque num set nao ha repetidos.*/
	
	boolean exists(T elem);
}
