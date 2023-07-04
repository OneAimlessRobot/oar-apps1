#ifndef HASH_IT_H
#define HASH_IT_H
template<typename T>
class HashTableIterator{
private:
HashTable<T>* collection;
T elem;

public:

T next();
T prev();
void fullForward();
void rewind();
void init(HashTable<T>* table);
HashTableIterator(HashTable<T>* table);

};

#endif
