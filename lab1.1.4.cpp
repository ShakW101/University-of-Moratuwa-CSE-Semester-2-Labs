#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'insertionSort1' function below.
 *
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. INTEGER_ARRAY arr
 */

void insertionSort1(int n, vector<int> arr) {
    int temp = arr[n-1];
    //this int will keep help track if the comparison has reached the left end of the array
    int track = 0;
    for ( int i = n-2; i >= 0; i--){
        //if the left element is smaller than the current element, do the relevant swap and break this loop
        if(arr[i] < temp){
            arr[i+1] = temp;
            break;
        }
        
        //if the program reaches here, then the comparison failed. so print the array after copying  values as specified
        arr[i+1] = arr[i];
        for( int x = 0; x < n-1; x++){
            cout << arr[x] << " ";
        }
        cout << arr[n-1] <<endl;
        track++;
    }
    
    if(track == n-1){
        //swaps with the left-most element as this can't be reached in the for loop
        arr[0] = temp;
    }
    //print the array for the final time
    for( int x = 0; x < n-1; x++){
            cout << arr[x] << " ";
        }
    cout << arr[n-1] <<endl;
}

int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    string arr_temp_temp;
    getline(cin, arr_temp_temp);

    vector<string> arr_temp = split(rtrim(arr_temp_temp));

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        int arr_item = stoi(arr_temp[i]);

        arr[i] = arr_item;
    }

    insertionSort1(n, arr);

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
