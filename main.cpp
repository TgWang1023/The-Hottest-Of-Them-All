#include <fstream>
#include "MinHeap.h"
#include "HashTable.h"

using namespace std;

int main(int argc, const char* argv[]) {
    if (argc == 1) {
        cout << "Please enter the name of the file as an argument" << endl;
        exit(0);
    } else if (argc > 2) {
        cout << "Please only enter the name of the file as an argument" << endl;
        exit(0);
    }

    MinHeap word_heap;
    fstream word_file;
    word_file.open(argv[1]);
    if (word_file.is_open()) {
        cout << "Successfully opened file." << endl;
        string word;
        while(word_file >> word) {
            if (word_heap.getSize() >= 15) {
                word_heap.replaceMin(word);
            } else {
                word_heap.insert(Entry(word));
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
                cout << "Case 2" << endl;
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