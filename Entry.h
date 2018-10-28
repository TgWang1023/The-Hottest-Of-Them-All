#include <string>
#include <iostream>

class Entry {
    public:
        Entry();
        Entry(std::string word);
        void increment();
        void replace(std::string new_word);
        void printEntry();
    private:
        std::string word;
        int frequency;
};