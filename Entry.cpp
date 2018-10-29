#include "Entry.h"

Entry::Entry() {
}

Entry::Entry(std::string word) {
    this->word = word;
    frequency = 1;
}

void Entry::increment() {
    this->frequency++;
}

void Entry::replace(std::string new_word) {
    this->word = new_word;
}

void Entry::printEntry() {
    std::cout << "Word: " << this->word << ", Frequency: " << this->frequency << std::endl;
}

std::string Entry::getWord() {
    return word;
}

int Entry::getFreq() {
    return frequency;
}