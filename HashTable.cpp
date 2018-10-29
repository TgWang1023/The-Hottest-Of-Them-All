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

int HashTable::searchTable(std::string word) {
    int idx = hashIdx(word);
    if (table[idx] == NULL) {
        return -1;
    } else {
        HashElem* runner = table[idx];
        while(runner->getNext() != NULL) {
            runner = runner->getNext();
            if(runner->getWord() == word) {
                return runner->getIndex();
            }
        }
    }
    return -1;
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
    if (table[idx] == NULL) {
        return;
    } else {
        HashElem* prev_runner = table[idx];
        HashElem* runner = table[idx];
        while(runner->getNext() != NULL) {
            runner = runner->getNext();
            if(runner->getWord() == word) {
                prev_runner->setNext(runner->getNext());
                break;
            }
            prev_runner = prev_runner->getNext();
        }
    }
}

void HashTable::changeContent(std::string word, int index) {
    int idx = hashIdx(word);
    if (table[idx] == NULL) {
        return;
    } else {
        HashElem* runner = table[idx];
        while(runner->getNext() != NULL) {
            runner = runner->getNext();
            if(runner->getWord() == word) {
                runner->setIndex(index);
                break;
            }
        }
    }
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