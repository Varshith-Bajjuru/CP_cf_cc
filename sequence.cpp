#include "iostream"
#include "vector"
#include "algorithm"
#include "cmath"
#include "set"
#include "unordered_set"
#include "map"
#include "unordered_map"
#include "string"

using namespace std;

#define ll long long;

void processNumber(string &s) {
    int n = s.size();
    for (int i = n - 2; i >= 0; --i) {
        int sum = (s[i] - '0') + (s[i + 1] - '0');
        if (sum >= 10) {
            s[i] = '1';
            s[i + 1] = (sum - 10) + '0';
            cout << s << endl;
            return;
        }
    }
    int sum = (s[0] - '0') + (s[1] - '0');
    cout << to_string(sum) + s.substr(2) << endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        processNumber(s);
    }
    return 0;
}