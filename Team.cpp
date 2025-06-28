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
    int n,m;cin >> n >> m;
    if (n-m > 1){
        cout << -1 << endl;
        return;
    }
    if (2*(n+1) < m){
        cout << "-1" << endl;
        return;
    }
    if (n > m){
        if (abs(n-m) == 1){
            for (int i = 0; i < n+m; ++i) {
                if (i%2 == 0) cout << 0;
                else cout << 1;
            }
            cout << endl;
        }
    }else{
        if (abs(n-m) == 1 || n == m){
            for (int i = 0; i < n+m ; ++i) {
                if (i%2 == 0){
                    cout << 1;
                }else cout << 0;
            }
            return;
        }
        while (n > 0 && m > 0){
            if (abs(n-m) == 1 || n == m) break;
            cout << 110;
            m -= 2;
            n -= 1;
        }
        if (n == 0){
            if (m == 1){
                cout << 1 << endl;
                return;
            }else{
                cout << 11 << endl;
                return;
            }
        }
        for (int i = 0; i < n+m ; ++i) {
            if (i%2 == 0){
                cout << 1;
            }else cout << 0;
        }
        cout << endl;
        return;
    }
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
