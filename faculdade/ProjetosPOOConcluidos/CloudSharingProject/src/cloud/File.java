package cloud;

public interface File {
	/**
	 * Devolve o nome deste ficheiro
	 * @return
	 */
	String getName();
	/**
	 * Altera a instância de User que está definida como proprietária deste ficheiro
	 * @param ownerName
	 */
	void setOwner(User newOwner);
	/**
	 * Devolve o nome do proprietário do ficheiro;
	 * @return
	 */
	String getOwnerName();
	/**
	 * Devolve o tamanho deste ficheiro;
	 * @return
	 */
	int getSize();
	/**
	 * Devolve true se os ficheiros forem iguais. Falso caso contrário.
	 * @return
	 */
	
	boolean equals(Object e);
	
	/**
	 * Devolve true se o ficheiro já está a ser partilhado entre 2 contas.
	 */
	
	boolean beingShared();
	/**
	 * Quando este método é aplicado, este File passa a ter o estatuto de "partilhado"
	 */
	void setShared();
	/**
	 * devolve o objeto de tipo User associado a este file
	 * @return
	 */
	User getOwner();
}
