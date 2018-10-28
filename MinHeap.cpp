#include "MinHeap.h"
#include <iostream>

MinHeap::MinHeap() {
    heap_arr = new Entry[16];
    size = 0;
}

void MinHeap::insert(Entry e) {
    heap_arr[size + 1] = e;
    size++;
}

void MinHeap::replaceMin(std::string new_word) {
    heap_arr[1].replace(new_word);
}

void MinHeap::printHeap() {
    for(int i = 0; i < size; i++) {
        
    }
}