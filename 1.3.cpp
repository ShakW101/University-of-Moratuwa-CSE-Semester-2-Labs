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
    
    //the optimized bubble sort
    //same this as before, but with a boolean to check if any swaps hadn't taken place
    int sizeL = inputList.size();
    //iterates from the beginning of the list till the end, for as many times as there are elements in the list
    for(int i = 0; i < sizeL - 1; i++){
        //this boolean flag will check if any swaps have taken place
        bool flag = false;
        for(int j = 0; j < sizeL - 1 - i; j++){
            //if in 2 consecutive elements, the right one is greater than the left one, swap them
            if(inputList[j] > inputList[j+1]){
                int temp = inputList[j];
                inputList[j] = inputList[j+1];
                inputList[j+1] = temp;
                flag = true;
            }
        }
        //if no swaps occured, simply break the loop
        if(flag == false){
            break;
        }
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


