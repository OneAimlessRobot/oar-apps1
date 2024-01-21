
// HashTable constructor
template <typename Key, typename Value>
HashTable<Key, Value>::HashTable(size_t initialSize) : numBuckets(initialSize), buckets(initialSize), size(0) {}

// Hash function
template <typename Key, typename Value>
size_t HashTable<Key, Value>::hash(const Key& key) const {
    return std::hash<Key>{}(key) % numBuckets;
}

// Rehash the hash table
template <typename Key, typename Value>
void HashTable<Key, Value>::rehash() {
    size_t newNumBuckets = numBuckets * 2;
    std::vector<std::list<HashNode>> newBuckets(newNumBuckets);

    for (const auto& bucket : buckets) {
        for (const auto& node : bucket) {
            size_t newIndex = hash(node.key);
            newBuckets[newIndex].emplace_back(node.key, node.value);
        }
    }

    numBuckets = newNumBuckets;
    buckets = std::move(newBuckets);
}

// Insert key-value pair into the hash table
template <typename Key, typename Value>
void HashTable<Key, Value>::insert(const Key& key, const Value& value) {
    size_t index = hash(key);
    for (auto& node : buckets[index]) {
        if (node.key == key) {
            std::cout << "Key already exists. Updating value." << std::endl;
            node.value = value;  // Update existing value
            return;
        }
    }
    buckets[index].emplace_back(key, value);
    ++size;

    // Check if rehashing is needed
    double loadFactor = static_cast<double>(size) / numBuckets;
    if (loadFactor > loadFactorThreshold) {
        rehash();
    }
}

// Retrieve value associated with a key
template <typename Key, typename Value>
Value HashTable<Key, Value>::get(const Key& key) const {
    size_t index = hash(key);
    for (const auto& node : buckets[index]) {
        if (node.key == key) {
            return node.value;
        }
    }
    throw std::out_of_range("Key not found in hash table.");
}