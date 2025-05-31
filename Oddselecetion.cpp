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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

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

//void solve(){
//    int n,x;
//    cin >> n >> x;
//    vector<int> a(n);
//    int ev = 0,od = 0;
//    rep(i,0,n){
//        cin >> a[i];
//        if (a[i]&1){
//            od++;
//        } else ev++;
//    }
//
//    if (x == 1){
//        if (od > 0){
//            py;
//            return;
//        }else{
//            pn;
//            return;
//        }
//    }
//
//    if (ev >= x){
//        if (od > 0){
//            py;
//            return;
//        }else{
//            pn;
//            return;
//        }
//
//    }else{
//        int diff = x - ev;
//        if (od == diff){
//            if (od&1){
//                py;
//                return;
//            }
//            else{
//                pn;
//                return;
//            }
//        }
//        if (od > diff){
//            py;
//            return;
//        }else{
//            pn;
//        }
//    }
//}

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> a(n);
    int odd = 0,evs = 0;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (a[i]&1)odd++;
        else evs++;
    }

    for (int i = 1; i <= odd; i += 2) {
        if (i > x) break;
        if (x - i <= evs){
            py;
            return;
        }
    }
    pn;
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
