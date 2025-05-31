#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FAST_IO ios_base::sync_with_stdio(false), cin.tie(nullptr);
#define vi vector<int>

[[noreturn]] void solve() {
    string s;
    cin >> s;
    int n = s.size();

    if (n == 1) {
        cout << (s[0] == '1' ? 1 : 0) << endl;
        return;
    }

    int maxCnt = 0, cnt = 0;
    int firstOnes = 0, lastOnes = 0;
    bool hasZero = false;

    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            cnt++;
        } else {
            maxCnt = max(maxCnt, cnt);
            cnt = 0;
            hasZero = true;
        }
    }
    maxCnt = max(maxCnt, cnt);
    if (!hasZero) {
        cout << n * n << endl;
        return;
    }
    int i = 0;
    while (i < n && s[i] == '1') {
        firstOnes++;
        i++;
    }
    i = n - 1;
    while (i >= 0 && s[i] == '1') {
        lastOnes++;
        i--;
    }
    maxCnt = max(maxCnt, firstOnes + lastOnes);
    int maxArea = 0;
    for (int k = 1; k <= maxCnt; ++k) {
        maxArea = max(maxArea, k * (maxCnt - k + 1));
    }
    cout << maxArea << endl;
}

signed main() {
    FAST_IO;
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
