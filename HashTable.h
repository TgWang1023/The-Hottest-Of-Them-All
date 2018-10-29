#include <string>
#include "HashElem.h"

class HashTable {
    public:
        HashTable();
        void insert(std::string word, int index);
        void delEntry(std::string word);
        void printHashTable();
    private:
        HashElem** table;
};