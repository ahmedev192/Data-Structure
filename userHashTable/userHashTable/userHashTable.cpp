#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to compute a generic hash value for any type 'T'
template<typename T>
int hash_generic(const T& key, int n) {
    long long nn = n; // Convert 'n' to long long to prevent overflow
    long long sum = 0; // Initialize sum to store the hash value
    for (size_t i = 0; i < sizeof(key); ++i)
        // Iterate over each byte of 'key' and accumulate the hash value
        sum = (sum * 26 + reinterpret_cast<const unsigned char*>(&key)[i]) % nn;
    return sum % nn; // Return the hash value modulo 'n'
}

// Structure representing a key-value pair in the hash table
template<typename K, typename V>
struct HashEntry {
    K key; // Key of the entry
    V value; // Value associated with the key

    // Constructor to initialize key and value
    HashEntry(const K& key, const V& value) : key(key), value(value) {}
};

// Class representing a Hash Table
template<typename K, typename V>
class HashTable {
private:
    int table_size; // Size of the hash table
    vector<vector<HashEntry<K, V>>> table; // Vector of vectors to store entries

public:
    // Constructor to initialize the hash table with a given size
    HashTable(int table_size) : table_size(table_size) {
        table.resize(table_size); // Resize the table vector to the specified size
    }

    // Function to retrieve a value associated with a key
    bool get(const K& key, V& value) {
        int idx = hash_generic(key, table_size); // Compute the index using the hash function

        // Iterate through the entries at the computed index
        for (const auto& entry : table[idx]) {
            if (entry.key == key) { // If key matches, update 'value' and return true
                value = entry.value;
                return true;
            }
        }
        return false; // If key not found, return false
    }

    // Function to insert or update a key-value pair
    void put(const K& key, const V& value) {
        int idx = hash_generic(key, table_size); // Compute the index using the hash function

        // Iterate through the entries at the computed index
        for (auto& entry : table[idx]) {
            if (entry.key == key) { // If key already exists, update the value and return
                entry.value = value;
                return;
            }
        }
        table[idx].emplace_back(key, value); // If key doesn't exist, add a new entry
    }

    // Function to remove an entry based on the key
    bool remove(const K& key) {
        int idx = hash_generic(key, table_size); // Compute the index using the hash function
        for (size_t i = 0; i < table[idx].size(); ++i) {
            if (table[idx][i].key == key) { // If key matches, swap with last element and remove
                swap(table[idx][i], table[idx].back());
                table[idx].pop_back();
                return true;
            }
        }
        return false; // If key not found, return false
    }

    // Function to print all key-value pairs in the hash table
    void print_all() {
        for (int hash = 0; hash < table_size; ++hash) {
            if (table[hash].size() == 0) // Skip empty buckets
                continue;

            // Print hash index and associated key-value pairs
            cout << "Hash " << hash << ": ";
            for (const auto& entry : table[hash])
                cout << "(" << entry.key << ", " << entry.value << ") ";
            cout << "\n";
        }
    }
};

// Main function to demonstrate the usage of the HashTable class
int main() {
    HashTable<string, string> table(25); // Example usage with string keys and values
    table.put("John", "123-456-7890"); // Inserting key-value pairs
    table.put("Alice", "456-789-0123");
    table.put("Bob", "789-012-3456");

    table.print_all(); // Print all entries in the hash table

    string phoneNumber;
    if (table.get("Alice", phoneNumber)) // Retrieve Alice's phone number
        cout << "Alice's phone number is: " << phoneNumber << endl;

    table.remove("Alice"); // Remove Alice's entry

    cout << "After removing Alice:\n";
    table.print_all(); // Print all entries after removal
}
