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
#define py cout << "YES" << endl
#define pn cout << "NO" << endl

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

//bool palindrome(const string &s){
//    int left = 0,right = s.size()-1;
//    while (left <= right){
//        if (s[left] != s[right]){
//            return false;
//        }
//        left++;
//        right--;
//    }
//    return true;
//}

int check(const string& s,char c){
    int left = 0,right = s.size()-1;
    int ans = 0;
    while (left <= right){
        if (s[left] == s[right]){
            left++;
            right--;
        }
        else if(s[left] == c){
            left++;
            ans++;
        }
        else if (s[right] == c){
            right--;
            ans++;
        }
        else {
            return INT_MAX;
        }
    }
    return ans;
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    set<char> st;
    for (int i = 0; i < n; ++i) {
        st.insert(s[i]);
    }
    int ans = INT_MAX;
    for (char it : st) {
        ans = min(ans,check(s,it));
    }

    cout << (ans == INT_MAX ? -1 : ans) << endl;
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
