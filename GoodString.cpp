#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update>;

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

int compute(string &s,char i,char j){
    int res = 0;
    int flip = 0;
    int ptr = 0;
    while (ptr < s.size()){
        if (flip == 0 && s[ptr] == i){
            flip = 1;
            res++;
        }else if (flip == 1 && s[ptr] == j){
            flip = 0;
            res++;
        }

        ptr++;
    }

    if (i != j && res%2 == 1){
        res--;
    }

    return res;
}

void solve(){
    string s;cin >> s;
    int n = (int)s.size();

    int ans = 2;
    for (char i = '0'; i <= '9'; ++i) {
        for (char j = '0'; j <= '9'; ++j) {
            ans = max(ans,max(compute(s,i,j), compute(s,j,i)));
        }
    }

    cout << n-ans << endl;
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
