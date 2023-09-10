package zoo;

/**
 * Classe que implementa com um vector acompanhado a coleccao de animais.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 *
 */
public class ZooClass implements Zoo {
	private static final int SIZE = 10;

	/**
	 * O vector de animais do zoo.
	 */
	private Animal[] animals;

	/**
	 * O numero de animais actual.
	 */
	private int counter;

	/**
	 * Construtor por omissao.
	 */
	public ZooClass() {
		animals = new Animal[SIZE];
		counter = 0;
	}

	@Override
	public void add(String name, String species) {
		if (counter == animals.length) 
			resize();
		animals[counter++] = createAnimal(name,species);
	}  

	/**
	 * Metodo auxiliar para duplicar o tamanho do vector. 
	 */
	private void resize() {
		Animal[] tmp = new Animal[animals.length*2];
		for (int i = 0; i < counter; i++) 
			tmp[i] = animals[i];
		animals = tmp;
	}
	
	/**
	 * Metodo auxiliar que cria um animal com o nome <code>name</code> e a especie <code>species</code>.
	 * @pre: hasSpecies(species)
	 * @param name - o nome do animal.
	 * @param species - o nome da especie.
	 * @return o animal criado de acordo com a especie dada.
	 */
	private Animal createAnimal(String name, String species) {
		Animal a = null;
		switch (species) {
			case DogClass.SPECIES:
				a = new DogClass(name);
				break;
			case CatClass.SPECIES:
				a = new CatClass(name);
				break;
			case DonkeyClass.SPECIES:
				a = new DonkeyClass(name);
				break;
		}
		return a;
	}

	@Override
	public boolean hasSpecies(String species) {
		boolean result = false;
		switch (species.toUpperCase()) {
			case DogClass.SPECIES:{

				result = true;
				break;
			}
			case CatClass.SPECIES:{

				result = true;
				break;
			}
			case DonkeyClass.SPECIES:{

				result = true;
				break;
			}
		}
		return result;
	}

	@Override
	public Iterator namedAnimals(String name) {
		return new NamesIterator(name, animals, counter);
	}

	@Override
	public Iterator speciesAnimals(String species) {
		return new SpeciesIterator(species, animals, counter);
	}
}

