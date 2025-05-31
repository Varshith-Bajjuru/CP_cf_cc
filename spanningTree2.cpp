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

map<int,vi> adj;
map<int,vi> newGraph;
set<int> vis;

void dfs(int node){
    vis.insert(node);
    for(auto child : adj[node]){
        if (vis.count(child) == 0){
            dfs(child);
        }
    }
}

void bfs(int node){
    queue<int> q;
    vis.insert(node);
    q.push(node);

    while (!q.empty()){
        int x = q.front();
        for (int i = 0; i < adj[x].size(); ++i) {
            if (vis.count(adj[x][i]) != 0){
                newGraph[x].push_back(adj[x][i]);
                newGraph[adj[x][i]].push_back(x);
                vis.insert(adj[x][i]);
                if (adj[x][i] != 1){
                    q.push(adj[x][i]);
                }
            }
        }
        q.pop();
    }
}

void newBfs(int node){

}

void solve() {
    int n , m , d;
    cin >> n >> m >> d;
    while (m--){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int maxDegree = INT_MIN,minCC = INT_MAX;
    for(auto &p : adj){
        maxDegree = max(maxDegree,(int)p.second.size());
    }

    for(auto &p : adj){
        if (vis.count(p.first) == 0){
            dfs(p.first);
            minCC++;
        }
    }

    if (d < minCC || d > maxDegree ){
        cout << "No" << endl;
        return;
    }

    for(auto &p : adj){
        if (vis.count(p.first) == 0){
            bfs(p.first);
        }
    }

    vector<pii> ans;
    vis.clear();

    cout << "Yes" << endl;
    newBfs(1);
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