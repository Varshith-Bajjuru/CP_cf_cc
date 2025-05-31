#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

void solve() {
    ll n;
    cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ll maxi = -1e18;
    ll sum = 0;
    for (int i = 0; i < n; ++i) {
       sum += arr[i];
       maxi = max(maxi,sum);
        if (i < n && abs(arr[i])%2 == abs(arr[i+1])%2){
            sum = 0;
        }
        if(sum < 0)sum = 0;
    }
    cout << maxi << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
