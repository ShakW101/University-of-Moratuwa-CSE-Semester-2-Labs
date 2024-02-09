#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

void printList(vector<int> arr){
    int sizeL = arr.size();
    for (int i = 0; i < sizeL; ++i) {
        cout << arr[i];
        if (i != sizeL - 1) {
            cout << " ";
        }
    }
    cout << endl;
}

//I passed the array by reference so I won't have to create and return a new array
void mergeArray(vector<int> &arr, int left, int mid, int right){
    //this merge works similar to the merge method of the recursive implementation
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftList[n1];
    int rightList[n2];

    for(int i = 0; i < n1; i++){
        leftList[i] = arr[left + i];
    }
    for(int i = 0; i < n2; i++){
        rightList[i] = arr[mid + 1 + i];
    }

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        if (leftList[i] <= rightList[j]) {
            arr[k] = leftList[i];
            i++;
        } else {
            arr[k] = rightList[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = leftList[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = rightList[j];
        j++;
        k++;
    }

}

vector<int> mergeSort (vector<int> arr){
    int sizeL = arr.size();
    //this for loop will iterate through sublists of sizes 1...2...4...8...
    //so on...
    for(int subSize = 1; subSize <= sizeL - 1; subSize = 2 * subSize){
        //this loop will divide those sublists and merge, iterating
        //through the elements of the array
        for(int leftEnd = 0; leftEnd < sizeL -1; leftEnd += 2 * subSize){
            int mid = leftEnd + subSize - 1;
            int rightEnd = leftEnd + 2 * subSize - 1;

            if(mid > sizeL - 1){
                mid = sizeL - 1;
            }

            if(rightEnd > sizeL - 1){
                rightEnd = sizeL - 1;
            }

            //calls another function to merge
            mergeArray(arr, leftEnd, mid, rightEnd);
        }
    }


    return arr;
}

int main(){
    vector<int> inputList;
    vector<int> sortedList;

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

    sortedList = mergeSort(inputList);

    printList(sortedList);
}
