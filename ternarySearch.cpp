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

bool f(const string& s,int x){
    map<char,int> mp;
    int n = (int)s.size();
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        mp[s[i]]++;
        if (mp[s[i]] == 1){
            cnt++;
        }
        if (i >= x){
            mp[s[i-x]]--;
            if (mp[s[i-x]] == 0){
                cnt--;
            }
        }

        if (i+1 >= x && cnt == 3){
            return true;
        }
    }
    return false;
}

void solve(){
    string s;cin >> s;
    set<char> st(s.begin(),s.end());

    if (st.size() != 3){
        cout << 0 << endl;
        return;
    }
    int l = 3,r = (int)s.size();
    int ans = INT_MAX;
    while (l <= r){
        int mid = l + (r-l)/2;
        if(f(s,mid)){
            ans = mid;
            r = mid - 1;
        }else{
            l = mid + 1;
        }
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
