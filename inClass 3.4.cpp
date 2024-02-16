#include <sstream>
#include <iostream>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;

int choosePivotandOrganize(vector<double> &arr, int low, int high){
    double pivot = arr[high];
    int j = low - 1;
    for(int i = low; i < high; i++){
        if(arr[i] <= pivot){
            j++;
            double temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;

        }
    }

    double temp = arr[j + 1];
    arr[j + 1] = arr[high];
    arr[high] = temp;
    return j + 1;

}
void recursiveQuickSort(vector<double> &arr, int low, int high){
    if(low < high){
        int pivotIndex = choosePivotandOrganize(arr, low, high);

        recursiveQuickSort(arr, low, pivotIndex - 1);
        recursiveQuickSort(arr, pivotIndex + 1, high);
    }
}

void findMedian(vector<double> &arr){
    int arrSize = arr.size();
    double roundedMed;
    if(arrSize % 2 == 1){
        int index = (arrSize - 1)/2;
        double median = arr[index];
        roundedMed = double(round(median * 10)/10);
    }else{
        int index1 = arrSize / 2;
        int index2 = index1 - 1;

        double median = double(arr[index1] + arr[index2])/2;
        roundedMed = double(round(median * 10)/10);
    }
    
    cout << setprecision(1)<<roundedMed << endl;

}

int main(){
    vector<double> inputList;

    string input;
    //read the whole line
    getline(cin, input);

    //create string stream from input
    istringstream iss(input);

    double num;
    //read integers from string stream and add to the array
    while (iss >> num) {
        inputList.push_back(num);
    }

    int sizeL = inputList.size();

    vector<double> subList = {};
    for(int i = 0; i < sizeL; i++){
        subList.push_back(inputList[i]);
        int n = subList.size();
        recursiveQuickSort(subList, 0, n- 1);

        findMedian(subList);
    }



}
