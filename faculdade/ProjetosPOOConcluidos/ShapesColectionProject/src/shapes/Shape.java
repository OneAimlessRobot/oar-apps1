package shapes;

// Exercício: comentar interface Shape
public interface Shape {
	/**
	 * Devolve o identificador desta Shape.
	 * @return
	 */
	String getID();
	/**
	 * Devolve o tipo.
	 * @return
	 */
	String getType();
	/**
	 * Devolve a abcissa atual desta Shape.
	 * @return
	 */
	int getCenterX();
	/**
	 * Devolve a ordenada atual.
	 * @return
	 */
	int getCenterY();
	/**
	 * Altera a posição desta shape para (x,y).
	 * @param x nova abcissa.
	 * @param y nova ordenada.
	 */
	void move(int x, int y);
	/**
	 * Acrescentei este método porque ajuda a ordenar de forma mais conveniente as Shapes em objetos de ShapesCollection por idade.
	 * @return
	 */
	int getModelNo();
	/**
	 * Retorna a área desta Shape. Implementação depende na especialização de AbstractShapeClass que se considera.
	 * @return
	 */
	double area();
}
