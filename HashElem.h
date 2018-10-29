#include <string>

class HashElem {
    public: 
        HashElem();
        HashElem(int index, std::string word);
        void setNext(HashElem* h);
        int getIndex();
        std::string getWord();
        HashElem* getNext();
    private: 
        int index;
        std::string word;
        HashElem* next;
};