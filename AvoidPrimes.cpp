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

int getNotes(int n){
    int x = 0;
    int temp = 9;
    while (n--){
        x += temp;
        temp *= 10;
    }
    return x;
}

int power(long long base, long long exponent) {
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) result *= base;
        base *= base;
        exponent /= 2;
    }
    return result;
}


void solve(){
    int n,k;cin >> n >> k;
    vi a(n);rep(i,0,n) cin >> a[i];
    int notes = k+1;
    int ans = 0;
    for (int i = 0; i < n-1; ++i) {
        int diff = a[i+1] - a[i];
        int currNotesCanBeUsed = getNotes(diff);
        ans += min(currNotesCanBeUsed,notes)*power(10,a[i]);
        notes -= min(currNotesCanBeUsed,notes);
    }
    if (notes > 0){
        ans += notes*power(10,a[n-1]);
    }
    cout << ans << endl;
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
