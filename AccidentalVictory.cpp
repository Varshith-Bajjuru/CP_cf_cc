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

bool canDo(int idx,vector<pair<int,int>> &v){
    int sum = 0;
    for (int i = 0; i <= idx; ++i) {
        sum += v[i].first;
    }

    bool canBeDone = true;
    for (int i = idx+1; i < v.size(); ++i) {
        if (v[i].first > sum){
            canBeDone = false;
            break;
        }else{
            sum += v[i].first;
        }
    }

    return canBeDone;
}

void solve(){
    int n;cin >> n;
    int sum = 0;
    vi a(n);rep(i,0,n){
        cin >> a[i];
        sum += a[i];
    }
    bool allSame = true;
    for (int i = 0; i < n; ++i) {
        if (a[i] != a[0]){
            allSame = false;
            break;
        }
    }
    if (allSame){
        cout << n << endl;
        for (int i = 1; i <= n; ++i) {
            cout << i << " ";
        }
        cout << endl;
        return;
    }else{
        vector<pair<int,int>> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = {a[i],i};
        }
        sort(all(v));
        int idx = n;
        int left = 0,right = n-1;
        while (left <= right){
            int mid = left + (right - left)/2;
            if (canDo(mid,v)){
                idx = mid;
                right = mid-1;
            }else{
                left = mid+1;
            }
        }
        vi ans;
        for (int i = idx; i < n; ++i) {
            ans.push_back(v[i].second);
        }
        cout << ans.size() << endl;
        sort(all(ans));
        for(int i : ans){
            cout << i+1 << " ";
        }
        cout << endl;
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
