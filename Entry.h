#ifndef _ENTRY_H_
#define _ENTRY_H_

#include <string>
#include <iostream>

class Entry {
    public:
        Entry();
        Entry(std::string word);
        void increment();
        void replace(std::string new_word);
        void printEntry();
        std::string getWord();
        int getFreq();
    private:
        std::string word;
        int frequency;
};

#endif