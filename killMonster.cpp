#include <bits/stdc++.h>
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

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
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

void solve(){
    ll hc,dc,hm,dm,k,w,a;
    cin >> hc >> dc;
    cin >> hm >> dm;
    cin >> k >> w >> a;

    ll nhc,ndc;
    for (int i = 0; i <= k; ++i) {
        nhc = hc + (i*a);
        ndc = dc +  ((k-i)*w);
        if ((nhc + dm - 1) / dm >= (hm + ndc - 1) / ndc){
            cout << "YES" << endl;
            return;
        }
    }

    cout << "NO" << endl;
}

int main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--){
        solve();
    }
    return 0;
}