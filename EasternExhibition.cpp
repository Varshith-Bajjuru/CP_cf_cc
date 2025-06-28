#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
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
    int n;
    cin>>n;
    vector<ll>x(n);
    vector<ll>y(n);
    for(int i=0;i<n;i++){
        cin>>x[i]>>y[i];
    }
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    if(n%2==1) cout<<1<<"\n";
    else{
        ll ans=(x[n/2]-x[n/2 - 1]+1)*(y[n/2]-y[n/2 -1]+1);
        cout<<ans<<"\n";
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
