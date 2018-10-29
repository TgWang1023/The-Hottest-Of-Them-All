#ifndef _HASHTABLE_H_
#define _HASHTABLE_H_

#include <string>
#include "HashElem.h"

class HashTable {
    public:
        HashTable();
        int searchTable(std::string word);
        void insert(std::string word, int index);
        void delEntry(std::string word);
        void changeContent(std::string word, int index);
        void printHashTable();
    private:
        HashElem** table;
        int size;
};

#endif 