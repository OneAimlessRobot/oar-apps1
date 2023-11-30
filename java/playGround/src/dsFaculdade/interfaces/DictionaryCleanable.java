/**
* @author Adriano Antonio Campos Valente (62411) aa.valente@campus.fct.unl.pt
* @author Pedro Miguel Martinho Assuncao (68840) pedroassuncao@gmail.com
*/

package dsFaculdade.interfaces; 


/**
 * Dictionary Abstract Data Type 
 * Includes description of general methods to be implemented by dictionaries.
 * @author AED  Team
 * @version 1.0
 * @param <K> Generic Key
 * @param <V> Generic Value 
 */

public interface DictionaryCleanable<K,V> extends Dictionary<K,V>
{             
	/**
	 * Puts this collection in a state where isEmpty() will return true.
	 * 
	 */
 void clean(); 

} 


