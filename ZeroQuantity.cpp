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

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

pair<int,int> getPair(int x,int y){
    int num = gcd(x,y);
    x /= num;
    y /= num;
    return {x,y};
}

void solve() {
    int n; cin >> n;
    vi a(n); rep(i, 0, n) cin >> a[i];
    vi b(n); rep(i, 0, n) cin >> b[i];
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        if (a[i] == 0 && b[i] == 0) ans++;
    }

    map<pair<int,int>,int> freq;
    for (int i = 0; i < n; ++i) {
        if (a[i] != 0){
            freq[getPair(a[i],b[i])]++;
        }
    }

    int maxi = 0;
    for(auto p : freq){
        maxi = max(maxi,p.second);
    }

    cout << ans+maxi << endl;
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
