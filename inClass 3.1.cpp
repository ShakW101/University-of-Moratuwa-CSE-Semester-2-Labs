#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

int choosePivot(vector<int> &arr, int low, int high){
    int pivot = arr[high];
    int j = low - 1;
    for(int i = low; i < high; i++){
        if(arr[i] <= pivot){
            j++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

        }
    }

    int temp = arr[j + 1];
    arr[j + 1] = arr[high];
    arr[high] = temp;
    return j + 1;

}
void recursiveQuickSort(vector<int> &arr, int low, int high){
    if(low < high){
        int pivotIndex = choosePivot(arr, low, high);

        recursiveQuickSort(arr, low, pivotIndex - 1);
        recursiveQuickSort(arr, pivotIndex + 1, high);
    }
}

int main(){
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

    int sizeL = inputList.size();
    // Perform Quicksort
    recursiveQuickSort(inputList, 0, sizeL- 1);

    // Print the sorted array
    for (int num : inputList) {
        cout << num << " ";
    }
    cout << endl;

}
