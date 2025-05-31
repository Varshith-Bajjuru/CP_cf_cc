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

int getTeams(map<int,int> mp,int sum){
    int teams = 0;
    map<int,int> temp = mp;
    for(auto &i : temp){
       int w1 = i.first;
       int w2 = sum - w1;
        if (w1 > w2){
            continue;
        }
        else if (w1 == w2){
            teams += temp[w1]/2;
        }
        else if (temp.count(w2)){
            teams += min(temp[w1],temp[w2]);
        }
    }
    return teams;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    map<int,int> mp;
    rep(i,0,n){
        cin >> a[i];
        mp[a[i]]++;
    }
    int ans = INT_MIN;
    for (int i = 2; i <= 100; ++i) {
        ans = max(ans, getTeams(mp,i));
    }
    cout << ans << endl;
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
