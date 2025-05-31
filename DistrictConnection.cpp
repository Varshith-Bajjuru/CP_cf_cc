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
   return __gcd(a,b);
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
            res = (res % p * x% p) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    map<int,vector<int>> mp;
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    if ((int)mp.size() == 1){
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    vector<vector<int>> matrix;
    for(const auto& p : mp){
        matrix.push_back(p.second);
    }
    vector<int> first = matrix[0];
    vector<int> second = matrix[1];
    for (int i = 1; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            cout << matrix[0][0] << " " << matrix[i][j] << endl;
        }
    }
    for (int i = 1; i < matrix[0].size(); ++i) {
        cout << matrix[1][0] << " " << matrix[0][i] << endl;
    }
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
