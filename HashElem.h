#include <string>

class HashElem {
    public: 
        HashElem();
        HashElem(int index, std::string word);
        void setNext(HashElem* h);
        void setIndex(int index);
        int getIndex();
        std::string getWord();
        HashElem* getNext();
    private: 
        int index;
        std::string word;
        HashElem* next;
};