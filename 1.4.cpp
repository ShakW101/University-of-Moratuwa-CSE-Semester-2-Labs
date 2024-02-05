#include <iostream>
#include <vector>
#include <sstream>

using namespace std;




int main() {
    vector<int> inputList;
    vector<int> sortedList;
    string input;
    //this reads the entire line
    getline(cin, input); 
    
    //create string stream
    istringstream iss(input);

    int num;
    //reads ints and stores them in vector array
    while (iss >> num) { 
        inputList.push_back(num); 
    }

    int sizeL = inputList.size();
    //the selection sort algorithm
    //this loop works in the logic that once the minimum element is found in the unsorted array
    //and swapped, that element is disregarded from the unsorted array
    for (int i = 0; i < sizeL - 1; ++i) {
        // find the minimum element in unsorted array
        int minIndex = i;
        for (int j = i + 1; j < sizeL; ++j) {
            if (inputList[j] < inputList[minIndex]) {
                minIndex = j;
            }
        }

        // swap the found minimum element with the first element
        int temp = inputList[i];
        inputList[i] = inputList[minIndex];
        inputList[minIndex] = temp;
    }
    //output
    for (int i = 0; i < sizeL; ++i) {
        cout << inputList[i];
        if (i != sizeL - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}


