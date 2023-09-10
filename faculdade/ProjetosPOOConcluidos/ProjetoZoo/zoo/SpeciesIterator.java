package zoo;

/**
 * Implementa um iterador por especie para a coleccao de animais.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 *
 */
public class SpeciesIterator implements Iterator {
	/**
	 * O vector de animais do zoo.
	 */
	private Animal[] animals;
	
	/**
	 * O numero de animais actual
	 */
	private int counter;
	
	/**
	 * O animal corrente.
	 */
	private int current;
	
	/**
	 * Especie de animais a iterar.
	 */
	private String species;

	/**
	 * Construtor por omissao
	 * @param species - especie dos animais a iterar.
	 * @param animals - vector dos animais do zoo.
	 * @param counter - numero de animais actual.
	 */
	public SpeciesIterator(String species, Animal[] animals, int counter) {
		this.animals = animals;
		this.counter = counter;
		this.species = species;
	}

	@Override
	public void init() {
		current = 0;
		searchNext();
	}

	@Override
	public boolean hasNext() {
		return (current < counter);
	}

	@Override
	public Animal next() {
		System.out.printf("index atual deste iterador: %d\n", current);
		Animal res = animals[current++];
		searchNext();
		return res;
	}
	
	/**
	 * Metodo auxiliar que avanca o iterador ate o proximo animal com a especie <code>species</code> 
	 */
	private void searchNext() {
		while ( hasNext() && !animals[current].getSpecies().equalsIgnoreCase(species))
			//			System.out.printf("Comprimento da lista: %d, Index atual: %d\n",animals.length,current);
			current++;
	}
}