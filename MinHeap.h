#include "Entry.h"

class MinHeap {
    public:
        MinHeap();
        int insert(Entry e, int exists);
        int replaceMin(std::string new_word, int exists);
        std::string getMin();
        void printHeap();
        int holdInvariant(int pos);
        int getSize();
    private:
        Entry* heap_arr;
        int size;
};