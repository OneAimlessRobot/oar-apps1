package zoo;

/**
 * Coleccao de animais.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 *
 */
public interface Zoo {
	/**
	 * Adiciona o animal com o nome e especie dados a coleccao de animais.
	 * @pre hasSpecies(species)
	 * @param name - o nome do animal a adicionar.
	 * @param species - a espacie do animal a adicionar.
	 */
	public void add(String name, String species);
	
	/**
	 * Verifica se a especie dada existe.
	 * @param species - a especie do animal a verificar.
	 * @return <code>true</code> se a especie existe, 
	 * <code>false</code> caso contrario
	 */
	public boolean hasSpecies(String species);	
	
	/**
	 * Cria e devolve um iterador de animais da especie dada.
	 * @pre hasSpecies(species)
	 * @param species - o nome da especie cujos animais vao ser iterados.
	 * @return Iterador em que os animais a visitar sao todos os animais da 
	 * especie passada como argumento.
	 */
	public Iterator speciesAnimals(String species);
	
	/**
	 * Cria e devolve um iterador de animais com o nome dado.
	 * @param name - o nome dos animais a iterar.
	 * @return Iterador em que os animais a visitar sao todos os animais com 
	 * o nomes passado como argumento. 
	 */
	public Iterator namedAnimals(String name);
}
