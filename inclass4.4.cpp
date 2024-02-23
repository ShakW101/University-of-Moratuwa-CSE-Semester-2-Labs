#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>


using namespace std;
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

vector<int> mergeSort(vector<int> arr){
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
    left = mergeSort(left);
    right = mergeSort(right);
    Merge(left, right, arr);
    return arr;
}

vector<int> findPairs(vector<int> &arr, int n){
    vector<int> sorted = mergeSort(arr);
    vector<int> pairs = {sorted[0], sorted[1]};

    int min = (sorted[1] - sorted[0]);
    for(int i = 1; i < n -1; i++){
        int now = (sorted[i+1] - sorted[i]);
        if(now < min){
            min = now;
            pairs.clear();
            pairs.push_back(sorted[i]);
            pairs.push_back(sorted[i+1]);
        }else if(now == min){
            pairs.push_back(sorted[i]);
            pairs.push_back(sorted[i+1]);
        }
    }

    return pairs;
}
int main(){
    int n;
    cin >> n;

    cin.ignore();

    int inputs[n];
    vector<int> raw ;

    string input;
    //read the whole line
    getline(cin, input);

    //create string stream from input
    istringstream iss(input);

    int num;
    //read integers from string stream and add to the array
    int track = 0;
    while (iss >> num) {
        inputs[track] = num;
        track++;
    }

    for(int x : inputs){
        raw.push_back(x);
    }

    vector<int> pairs = findPairs(raw, n);

    n = pairs.size();
    for (int i = 0; i < n; ++i) {
        cout << pairs[i];
        if (i != n - 1) {
            cout << " ";
        }
    }
    cout << endl;

    return 0;
}
