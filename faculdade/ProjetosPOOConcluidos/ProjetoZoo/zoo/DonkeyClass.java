package zoo;

/**
 * Classe que representa um burro.
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 */
public class DonkeyClass implements Animal {
	/**
	 * Definicao da especie.
	 */
	public static final String SPECIES = "BURRO";
	
	/**
	 * Definicao da "fala".
	 */
	private static final String SOUND = "Ihhh-ohhh";
	
	/**
	 * Nome do burro
	 */
	private String name;

	/**
	 * Constructor por omissao
	 * @param name - nome do burro
	 */
	public DonkeyClass(String name){ 
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

