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

void print(vector<pair<int,int>> &v){
    cout << v.size() << endl;
    for(auto p : v){
        cout << p.first << " " << p.second << endl;
    }
}

vector<pair<int,int>> partition(vector<int> &v,int idx){
    vector<int> a = v;
    vi v1,v2;
    for (int i = 0; i <= idx; ++i) {
        while (a[i] != 0){
            v1.push_back(i+1);
            a[i]--;
        }
    }
    for (int i = idx+1; i < a.size(); ++i) {
        while (a[i] != 0){
            v2.push_back(i+1);
            a[i]--;
        }
    }
    vector<pair<int,int>> ans;
    for (int i = 0; i < min(v1.size(),v2.size()); ++i) {
        ans.emplace_back(v1[i] ,v2[i]);
    }
    return ans;
}

void solve(){
    int n;cin >> n;
    vi a(n);rep(i,0,n) cin >> a[i];
    vi v;
    for (int i = 0; i < n; ++i) {
        while (a[i] > 0){
            v.push_back(i+1);
            a[i]--;
        }
    }

    vector<pair<int,int>> ans;
    int i = 0,j = (int)v.size()/2;
    while (j < v.size() && i < v.size()/2){
        if (v[i] != v[j]){
            ans.emplace_back(v[i],v[j]);
            i++,j++;
        }else{
            while (v[i] == v[j] && j < v.size()){
                j++;
            }
        }
    }
    print(ans);
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