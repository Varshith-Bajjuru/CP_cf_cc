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

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

void solve(){
    int n;cin >> n;
    if (n == 1){
        cout << "FastestFinger" << endl;
        return;
    }else if (n%2 || n == 2){
        cout << "Ashishgup" << endl;
        return;
    }else{
        if ((n&(n-1)) == 0){
          cout << "FastestFinger" << endl;
          return;
        }else{
            int two = 0;
            while ((n%2) == 0){
                two++;
                n/=2;
            }
            if (isPrime(n) && two > 1){
                cout << "Ashishgup" << endl;
                return;
            }
            if (isPrime(n) && two == 1){
                cout << "FastestFinger" << endl;
                return;
            }
            if (!isPrime(n) && two > 1){
                cout << "Ashishgup" << endl;
                return;
            }
            if (!isPrime(n) && two == 1){
                cout << "Ashishgup" << endl;
                return;
            }
        }
    }
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
