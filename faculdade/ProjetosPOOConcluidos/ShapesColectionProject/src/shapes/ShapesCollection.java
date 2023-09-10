package shapes;

public interface ShapesCollection {
	/**
	 * Verifica se uma instância de ShapesCollection está, ou não, vazia.
	 * @return <strong>true </strong> se está vazia. <strong> false </strong> se o contrário for verdade.
	 * 
	 */
	boolean isEmpty();
	/**
	 * Verificar se a shape com ID "ID" está na coleção.
	 * @param ID id a procurar
	 * @return true se é verdade. Falso caso contrário.
	 */
	boolean hasShape(String ID);
	/**
	 * Mesma coisa que o método anterior, mas em vez de retornar um booleano, retorna um
	 * objeto do tipo Shape caso encontre o ID dado como parâmetro na coleção.
	 * @pre !hasShape()
	 * @param ID id a procurar.
	 * @return O objeto do tipo Shape com o id fornecido
	 */
	Shape getShapeFromID(String ID);
	/**
	 * Adiciona uma instância de CircleClass á coleção, sendo inicializada com os valores fornecidos. 
	 * @pre !hasShape()
	 * @param ID id da Shape.
	 * @param x abcissa inicial.
	 * @param y ordenada inicial.
	 * @param radius Raio.
	 */
	void addCircle(String ID, int x, int y, int radius);
	/**
	 * Adiciona uma instância de RectangleClass á coleção, sendo inicializada
	 * com os valores fornecidos como argumentos.
	 * @pre !hasShape()
	 * @param ID id da Shape.
	 * @param x abcissa inicial.
	 * @param y ordenada inicial.
	 * @param height altura.
	 * @param width largura.
	 */
	void addRectangle(String ID, int x, int y, int height, int width);
	/**
	 * Altera as coordenadas da shape com o ID fornecido para (x,y);
	 * @param ID id a procurar.
	 * @param x nova abcissa.
	 * @param y nova ordenada.
	 */
	void move(String ID, int x, int y);
	/**
	 * Procura e retorna a Shape com menor valor de área. Caso haja empates na área, é devolvida a mais recente.
	 * @return
	 */
	Shape smallestArea();
	/**
	 * Constrói e retorna um iterador de todas as Shapes na coleção.
	 * @return
	 */
	Iterator allShapesIterator();
}
