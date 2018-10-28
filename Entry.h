#include <string>

class Entry {
    public:
        Entry(std::string word);
        ~Entry();
        void increment();
        void replace(std::string new_word);
    private:
        std::string word;
        int frequency;
};