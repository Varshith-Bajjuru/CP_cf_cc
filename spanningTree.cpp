#include <bits/stdc++.h>
#include "set"
#include <cmath>
#include "unordered_map"
#include "algorithm"
using namespace std;

#define int long long
#define fast_io() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define vi vector<int>
#define pii pair<int, int>
#define all(v) (v).begin(), (v).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n';

int MOD = 998244353;

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

bool isPowerOf2(int n) {
    return (n > 0) && ((n & (n - 1)) == 0);
}

int digits(int n){
    int cnt = 0;
    while (n != 0){
        n = n/10;
        cnt++;
    }
    return cnt;
}

int power(int a, int b){
    if (b == 0) return 1;
    int x  = power(a, b/2);
    if (b % 2 == 0){
        return x * x;
    } else{
        return x * x * a;
    }
}

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    }
    return true;
}

int powermod(int x, int y, int p) {
    int res = 1;
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

int bitCount(int num) {
    return num ? (int) log2(num) + 1 : 0;
}

void solve() {
    int n , m;
    cin >> n >> m;
    map<int,vector<int>> list;
    for (int i = 0; i < m; ++i) {
        int a,b;
        cin >> a >> b;
        list[a].push_back(b);
        list[b].push_back(a);
    }
    int maxDegree = 0,maxEle = 0;
    for(auto &p : list){
        if (p.second.size() > maxDegree){
            maxDegree = (int)p.second.size();
            maxEle = p.first;
        }
    }

    vector<pii> ans;
    set<int> visited;
    queue<int> q;
    for (int i : list[maxEle]) {
        q.push(i);
        visited.insert(i);
        ans.emplace_back(maxEle,i);
    }
    visited.insert(maxEle);

    while (!q.empty()){
        int x = q.front();
        for (int i = 0; i < list[x].size(); ++i) {
            if (visited.count(list[x][i]) == 0){
                q.push(list[x][i]);
                visited.insert(list[x][i]);
                ans.emplace_back(x,list[x][i]);
            }
        }
        q.pop();
    }

    for (auto & an : ans) {
        cout << an.first << " " << an.second << endl;
    }
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