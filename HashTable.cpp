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
    size = 0;
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
        while(runner != NULL) {
            if(runner->getWord() == word) {
                return runner->getIndex();
            }
            runner = runner->getNext();
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
    size++;
}

void HashTable::delEntry(std::string word) {
    int idx = hashIdx(word);
    if (table[idx] == NULL) {
        return;
    } else {
        HashElem* prev_runner = table[idx];
        HashElem* runner = table[idx];
        if(runner->getWord() == word) {
            runner->setNext(NULL);
        } else {
            while(runner != NULL) {
                runner = runner->getNext();
                if(runner != NULL && runner->getWord() == word) {
                    prev_runner->setNext(runner->getNext());
                    break;
                }
                prev_runner = prev_runner->getNext();
            }
        }
    }
}

void HashTable::changeContent(std::string word, int index) {
    int idx = hashIdx(word);
    if (table[idx] == NULL) {
        return;
    } else {
        HashElem* runner = table[idx];
        while(runner != NULL) {
            if(runner->getWord() == word) {
                runner->setIndex(index);
                break;
            }
            runner = runner->getNext();
        }
    }
}

void HashTable::printHashTable() {
    for(int i = 0; i < 20; i++) {
        std::cout << i << ": ";
        HashElem* runner = table[i];
        while(runner != NULL && runner->getIndex() > 0) {
            std::cout << runner->getWord() << ", " << runner->getIndex() << " -> ";
            runner = runner->getNext();
        }
        std::cout << "NULL" << std::endl;
    }
}