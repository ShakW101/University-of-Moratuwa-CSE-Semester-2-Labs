#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

/*
 * Complete the 'twoStacks' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER maxSum
 *  2. INTEGER_ARRAY a
 *  3. INTEGER_ARRAY b
 */
 
// void traverseStack(vector<int> &a, vector<int> &b, int maxSum, int achievedTotal, int count, int &max, int trackA, int trackB, int aSize, int bSize, int value){
//     if(maxSum >= achievedTotal && (trackA < aSize || trackB < bSize)){
//         achievedTotal += value;
//         count++;
//         traverseStack(a, b, maxSum, achievedTotal, count, max, trackA + 1, trackB,  aSize, bSize, a[trackA + 1]);
//         traverseStack(a, b, maxSum, achievedTotal, count, max, trackA, trackB+1,  aSize, bSize, b[trackB + 1]);
//     }
    
//     if(count > max){
//         max = count;
//     }
// }

double calculateGravity(vector<int> &arr, int &track, int n){
    int total;
    for(int i = track; i < n; i++){
        total += arr[i];
    }
    
    double gravity = double(total)/(n - track);
    track++;
    return gravity;
}

int twoStacks(int maxSum, vector<int> a, vector<int> b) {
    int achievedTotal = 0;
    int count = 0;
    int max = 0;
    int aSize = a.size();
    int bSize = b.size();
    int trackA = 0;
    int trackB = 0;
    
    while(achievedTotal <= maxSum ||(trackA < aSize && trackB < bSize)){
        double gravA, gravB;
        bool conA = trackA  == aSize;
        bool conB = trackB  == bSize;
        
        if(!conA){
            gravA = calculateGravity(a, trackA,  aSize);
        }
        if(!conB){
            gravB = calculateGravity(b, trackB,  bSize);
        }
        
        if(conA){
            achievedTotal += b[trackB];
            trackB++;
        }else if(conB){
            achievedTotal += a[trackA];
            trackA++;
        }else{
            if(gravA < gravB){
                achievedTotal += a[trackA];
                trackA++;
            }else{
                achievedTotal += b[trackB];
                trackB++;
            }
        }
        
        count++;
    }
    count++;
    cout << count;
    return count;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string g_temp;
    getline(cin, g_temp);

    int g = stoi(ltrim(rtrim(g_temp)));

    for (int g_itr = 0; g_itr < g; g_itr++) {
        string first_multiple_input_temp;
        getline(cin, first_multiple_input_temp);

        vector<string> first_multiple_input = split(rtrim(first_multiple_input_temp));

        int n = stoi(first_multiple_input[0]);

        int m = stoi(first_multiple_input[1]);

        int maxSum = stoi(first_multiple_input[2]);

        string a_temp_temp;
        getline(cin, a_temp_temp);

        vector<string> a_temp = split(rtrim(a_temp_temp));

        vector<int> a(n);

        for (int i = 0; i < n; i++) {
            int a_item = stoi(a_temp[i]);

            a[i] = a_item;
        }

        string b_temp_temp;
        getline(cin, b_temp_temp);

        vector<string> b_temp = split(rtrim(b_temp_temp));

        vector<int> b(m);

        for (int i = 0; i < m; i++) {
            int b_item = stoi(b_temp[i]);

            b[i] = b_item;
        }

        int result = twoStacks(maxSum, a, b);

        fout << result << "\n";
    }

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