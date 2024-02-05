#include <iostream>
#include <vector>
#include <sstream>

using namespace std;



int main() {
    vector<int> inputList;
    
    string input;
    //read the whole line
    getline(cin, input); 
    
    //create string stream from input
    istringstream iss(input); 

    int num;
    //read integers from string stream and add to the array
    while (iss >> num) { 
        inputList.push_back(num); 
    }
    
    //the insertion sort
    int sizeL = inputList.size();
    for (int i = 1; i < sizeL; ++i) {
        //choose a key starting from the left
        int key = inputList[i];
        int j = i - 1;

        // shift the elements to the left of the key that are greater than the key to 
        //one ahead of their current position
        while (j >= 0 && inputList[j] > key) {
            inputList[j+1] = inputList[j];
            j = j - 1;
        }
        inputList[j+1] = key;

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


