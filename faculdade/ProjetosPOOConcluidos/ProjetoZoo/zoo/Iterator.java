package zoo;

/**
 * Iterador para a coleccao de animais.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 */
public interface Iterator {
	/**
	 * Vai para o inicio da coleccao
	 */
	public void init();

	/**
	 * Verifica se existe mais algum elemento a visitar
	 * @return - <code>true</code>, se houver mais elementos a visitar, 
	 * <code>false</code>, caso contrario
	 */
	public boolean hasNext();

	/**
	 * Devolve o proximo elemento a visitar na colecao.
	 * @pre hasNext()
	 * @return - o proximo elemento a visitar, se existir, ou null, caso contrario.
	 */
	public Animal next();
}

