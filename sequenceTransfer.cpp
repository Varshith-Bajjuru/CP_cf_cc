#include <bits/stdc++.h>
#include "set"
#include "unordered_map"
#include "algorithm"
using namespace std;

#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ll long long
#define vi vector<int>
#define vll vector<ll>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

ll MOD = 1e9+7;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(ll n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(ll n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

ll power(int a,int b){
    if (b == 0) return 1;
    ll x  = power(a,b/2);
    if (b%2 == 0){
        return x*x;
    } else{
        return x*x*a;
    }
}

ll powermod(ll x, ll y, ll p) {
    ll res = 1;
    x = x % p;
    if (x == 0) return 0;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve(){
    int n;
    cin>>n;
    vector<int>a(n);
    map<int,vector<int>>mp;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        mp[x].push_back(i);
    }
    if(n==1){
        cout<<0<<"\n";
        return;
    }
    int len=2e5+2;
    for(auto i : mp){
        int ok=0;
        if((int)i.second.size()==1){
            if(i.second[0]==0 || i.second[0]==n-1)
                len=min(len,1);
            else
                len=min(len,2);
            continue;
        }
        for(int j=0;j<(int)i.second.size();j++){
            if(j==0){
                if(i.second[j]>=1)
                    ok++;
                continue;
            }
            if(j==(int)i.second.size()-1){
                if(i.second[j]<(n-1))
                    ok++;
            }
            if(i.second[j]-i.second[j-1]>1)
                ok++;
        }
        len=min(len,ok);
    }
    cout<<len<<"\n";
}


int main() {
    fast_io();
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}