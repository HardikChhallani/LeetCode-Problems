/* Question -
Problem Statement:
You are given a string of length n. Your task is to find and print the maximum integer present in the string s. An integer is defined by consecutive digit characters of string s.
- Print 1 if no integer is found.
- If string s is empty then print -1.

Input Format:
- The first line contains an integer n, i.e., the length of the string.
- The second line contains the string s.

Output Format:
The maximum integer present in the string s. Print -1 if no integer is found, and 1 if s is empty then print -2.

Constraints:
- 1 <= n <= 1000000
- String s will be read from the STDIN by the candidate.

Example:
Input:
39
ab12cd34ef56

Output:
56

Explanation:
We have 3 integers: 12, 34 and 56, since 56 is maximum, output is 56.

Sample Input:
5
abcde
Sample Output:
-1
*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    int n;
    if (!(cin >> n)) {
        cout << "Invalid input for n" << endl;
        return 1;
    }
    cin.ignore();
    string s;
    if (!getline(cin, s)) {
        cout << "Failed to read string" << endl;
        return 1;
    }

    long long maxNum = 0;  // Use long long to handle larger numbers
    long long currNum = 0;
    bool found = false;

    for (char& c : s) {
        if (isdigit(c)) {
            currNum = currNum * 10 + (c - '0');
            found = true;
            // Optional: Check for overflow
            if (currNum > LLONG_MAX / 10) {
                cout << "Number too large" << endl;
                return 1;
            }
        } else {
            maxNum = max(maxNum, currNum);
            currNum = 0;
        }
    }
    maxNum = max(maxNum, currNum);

    if (!found) cout << -1 << endl;
    else cout << maxNum << endl;
    return 0;
}
