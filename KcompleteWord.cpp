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

void solve(){
    int n,k;cin >> n >> k;
    string s;cin >> s;
    int i = 0,j = k-1;
    int ans = 0;
    while (i < j){
        vector<int> freq(26,0);
        for (int l = i; l < n; l+=k) {
            freq[s[l] - 'a']++;
        }
        for (int l = j; l < n; l+=k) {
            freq[s[l] - 'a']++;
        }
        int req = 2*(n/k);
        int maxi = *max_element(all(freq));
        ans += (req - maxi);
        i++;
        j--;
    }

    if (k&1){
        vi freq(26,0);
        for (int l = i; l < n; l+=k) {
            freq[s[l] - 'a']++;
        }
        int maxi = *max_element(all(freq));
        ans += (n/k - maxi);
     }

    cout << ans << endl;
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
