#include "Entry.h"

Entry::Entry() {
    this->word = "stub";
    frequency = 0;
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