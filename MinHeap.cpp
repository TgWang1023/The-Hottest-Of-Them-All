#include "MinHeap.h"


MinHeap::MinHeap() {
    heap_arr = new Entry[16];
    size = 0;
}

int MinHeap::insert(Entry e, int exists, HashTable &h) {
    if(exists > 0) {
        heap_arr[exists].increment();
        return holdInvariant(exists, h);
    } else {
        heap_arr[size + 1] = e;
        int runner = size + 1;
        while(runner / 2 > 0) {
            if(heap_arr[runner / 2].getFreq() > heap_arr[runner].getFreq()) {
                Entry temp = heap_arr[runner / 2];
                heap_arr[runner / 2] = heap_arr[runner];
                heap_arr[runner] = temp;
                h.changeContent(heap_arr[runner].getWord(), runner);
                runner = runner / 2;
            } else {
                break;
            }
        }
        size++;
        return runner;
    }
}

int MinHeap::replaceMin(std::string new_word, int exists, HashTable &h) {
    if(exists > 0) {
        heap_arr[exists].increment();
        return holdInvariant(exists, h);
    } else {
        heap_arr[1].replace(new_word);
        return 1;
    }
}

std::string MinHeap::getMin() {
    return heap_arr[1].getWord();
}

void MinHeap::printHeap() {
    for(int i = 0; i < size; i++) {
        heap_arr[i + 1].printEntry();
    }
}

int MinHeap::getSize() {
    return size;
}

int MinHeap::holdInvariant(int pos, HashTable &h) {
    int runner = pos;
    while(runner * 2 <= size) {
        int left = 2 * runner;
        int right = 2 * runner + 1;
        if(heap_arr[runner].getFreq() > heap_arr[left].getFreq() || heap_arr[runner].getFreq() > heap_arr[right].getFreq()) {
            if(heap_arr[left].getFreq() < heap_arr[right].getFreq() || right > size) {
                Entry temp = heap_arr[left];
                heap_arr[left] = heap_arr[runner];
                heap_arr[runner] = temp;
                h.changeContent(heap_arr[runner].getWord(), runner);
                runner = runner * 2;
            } else {
                Entry temp = heap_arr[right];
                heap_arr[right] = heap_arr[runner];
                heap_arr[runner] = temp;
                h.changeContent(heap_arr[runner].getWord(), runner);
                runner = runner * 2 + 1;
            }
        } else {
            break;
        }
    }
    return runner;
}