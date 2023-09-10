package zoo;

/**
 * Classe que representa um cao.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 */
public class DogClass implements Animal {
	/**
	 * Definicao da especie.
	 */
	public static final String SPECIES = "CAO";
	
	/**
	 * Definicao da "fala".
	 */
	private static final String SOUND = "Beu!Beu!";
	
	/**
	 * Nome do cao
	 */
	private String name;

	/**
	 * Constructor por omissao
	 * @param name - nome do cao
	 */
	public DogClass(String name){ 
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