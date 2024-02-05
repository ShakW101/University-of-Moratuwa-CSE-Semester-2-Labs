#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);



int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));
    //basic if-else statements 
    if(n > 9){
        cout << "Greater than 9" <<endl;
    }else if(n > 8){
        cout << "nine" << endl;
    }else if(n > 7){
        cout << "eight" << endl;
    }else if(n > 6){
        cout << "seven" << endl;
    }else if(n > 5){
        cout << "six" << endl;
    }else if(n > 4){
        cout << "five" << endl;
    }else if(n > 3){
        cout << "four" << endl;
    }else if(n > 2){
        cout << "three" << endl;
    }else if(n > 1){
        cout << "two" << endl;
    }else{
        cout << "one" << endl;
    }
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
