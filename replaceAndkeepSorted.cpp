#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
#include "algorithm"
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

ll MOD = 1e9+7;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(ll n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

ll power(int a,int b){
    if (b == 0) return 1;
    ll x  = power(a,b/2);
    if (b%2 == 0){
        return x*x;
    } else{
        return x*x*a;
    }
}

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int caluclate(vector<int> &a,int i,int j){
    int ans = 0;
    for (int k = 2; k < (int)a.size(); ++k) {
        if (k > 2 && j < (int)a.size() - 2){
            ans += (a[k] - a[k-2] - 2);
        }
        else
        ans += (a[k] - a[k-2]);
    }
    return ans;
}

void solve(){
    int n,q,k;
    cin >> n >> q >> k;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    vector<int> ans;
    for (int i = 0; i < q; ++i) {
        int x,y;
        cin >> x >> y;
        vector<int> curr;
        curr.push_back(1);
        for (int j = x-1; j <= y-1 ; ++j) {
            curr.push_back(a[j]);
        }
        curr.push_back(k);
        ans.push_back(caluclate(curr,x-1,y-1));
    }
    for(auto i : ans) cout << i << endl;
}


int main() {
    fast_io();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}