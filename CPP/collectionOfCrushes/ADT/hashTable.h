#ifndef HTABLE_H
#define HTABLE_H

// HashTable class
template <typename Key, typename Value>
class HashTable {
private:
    // HashNode class
    struct HashNode {
        Key key;
        Value value;
        HashNode(const Key& k, const Value& v) : key(k), value(v) {}
    };


    // Iterator class
    class Iterator {
    private:
        typename std::vector<std::list<HashNode>>::const_iterator bucketIt;
        typename std::list<HashNode>::const_iterator nodeIt;
        const std::vector<std::list<HashNode>>& buckets;
        size_t numBuckets;

        // Advance iterator to the next valid position
        void advanceIterator() {
            while (bucketIt != buckets.end() && nodeIt == bucketIt->end()) {
                ++bucketIt;
                if (bucketIt != buckets.end()) {
                    nodeIt = bucketIt->begin();
                }
            }
        }

    public:
        Iterator(const std::vector<std::list<HashNode>>& b, size_t n)
            : bucketIt(b.begin()), nodeIt(b.begin()->begin()), buckets(b), numBuckets(n) {
            advanceIterator();
        }

        // Dereference operator
        const HashNode& operator*() const {
            return *nodeIt;
        }

        // Pre-increment operator
        Iterator& operator++() {
            ++nodeIt;
            advanceIterator();
            return *this;
        }

        // Post-increment operator
        Iterator operator++(int) {
            Iterator temp = *this;
            ++(*this);
            return temp;
        }

        // Equality operator
        bool operator==(const Iterator& other) const {
            return (bucketIt == other.bucketIt && nodeIt == other.nodeIt);
        }

        // Inequality operator
        bool operator!=(const Iterator& other) const {
            return !(*this == other);
        }
    };
    // Member variables
    std::vector<std::list<HashNode>> buckets;
    size_t numBuckets;
    size_t size; // number of elements in the hash table
    const double loadFactorThreshold = 0.75; // load factor threshold for rehashing

    // Hash function
    size_t hash(const Key& key) const;

    // Rehash the hash table
    void rehash();

public:
    // Constructor
    HashTable(size_t initialSize = 10);

    // Insert key-value pair into the hash table
    void insert(const Key& key, const Value& value);

    // Retrieve value associated with a key
    Value get(const Key& key) const;

    // Remove a key-value pair from the hash table
    void remove(const Key& key);

    // Check if a key exists in the hash table
    bool contains(const Key& key) const;

    // Get the current size of the hash table
    size_t getSize() const;

    Iterator getIterator(){

        return new Iterator(this->buckets);

    }
};
#include "hashTable.tpp"
#endif
