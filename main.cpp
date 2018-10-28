#include "MinHeap.h"
#include "HashTable.h"

using namespace std;

int main() {
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
                cout << "Case 1" << endl;
                break;
            case '2':
                cout << "Case 2" << endl;
                break;
            case '3':
                cout << "Case 3" << endl;
                break;
            case '0':
                cout << "Goodbye" << endl;
                exit(0);
            default:
                cout << "Please enter 1, 2 or 3 to perform an action or 0 to quit" << endl;
        }
    }
    return 0;
}