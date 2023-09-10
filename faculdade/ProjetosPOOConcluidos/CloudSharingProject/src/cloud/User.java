package cloud;
import dataStructures.*;
/**
Premium pode partilhar ficheiros
Basic não pode.
Os ficheiros que são partilhados com premium (obviamente) são contados com metade do tamanho no premium de destino. São contados normalemnte em destinatários Basic.
Os premium podem partilhar com outros premium e com Basic. Os basic não podem partilhar com ninguém.
**/
public interface User{
	
	
	/**
	 * Retorna o Email deste utilizador
	 * @return
	 */
	String getName();
	/**
	 * Altera o Email do utilizador para "address"
	 * @param address
	 */
	void setName(String address);
	/**
	 * Devolve a capacidade máxima desta conta (armazenamento)
	 * @return
	 */
	int getCapacity();
	/**
	 * Acrescenta um ficheiro com tamanho "fileSize" e nome "fileName" á conta de nome "userName"
	 * @param userName
	 * @param fileName
	 * @param fileSize
	 */
	void addFile(String fileName,int fileSize);
	/**
	 * Retorna uma string que representa o tipo de utilizador
	 * @return
	 */
	String getType();
	/**
	 * True se o ficheiro com nome "fileName" já existir nesta conta
	 * @return
	 */
	boolean hasFile(String fileName);
	/**
	 * Retorna um iterador de todos os ficheiros deste user
	 * @return
	 */
	
	Iterator<File> listFiles();
	/**
	 * Retorna true se o usuario pode partilhar ficheiros. Falso caso contrario
	 * @return
	 */
	boolean allowsSharing();
/**
 * Verifica se um utilizador ainda tem espaço para um ficheiro de tamanho "fileSize"
 * @param
 * @return
 */
	boolean hasCapacity(int fileSize);
	/**
	 * Verifica se um utilizador tem o espaço necessário para que mais um ficheiro  seja partilhado com ele.
	 * @param filesize
	 * @return
	 */
	boolean hasSharingCapacity(int filesize);
	/**
	 * Partilha um ficheiro com outro user;
	 * @param user
	 */
	void shareFileWith(User user,String fileName);
	/**
	 * Retorna um ficheiro guardado na pasta deste user através da string que o identifica. (Se existir)
	 * @param
	 * @return
	 */
	File getFileWithFileName(String fileName);
	/**
	 * Adiciona um ficheiro à coleção de ficheiros partilhados deste utilizador
	 * @param foreignFile
	 */
	void receiveSharedFile(File foreignFile);
	
	/**
	 * Verifica se este user já possui na sua coleção um ficheiro partilhado por alguém com nome "otherUser" e com nome "fileName"
	 */
	
	boolean hasExternalFile(String otherUser,String fileName);
//	/**
//	 * Iterador de todos os ficheiros partilhados com este User
//	 * @return
//	 */
//	Iterator<File> sharedFileIterator();
	int getUsedStorage();
	/**
	 * Iterador de todos os ficheiros partilhados com este User
	 * @return
	 */
//	Iterator<File> sharedFileIterator();
	/**
	 * Consulta o armazenamento restante deste User.
	 * @return
	 */
	int getRemainingStorage();
}
