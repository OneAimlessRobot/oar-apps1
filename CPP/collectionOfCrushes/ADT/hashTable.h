#ifndef HTABLE_H
#define HTABLE_H
template<typename T>
class HashTable{
private:
int DEFAULT_CAPACITY=10;
float DEFAULT_LOAD_FACTOR=0.75;

typename std::vector<std::list<T>> table;
void reHash();
public:
    HashTable();
    void add(T elem);
    void remove(T elem);
    void clear();
//    HashTableIterator<T> * iterator();



};
#endif
