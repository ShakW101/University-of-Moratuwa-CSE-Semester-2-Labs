#include <iostream>
#include <sstream>
#include <vector>
using namespace std;
  
// function to heapify the tree
void heapify(int arr[], int n, int root)
{
    // build heapify
    int largest;
    int left = 2*root + 1;
    int right = 2*root + 2;
    
    //if the left node is larger than the root node, the largest index is index left
    //otherwise the largest one is root
    if(left<n && arr[left] > arr[root]){
            largest = left;

    }else{
        largest = root;
    }
    
    //then if right node is larger than the node 'largest',
    //well largest = right
    if(right < n && arr[right] > arr[largest]){
            largest = right;
    }
    
    //if the largest one is no longer the root, swap the root and largest 
    //and recursively call heapify on the affected subtree
    if(root != largest){
        swap(arr[root], arr[largest]);
        int swapped = largest;
        heapify(arr, n, swapped);
    }
//in case swap() doesn't work on this
//    int temp = arr[root];
//    arr[root] = arr[largest];
//    arr[largest] = temp;

}

// implementing heap sort
void heapSort(int arr[], int n)
{
    // build heap
    for(int i = n/2 - 1; i >=0; i--){
        heapify(arr, n, i);
    }

    // extracting elements from heap by swapping with last of unsorted array
    for(int i = n-1; i >0; i--){
        swap(arr[0], arr[i]);
        //this is max heapify 
        heapify(arr, i, 0);
    }

}

/* print contents of array */
void displayArray(int arr[], int n)
{
    for (int i=0; i<n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

// main program
int main()
{
    string input;
    getline(cin, input);

    stringstream ss(input);
    int num;
    vector<int> heap_arr;

    while (ss >> num) {
        heap_arr.push_back(num);
    }

    int n = heap_arr.size();
  
    heapSort(heap_arr.data(), n);
   
    displayArray(heap_arr.data(), n);
}
