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

void solve(){
    int n,m;cin >> n >> m;
    int s = n/2 + m/2;
    multiset<int> st;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (n%2 == 0 && m%2 == 0){
                int a1,a2,b1,b2;
                a1 = n/2;
                a2 = n/2 - 1;
                b1 = m/2;
                b2 = m/2 - 1;
                int d = min(abs(a1 - i) + abs(b1 - j),abs(a2 - i) + abs(b2 - j));
                d = min(d,abs(a1 - i) + abs(b2 - j));
                d = min(d,abs(a2 - i) + abs(b1 - j));
                st.insert(s+d);
            }
            else if(n%2 == 1 && m%2 == 1){
                int a1,b1;
                a1 = n/2;
                b1 = m/2;
                int d = abs(a1 - i) + abs(b1 - j);
                st.insert(s+d);
            }else if(n%2 == 0){
                int a1,b1,a2;
                a1 = n/2;
                a2 = n/2 - 1;
                b1 = m/2;
                int d = min(abs(a1 - i) + abs(b1 - j),abs(a2 - i) + abs(b1 - j));
                st.insert(s+d);
            }else if (m%2 == 0){
                int a1,b1,b2;
                a1 = n/2;
                b2 = m/2 - 1;
                b1 = m/2;
                int d = min(abs(a1 - i) + abs(b1 - j),abs(a1 - i) + abs(b2 - j));
                st.insert(s+d);
            }
        }
    }
    for(int i : st) cout << i << " ";
    cout << endl;
}

int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
