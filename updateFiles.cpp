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
    ll n,k;
    cin >> n >> k;
    ll cmpd = 1;
    ll hrs = 0;
    if(n == 1){
        cout << 0 << endl;
        return;
    }
    if (k == 1){
        cout << n-1 << endl;
        return;
    }
    while (cmpd < k){
        cmpd *= 2;
        hrs++;
    }
    if(cmpd < n) hrs += ((n-cmpd+k-1)/k);
    cout << hrs << endl;
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