#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'

int MOD = 998244353;

void setIO(){
    fast_io();
#ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    bool allSame = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]){
            allSame = false;
            break;
        }
    }
    if (allSame){
        cout << "Yes" << endl;
        return;
    }
    if (n == 2){
        if (a[0] == a[1]){
            cout << "Yes" << endl;
            return;
        }else{
            cout << "No" << endl;
            return;
        }
    }

    for (int i = 0; i < n-1; ++i) {
        int x = 0;
        for (int j = 0; j <= i; ++j) {
            x ^= a[j];
        }
        int t = 0;
        int f = 0;
        for (int j = i+1; j < n; ++j) {
            t ^= a[j];
            if (t == x){
                f = 1;
                t = 0;
            }
        }
        if (t == 0 and f){
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
