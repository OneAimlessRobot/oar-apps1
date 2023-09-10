package zoo;

/**
 * Um animal, representado pela especie, nome e "fala".
 * @author Miguel Goulao / Adriano Lopes / Carla Ferreira 
 */
public interface Animal {
	  /**
	   * Devolve o nome do animal
	   * @return - nome do animal
	   */
	  public String getName();
	  
	  /**
	   * Devolve a espécie do animal
	   * @return - espécie do animal
	   */
	  public String getSpecies();
	  
	  /**
	   * Devolve o "falar" do animal
	   * @return - onomatopeia da voz do animal
	   */
	  public String speak();
}
