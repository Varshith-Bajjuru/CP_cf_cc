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

    int x = (n*a[1] - (n-1)*a[0])/(n+1);
    int y = (a[0] - x)/n;
    if (x < 0 || y < 0){
        cout << "No" << endl;
        return;
    }
    if ((n*a[1] - (n-1)*a[0])%(n+1) != 0){
        cout << "No" << endl;
        return;
    }
    if ((a[0] - x)%n != 0){
        cout << "No" << endl;
        return;
    }

    int xCoff = 1,yCoff = n;
    for (int i = 0; i < n; ++i) {
        if ((x*xCoff + y*yCoff) != a[i]){
            cout << "No" << endl;
            return;
        }
        xCoff++;
        yCoff--;
    }
    cout << "Yes" << endl;
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