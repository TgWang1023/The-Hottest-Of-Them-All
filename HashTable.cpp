#include "HashTable.h"
#include <iostream>

int hashIdx(std::string word) {
    int total = 0;
    for(int i = 0; i < word.length(); i++) {
        total += (int)word[i] * (i + 1);
    }
    return total % 20;
}

HashTable::HashTable() {
    table = new HashElem*[20];
    for(int i = 0; i < 20; i++) {
        table[i] = NULL;
    }
}

void HashTable::insert(std::string word, int index) {
    int idx = hashIdx(word);
    HashElem* h = new HashElem(index, word);
    if (table[idx] == NULL) {
        table[idx] = h;
    } else {
        HashElem* runner = table[idx];
        while(runner->getNext() != NULL) {
            runner = runner->getNext();
        }
        runner->setNext(h);
    }
}

void HashTable::delEntry(std::string word) {
    int idx = hashIdx(word);
    
}

void HashTable::printHashTable() {
    for(int i = 0; i < 20; i++) {
        std::cout << i << ": ";
        HashElem* runner = table[i];
        while(runner->getIndex() > 0 && runner->getNext() != NULL) {
            std::cout << runner->getIndex() << " -> ";
            if(runner->getNext() == NULL) {
                std::cout << "NULL" << std::endl;
                break;
            } 
            runner = runner->getNext();
        }
    }
}