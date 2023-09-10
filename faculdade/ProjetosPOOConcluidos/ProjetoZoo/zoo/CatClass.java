package zoo;

/**
 * Classe que representa um gato.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 */
public class CatClass implements Animal {
	/**
	 * Definicao da especie.
	 */
	public static final String SPECIES = "GATO";
	
	/**
	 * Definicao da "fala".
	 */
	private static final String SOUND = "Miau!";

	/**
	 * Nome do gato
	 */
	private String name;

	/**
	 * Constructor por omissao
	 * @param name - nome do gato
	 */
	public CatClass(String name){ 
		this.name = name; 
	}
	
	@Override
	public String getName() { 
		return name; 
	}
	
	@Override
	public String getSpecies() { 
		return SPECIES; 
	}
	
	@Override
	public String speak() { 
		return SOUND; 
	}
}


