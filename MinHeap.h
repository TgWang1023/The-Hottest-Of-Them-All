#include "Entry.h"

class MinHeap {
    public:
        MinHeap();
        void insert(Entry e);
        void replaceMin(std::string new_word);
        void printHeap();
        void holdInvariant(int pos);
        int getSize();
        int alreadyExist(std::string new_word); // Will be removed after implementing hash table!!!
    private:
        Entry* heap_arr;
        int size;
};