#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'twoStrings' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts following parameters:
 *  1. STRING s1
 *  2. STRING s2
 */

//hashfunc to return an index
int hashfunc(char key){
     return key%26;
 }

string twoStrings(string s1, string s2) {
    //create new bool array in the heap and set all to false
    bool* chars = new bool[26];
    memset(chars, false, 26);
    
    //store a 'true' corresponding to each character in s1
    for(char c : s1){
        int index = hashfunc(c);
        chars[index] = true;
    }
    
    //if any character from s2 matches, deallocate that array and return YES
    for(char c : s2){
        int index = hashfunc(c);
        if(chars[index]){
            delete[] chars;
            return "YES";
        }
    }
    
    //if tht doesn't work, return NO
    return "NO";

}

int main()
{
    string q_temp;
    getline(cin, q_temp);

    int q = stoi(ltrim(rtrim(q_temp)));

    for (int q_itr = 0; q_itr < q; q_itr++) {
        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        string result = twoStrings(s1, s2);

        cout << result << "\n";
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
