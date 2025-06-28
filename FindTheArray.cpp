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

void solve(vi &a){
    int n;cin >> n;
    if (n == 2) {
        cout << 2 << " " << 1 << endl;
    }
    else if (n == 3) {
        cout << 2 << " " << 1 << " " << 3 << endl;
    }
    else if (n == 4) {
        cout << 3 << " " << 1 << " " << 2 << " " << 4 << endl;
    }
    else if (n == 5) {
        cout << 3 << " " << 1 << " " << 2 << " " << 5 << " " << 4 << endl;
    }
    else if (n == 6) {
        cout << 3 << " " << 1 << " " << 2 << " " << 5 << " " << 4 << " " << 6 << endl;
    }
    else if (n == 7) {
        cout << 3 << " " << 1 << " " << 2 << " " << 5 << " " << 4 << " " << 7 << " " << 6 << endl;
    }
    else if (n == 8){
        for (int i = 0; i < 8; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }else if (n == 9){
        for (int i = 0; i < 9; ++i) {
            cout << a[i] << " ";
        }
        cout << endl;
        return;
    }else{
        if (n%2 == 0){
            for (int i = 0; i < n-1; ++i) {
                cout << a[i] << " ";
            }
            cout << n << endl;
            return;
        }else{
            for (int i = 0; i < n; ++i) {
                cout << a[i] << " ";
            }
            cout << endl;
            return;
        }
    }
}

int32_t main() {
    setIO();
    int t = 1;
    cin >> t;
    vi a(2*1e5+1);
    a[0] = 3;
    a[1] = 1;
    a[2] = 2;
    a[3] = 5;
    a[4] = 4;
    a[5] = 7;
    a[6] = 6;
    a[7] = 8;
    a[8] = 9;
    for (int i = 9; i <(int)2*1e5; ++i) {
        if (i%2 == 0){
            a[i] = i;
        }else a[i] = i+2;
    }
    while (t--) {
        solve(a);
    }
    return 0;
}
