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

int getAns(unordered_map<int,int> &freq,int f){
    int cnt = 0;
    for(auto &p : freq){
        if (f == p.second) continue;
        else if (p.second > f){
            cnt += (p.second - f);
        }else{
            cnt += p.second;
        }
    }
    return cnt;
}

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n)cin >> a[i];
    unordered_map<int,int> freq;
    for (int i = 0; i < n; ++i) freq[a[i]]++;

    int minFreq = INT_MAX,maxFreq = INT_MIN;
    for(auto &p : freq){
        minFreq = min(minFreq,p.second);
        maxFreq = max(maxFreq,p.second);
    }

    int ans = INT_MAX;
    set<int> st;
    for(auto &p : freq) st.insert(p.second);
    for(int i : st){
        ans = min(ans,getAns(freq,i));
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
