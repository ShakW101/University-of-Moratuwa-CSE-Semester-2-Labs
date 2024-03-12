#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'cookies' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER k
 *  2. INTEGER_ARRAY A
 */
 
 //simple minHeapify function 
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
 

int cookies(int k, vector<int> A) {
    //first, let's check if we have to do any operations at all
    bool initiallyDone = true;
    for(int x : A){
        if (x < k){
            initiallyDone = false;
            break;
        }
    }
    
    //if so, return 0.
    if(initiallyDone)
        return 0;
        
    //if not, then first minHeapify the array
    int n = A.size();
    for(int i = (n/2)-1; i >= 0; i--){
        minHeapify(A, n, i);
    }
    
    
    int count = 0;
    //we will continue to  loop until a break is given inside.
    while(true){
        //get 1st (smallest cookie sweetness) value and swap with last in array
        int min1 = A[0];
        swap(A[0], A[n-1]);
        
        //min heapify the unorganized array excluding the last value
        minHeapify(A, n-1, 0);
        
        //get next smallest cookie sweetness value and calculate new sweetness
        int min2 = A[0];
        int newSweetness = min1 + 2*min2;
        
        //remove the last element and replace the first element with the new sweetness
        A.erase(A.begin() + n-1);
        n--;
        A[0] = newSweetness;
        
        //an operation was done. increment count by 1
        count++;
        
        //if our array is now done, return the count
        bool isBigger = true;
        for(int x : A){
            if(x < k){
                isBigger = false;
                break;
            }
        } 
        if(isBigger)
            return count;
        
        //if not, min heapify the new array if its size isn't 1. 
        //if its size is 1, then we can't do any more operations on it,
        //and reaching this far means we can't achieve targetted sweetness
        //so return -1
        if(n != 1)
            minHeapify(A, n, 0);
        else{
            count = -1;
            return count;
        }
    }
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int k = stoi(first_multiple_input[1]);

    string A_temp_temp;
    getline(cin, A_temp_temp);

    vector<string> A_temp = split(rtrim(A_temp_temp));

    vector<int> A(n);

    for (int i = 0; i < n; i++) {
        int A_item = stoi(A_temp[i]);

        A[i] = A_item;
    }

    int result = cookies(k, A);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
