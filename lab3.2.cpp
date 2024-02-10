#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'powerSum' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER X
 *  2. INTEGER N
 */

void generateCombinations(vector<int> nums, int n, int begin, vector<int> &current, vector<vector<int>> &result){
    result.push_back(current);

    for(int i = begin; i < n; i++){
        current.push_back(nums[i]);
        generateCombinations(nums, n, i+1, current, result);
        current.pop_back();
    }
}

//this does an indirect recursion which later recurses directly to find the combinations.
vector<vector<int>> findAllCombinations(vector<int> arr){
    vector<vector<int>> result;
    vector<int> current;
    int sizeL = arr.size();
    generateCombinations(arr,sizeL,  0, current, result);

    return result;
}

//added another function to avoid too many brackets in the findSums function (personal preference)
int compute(vector<int> &arr, int power){
    int total = 0;
    for(int x : arr){
        total += pow(x, power);
    }

    return total;
}

//this function finds the sum of the numbers in each list raised to the specified power
int findSums(vector<vector<int>> &arr, int power, int target){
    int total = 0;

    for(vector<int> scan : arr){
        int sum = compute(scan, power);
        if(sum == target) {
            total++;
        }
    }


    return total;
}
int powerSum(int X, int N) {
    //this will be the maximum term that will be checked
    double maxTerm = pow(X, 1.0/N);
    vector<int> nums;
    for(int i = maxTerm; i >= 1; i--){
        nums.push_back(i);
    }
    //will first search for all combinations of numbers from 1.- max value
   vector<vector<int>> combinations =  findAllCombinations(nums);

    //after finding the combinations, the program will add up and check all the 
    //sums of the combinations and compare it against the target
    int total = findSums(combinations, N, X);

    cout<<total<<endl;
    return total;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string X_temp;
    getline(cin, X_temp);

    int X = stoi(ltrim(rtrim(X_temp)));

    string N_temp;
    getline(cin, N_temp);

    int N = stoi(ltrim(rtrim(N_temp)));

    int result = powerSum(X, N);

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
