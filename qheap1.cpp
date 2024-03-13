#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

//basic min heapify
void minHeapify(vector<int> &arr, int n, int root){
    int left = 2*root + 1;
    int right = 2 * root + 2;
    int smallest;

    if(left<n && arr[left] < arr[root]){
        smallest = left;
    }else{
        smallest = root;
    }

    if(right < n && arr[right] < arr[smallest]){
        smallest = right;
    }

    if(smallest != root){
        swap(arr[smallest], arr[root]);
        minHeapify(arr, n, smallest);
    }
}

void deleteFromHeap(vector<int> &arr, int value){
    int n = arr.size();
    //find the index of the value to delete
    int index = -1;
    for(int i = 0; i < n; i++){
        if(arr[i] == value){
            index = i;
            break;
        }
    }

    //replace the value with the last element
    arr[index] = arr[n - 1];
    //remove the last element
    arr.pop_back();

    //restore heap property
    n = arr.size();
    if (index < n)
        minHeapify(arr, arr.size(), index);
}



int main() {
    int q;
    cin >> q;

    vector<int> arr;

    for (int i = 0; i < q; i++) {
        int t, v, n;
        cin >> t;

        switch (t) {
            case 1:
                cin >> v;
                arr.insert(arr.begin(), v);
                n = arr.size();
                if(n > 1){
                    minHeapify(arr, n, 0);
                }
                break;
            case 2:
                cin >> v;
                deleteFromHeap(arr, v);
                break;
            case 3:
                cout<<arr[0]<<endl;
                break;
        }
    }

    return 0;
}
