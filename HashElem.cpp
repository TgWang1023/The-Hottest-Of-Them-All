#include <stddef.h>
#include "HashElem.h"

HashElem::HashElem() {
}

HashElem::HashElem(int index, std::string word) {
    this->index = index;
    this->word = word;
    this->next = NULL;
}

void HashElem::setNext(HashElem* h) {
    this->next = h;
}

void HashElem::setIndex(int index) {
    this->index = index;
}

int HashElem::getIndex() {
    return index;
}

std::string HashElem::getWord() {
    return word;
}

HashElem* HashElem::getNext() {
    return next;
}