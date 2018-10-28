#include "Entry.h"

class MinHeap {
    public:
        MinHeap();
        void insert(Entry e);
        void replaceMin(std::string new_word);
        void printHeap();
    private:
        Entry *heap_arr;
        int size;
};