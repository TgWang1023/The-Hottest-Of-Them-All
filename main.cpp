#include <fstream>
#include "MinHeap.h"
#include "HashTable.h"

using namespace std;

string convertToLower(string word) {
    string result = word;
    for(int i = 0; i < result.length(); i++) {
        result[i] = tolower(result[i]);
    }
    return result;
}

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        cout << "Please enter the name of the file as an argument" << endl;
        exit(0);
    } else if (argc > 2) {
        cout << "Please only enter the name of the file as an argument" << endl;
        exit(0);
    }

    MinHeap word_heap;
    HashTable idx_table;
    fstream word_file;
    word_file.open(argv[1]);
    if (word_file.is_open()) {
        cout << "Successfully opened file." << endl;
        string word;
        while(word_file >> word) {
            word = convertToLower(word);
            int found = idx_table.searchTable(word);
            if (word_heap.getSize() >= 15) {
                int resultIdx = word_heap.replaceMin(word, found);
                if(found > 0) {
                    idx_table.changeContent(word, word_heap.replaceMin(word, resultIdx));
                } else {
                    idx_table.delEntry(word_heap.getMin());
                    idx_table.insert(word, word_heap.replaceMin(word, resultIdx));
                }
            } else {
                Entry newEntry = Entry(word);  
                int resultIdx = word_heap.insert(newEntry, found);
                if(found > 0) {
                    idx_table.changeContent(word, resultIdx);
                } else {
                    idx_table.insert(word, resultIdx);
                }       
            }
        }
    } else {
        cout << "Unable to open this file." << endl;
        exit(0);
    }

    cout << "\n\n\nThe Hottest Of Them All" << endl;
    cout << "Please select the action you would like to perform:" << endl;

    while(1) {
        cout << "-------------------------" << endl;
        cout << "1: Print Heap" << endl;
        cout << "2: Print Hash Table" << endl;
        cout << "3: Insert a custom word" << endl;
        cout << "0: Exit" << endl;
        cout << "-------------------------" << endl;
        cout << "Choice: ";

        char choice;
        cin >> choice;

        switch(choice) {
            case '1':
                cout << "-------------------------" << endl;
                word_heap.printHeap();
                break;
            case '2':
                cout << "-------------------------" << endl;
                idx_table.printHashTable();
                break;
            case '3':
                cout << "Case 3" << endl;
                break;
            case '0':
                cout << "Goodbye" << endl;
                word_file.close();
                exit(0);
            default:
                cout << "Please enter 1, 2 or 3 to perform an action or 0 to quit" << endl;
        }
    }
    return 0;
}