#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 998244353;

struct DSU{
    int n;
    vi p;
    DSU(int N){
        n = N;
        p.resize(n+1);
        for (int i = 0; i <= n; ++i) {
            p[i] = i;
        }
    }

    int find(int i){
        return p[i] == i ? i : p[i] = find(p[i]);
    }

    void merge(int a,int b){
        a = find(a);b = find(b);
        if (a != b){
            p[b] = a;
        }
    }
};

void solve(){
    int n,m1,m2;cin >> n >> m1 >> m2;
    DSU dsu1(n),dsu2(n);
    while (m1--){
        int u,v;cin >> u >> v;
        dsu1.merge(u,v);
    }
    while(m2--){
        int u,v;cin >> u >> v;
        dsu2.merge(u,v);
    }
    vector<pair<int ,int>> ans;

    for (int i = 2; i <= n; ++i) {
        if (dsu1.find(i) != dsu1.find(1) and dsu2.find(i) != dsu2.find(1)){
            ans.emplace_back(1,i);
            dsu1.merge(1,i);
            dsu2.merge(1,i);
        }
    }

    int ptr1 = 1,ptr2 = 1;
    while (ptr1 <= n && ptr2 <= n){
        while (ptr1 <= n && dsu1.find(ptr1) == dsu1.find(1)) ptr1++;
        while (ptr2 <= n && dsu2.find(ptr2) == dsu2.find(1)) ptr2++;

        if (ptr1 > n or ptr2 > n) break;

        ans.emplace_back(ptr1,ptr2);
        dsu1.merge(ptr1,ptr2);
        dsu2.merge(ptr1,ptr2);
        ptr1++,ptr2++;
    }

    cout << ans.size() << endl;
    for (auto it : ans) {
        cout << it.first << " " << it.second << "\n";
    }
    cout << endl;
}

int32_t main() {
    fast_io();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}