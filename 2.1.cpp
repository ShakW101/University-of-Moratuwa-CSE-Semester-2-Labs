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

void Merge(vector<int> left, vector<int> right, vector<int> &arr){
    //this takes the 2 passed left and right arrays and merges then using the 'pointer' method
    int nL = left.size();
    int nR = right.size();

    int i = 0;
    int j = 0;
    int k = 0;

    /*this loop checks how large an element of one array is compared to one in the other, and
     * adds it appropriately to the main array*/
    while(i < nL && j < nR){
        if(left[i] <= right[j]){
            arr[k] = left[i];
            i++;
        }else{
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    //these 2 loops will add remaining elements to the array, if any
    while(i < nL){
        arr[k] = left[i];
        k++;
        i++;
    }
    while(j < nR){
        arr[k] = right[j];
        k++;
        j++;
    }

}
vector<int> myMergeSort(vector<int> arr){
    int n = arr.size();

    //terminates if array is of size 1
    if(n < 2){
        return arr;
    }
    int mid = n/2;

    vector<int> left;
    vector<int> right;

    //divides main array into 2 arrays left and right
    for(int x = 0; x < mid; x++){
        left.push_back(arr[x]);
    }
    for(int x = mid; x < n; x++){
        right.push_back(arr[x]);
        //cout<< "WORRRKKK"<<endl;
    }

    //let the divide and conquer begin
    left = myMergeSort(left);
    right = myMergeSort(right);
    Merge(left, right, arr);
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

    sortedList = myMergeSort(inputList);

    printList(sortedList);
}
