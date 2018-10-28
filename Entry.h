#include <string>

class Entry {
    public:
        Entry();
        Entry(std::string word);
        void increment();
        void replace(std::string new_word);
    private:
        std::string word;
        int frequency;
};