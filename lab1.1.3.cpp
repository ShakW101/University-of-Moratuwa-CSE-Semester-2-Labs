#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    int num[3];
    cin >> num[0] >> num[1] >> num[2];
    int total = 0;
    //a for loop iterates through everything and adds them up to total
    for(int x : num){
        total += x;
    }
    cout << total << endl;
    return 0;
}
