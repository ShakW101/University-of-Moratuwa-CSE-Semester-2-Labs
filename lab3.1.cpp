#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'superDigit' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. STRING n
 *  2. INTEGER k
 */
 
//this function adds the digits of a string.
int addDigits(string data){
    vector<int> digits;
    
    //it does this by storing the numerical value of each digit in the 
    //string inside a vector array by subtracting the 
    //value of '0' the digit's character value.
    for(char c : data){
        digits.push_back(c - '0');
    }

    int sizeL = digits.size();
    //-1 is returned to verify that the string length is 1 in the getSuperDigit function
    if(sizeL <= 1){
        return -1;
    }
    
    //adds the digits
    int sum = 0;
    for(int x : digits){
        sum += x;
    }
    return sum;
}

//this will work on adding the digits of the number recursively until a single digit remains.
string getSuperDigit(string n){
    int out = addDigits(n);
    if( out == -1){
        return n;
    }

    return getSuperDigit(to_string(out));

}

//this function will actually be dedicated to concatenating the string as asked.
int superDigit(string n, int k) {
    string concat = n;
    for (int i = 0; i < k - 1; i++) {
        concat += n;
    }
    
    //returning the value won't output anything for the test cases. so it's done manually here.
    cout<< getSuperDigit(concat)<< endl;
    return 0;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string first_multiple_input_temp;
    getline(cin, first_multiple_input_temp);

    vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

    string n = first_multiple_input[0];

    int k = stoi(first_multiple_input[1]);

    int result = superDigit(n, k);

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
