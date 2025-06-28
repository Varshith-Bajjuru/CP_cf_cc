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

void solve(){
    string l,r;cin >> l >> r;
    vi tens(10);
    tens[0] = 1;
    for (int i = 1; i < 10; ++i) {
        tens[i] = tens[i-1]*10;
    }
    vi corrs(10);
    corrs[0] = 1;
    for (int i = 1; i < 10; ++i) {
        corrs[i] = corrs[i-1]*10 + 1;
    }

    map<int,int> mp;
    for (int i = 0; i < 10; ++i) {
        mp[tens[i]] = corrs[i];
    }

    int ansl = 0,ansr = 0;
    int m = (int)l.size();
    int n = (int)r.size();

    int ptr1 = m-1;
    while (ptr1 >= 0){
        int digit = l[ptr1] - '0';
        int power = (int)pow(10,m-1-ptr1);
        ansl += digit*mp[power];
        ptr1--;
    }
    int ptr2 = n-1;
    while (ptr2 >= 0){
        int digit = r[ptr2] - '0';
        int power = (int)pow(10,n-1-ptr2);
        ansr += digit*mp[power];
        ptr2--;
    }

    cout << ansr - ansl << endl;
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
