#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'arrayManipulation' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER n
 *  2. 2D_INTEGER_ARRAY queries
 */

long arrayManipulation(int n, vector<vector<int>> queries) {
    //question says to return ints, but this only works with long ints
    
    //this will initialize the 0s into the array
    long arr[n];
    for(int i = 0; i < n; i++){
        arr[i] = 0;
    }
    
    int operations = queries.size();
    
    //add the values of k between indices a and b inclusive to the array as asked
    for(int i = 0; i < operations;i++){
        int a = queries[i][0] - 1;
        int b = queries[i][1] - 1;
        int k = queries[i][2];
        
        for(int tracer = a; tracer <= b; tracer ++){
            arr[tracer] += k;
        }
    }
    
    //finds the maximum. we can start at maximum = 0 because k will never be negative
    long maximum = 0;
    for(int i = 0; i < n; i++){
        if(arr[i] > maximum){
            maximum = arr[i];
        }
    }
    
    /*
        For some reason, the given code won't output the maximum after it's returned.
        I have to manually output it using cout.
    */
    cout << maximum <<endl;
    
    return maximum;
    

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    int n = stoi(first_multiple_input[0]);

    int m = stoi(first_multiple_input[1]);

    vector<vector<int>> queries(m);

    for (int i = 0; i < m; i++) {
        queries[i].resize(3);

        string queries_row_temp_temp;
        getline(cin, queries_row_temp_temp);

        vector<string> queries_row_temp = split(rtrim(queries_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int queries_row_item = stoi(queries_row_temp[j]);

            queries[i][j] = queries_row_item;
        }
    }

    long result = arrayManipulation(n, queries);

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