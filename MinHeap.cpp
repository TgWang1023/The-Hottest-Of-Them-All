#include "MinHeap.h"

MinHeap::MinHeap() {
    heap_arr = new Entry[16];
    size = 0;
}

void MinHeap::insert(Entry e) {
    if(alreadyExist(e.getWord()) > 0) {
        heap_arr[alreadyExist(e.getWord())].increment();
        holdInvariant(alreadyExist(e.getWord()));
    } else {
        heap_arr[size + 1] = e;
        int runner = size + 1;
        while(runner / 2 > 0) {
            if(heap_arr[runner / 2].getFreq() > heap_arr[runner].getFreq()) {
                Entry temp = heap_arr[runner / 2];
                heap_arr[runner / 2] = heap_arr[runner];
                heap_arr[runner] = temp;
                runner = runner / 2;
            } else {
                break;
            }
        }
        size++;
    }
}

void MinHeap::replaceMin(std::string new_word) {
    if(alreadyExist(new_word) > 0) {
        heap_arr[alreadyExist(new_word)].increment();
        holdInvariant(alreadyExist(new_word));
    } else {
        heap_arr[1].replace(new_word);
    }
}

void MinHeap::printHeap() {
    for(int i = 0; i < size; i++) {
        heap_arr[i + 1].printEntry();
    }
}

int MinHeap::getSize() {
    return size;
}

int MinHeap::alreadyExist(std::string new_word) {
    for(int i = 0; i < size; i++) {
        if(heap_arr[i + 1].getWord() == new_word) {
            return i + 1;
        }
    }
    return -1;
}

void MinHeap::holdInvariant(int pos) {
    int runner = pos;
    while(runner * 2 <= size) {
        int left = 2 * runner;
        int right = 2 * runner + 1;
        if(heap_arr[runner].getFreq() > heap_arr[left].getFreq() || heap_arr[runner].getFreq() > heap_arr[right].getFreq()) {
            if(heap_arr[left].getFreq() < heap_arr[right].getFreq() || right > size) {
                Entry temp = heap_arr[left];
                heap_arr[left] = heap_arr[runner];
                heap_arr[runner] = temp;
                runner = runner * 2;
            } else {
                Entry temp = heap_arr[right];
                heap_arr[right] = heap_arr[runner];
                heap_arr[runner] = temp;
                runner = runner * 2 + 1;
            }
        } else {
            break;
        }
    }
}