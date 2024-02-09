#include <iostream>
#include <chrono>
#include <vector>
#include <random>

using namespace std;
using namespace chrono;

vector<int> generateRandomVector(int length, int minVal, int maxVal) {
    // Seed the random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(minVal, maxVal);

    // Generate the random vector
    vector<int> randomVector(length);
    for (int i = 0; i < length; ++i) {
        randomVector[i] = distribution(gen);
    }

    return randomVector;
}

void outputArray(vector<int> data){
    int sizeL = data.size();
    for (int i = 0; i < sizeL; ++i) {
        cout << data[i];
        if (i != sizeL - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

void bubbleSort(vector<int> inputList){
    //Your bubble sort algorithm here
    int sizeL = inputList.size();
    for(int i = 0; i < sizeL - 1; i++){
        for(int j = 0; j < sizeL - 1 - i; j++){
            if(inputList[j] > inputList[j+1]){
                int temp = inputList[j];
                inputList[j] = inputList[j+1];
                inputList[j+1] = temp;
            }
        }
    }
}

void optimizedBubbleSort(vector<int> inputList){
    int sizeL = inputList.size();

    for(int i = 0; i < sizeL - 1; i++){
        //this flag will check if any swaps have taken place
        bool flag = false;
        for(int j = 0; j < sizeL - 1 - i; j++){
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

}

void insertionSort(vector<int> inputList){
    int n = inputList.size();
    for (int i = 1; i < n; ++i) {
        int key = inputList[i];
        int j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key,
        // to one position ahead of their current position
        while (j >= 0 && inputList[j] > key) {
            inputList[j + 1] = inputList[j];
            j = j - 1;
        }
        inputList[j + 1] = key;

    }
}

void selectionSort(vector<int> inputList){
    int sizeL = inputList.size();

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
}


int main() {
    int upperLimit = 50;
    int lowerLimit = 3;
    int skips = 2;
    int listLow = 0;
    int listHigh = 500;

    vector<int> testList;
//REMOVE THESE FUNCTIONS AND PUT YOUR OWN. YOUR FUNCTIONS MUST BE VOID. FOR RECURSIVE MERGE SORT, USE A DIFFERENT VOID FUNCTION TO CALL THE VECTOR INT FUNCTION
    void (*algorithms[])(vector<int>) = {bubbleSort, optimizedBubbleSort, insertionSort, selectionSort};
//PUT THE NUMBER OF FUNCTIONS IN THE ABOVE ARRAY IN THIS VARIABLE
    int funcsLen = 4;
//THIS IS OPTIONAL. PUT THE NAME OF YOUR ALGORITHM IN THE SAME ORDER AS IN THE FUNCTION ARRAY
    string names[] = {"Bubble Sort", "Optimized Bubble Sort", "Insertion Sort", "Selection Sort"};

    for(int length = lowerLimit; length <= upperLimit; length = length + skips){
        
        cout << "For a list of " << length << " elements, " <<endl;
        for(int i = 0; i < funcsLen; i++) {
            duration<double> duration[3];
            for (int x = 0; x < 3; x++) {
                testList = generateRandomVector(length, listLow, listHigh);
                auto start = high_resolution_clock::now();
                algorithms[i](testList);
                auto end = high_resolution_clock::now();
                duration[x] = end - start;
            }
            ::duration<double> finalDur = (duration[0] + duration[1] + duration[2])/3;
//THIS WILL OUTPUT THE TIME TAKEN IN MICROSECONDS FOR EACH ALGORITHM IN THE ORDER YOU SPECIFIED ABOVE
            cout  << finalDur.count()*1000000   << endl;
        }
        cout<<endl;

    }
    return 0;
}
