#include <iostream>
#include <vector>

// Define a simple hash function that takes a string key and returns an index.
// This hash function sums up the ASCII values of the characters in the key
// and then takes the modulo of the sum with the size of the hash table.
size_t myHash(const std::string &key, size_t tableSize)
{
    size_t sum = 0;
    for (char c : key)
    {
        sum += static_cast<size_t>(c); // Convert char to its ASCII value
                                       // sum += (int)c;
    }
    return sum % tableSize; // Ensures the index is within bounds of the table
}

// Define a basic hash table using a vector of strings.
class HashTable
{
public:
    explicit HashTable(size_t size) : table(size) {}

    // Insert a key-value pair into the hash table.
    void insert(const std::string &key, const std::string &value)
    {
        size_t index = myHash(key, table.size()); // Compute hash index
        table[index] = value;                     // Store value at the computed index
    }

    // Retrieve the value associated with a key.
    std::string get(const std::string &key)
    {
        size_t index = myHash(key, table.size()); // Compute hash index
        return table[index];                      // Retrieve value from the computed index
    }

private:
    std::vector<std::string> table; // Vector to store hash table
};

int main()
{
    // Create a hash table with 10 slots.
    HashTable myTable(10);

    // Insert some key-value pairs.
    myTable.insert("apple", "fruit");
    myTable.insert("banana", "yellow");
    myTable.insert("cherry", "red");

    // Retrieve values based on keys.
    std::cout << "Value for 'banana': " << myTable.get("banana") << std::endl;
    std::cout << "Value for 'cherry': " << myTable.get("cherry") << std::endl;

    return 0;
}
