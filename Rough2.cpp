#include <bits/stdc++.h>
#include<vector>
#include <set>
#include <algorithm>
#include <cmath>
#include <unordered_map>
using namespace std;

#define int long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define pii pair<int, int>
#define vii vector<pii>
#define mii map<int, int>
#define pb push_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ff first
#define ss second
#define endl '\n'
#define f(i,a,b) for(int i = a;i < b;i++)

const int MOD = 1e9 + 7;
const int INF = 1e18;

void fast_io() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

// GCD & LCM
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }

// Modular Exponentiation (a^b % mod)
int mod_exp(int a, int b, int mod = MOD) {
    int res = 1;
    while (b) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

// Prime Check
bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

// Sieve of Eratosthenes
vi sieve(int n) {
    vector<bool> prime(n + 1, true);
    vi primes;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            primes.pb(i);
            for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
    }
    return primes;
}

// Binary Search
int binary_search(vi &arr, int x) {
    int l = 0, r = arr.size() - 1;
    while (l <= r) {
        int mid = (l + r) / 2;
        if (arr[mid] == x) return mid;
        else if (arr[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}

// BFS (Breadth-First Search)
void bfs(int start, vvi &adj, vi &dist) {
    queue<int> q;
    q.push(start);
    dist[start] = 0;
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int neighbor : adj[node]) {
            if (dist[neighbor] == -1) {
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
}

// DFS (Depth-First Search)
void dfs(int node, vvi &adj, vi &visited) {
    visited[node] = 1;
    for (int neighbor : adj[node])
        if (!visited[neighbor])
            dfs(neighbor, adj, visited);
}

// Dijkstra’s Algorithm (Shortest Path)
vi dijkstra(int src, int n, vector<vii> &adj) {
    vi dist(n, INF);
    priority_queue<pii, vii, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dist[u]) continue;
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}
void sieveOfHypo(int n, vector<int>& primes) {
    vector<int> cnt(n + 1, 1);
    cnt[0] = 0;
    cnt[1] = 0;
    for (int i = 2; i * i <= n; ++i) {
        if (cnt[i] == 1) {
            for (int j = i * i; j <= n; j += i) {
                cnt[j] = 0;
            }
        }
    }
    for (int i = 0; i <= n; ++i) {
        if (cnt[i] == 1) {
            primes.push_back(i);
        }
    }
}

int helper(int i, vector<int>& primes, int sum) {
    if (sum == 0) return 0;
    if (i >= primes.size() || sum < 0) return INT_MAX / 2;

    int pick = INT_MAX / 2;
    if (primes[i] <= sum) {
        pick = 1 + helper(i, primes, sum - primes[i]);
    }
    int notPick = helper(i + 1, primes, sum);

    return min(pick, notPick);
}

//void solve() {
//    int n,k,p;
//    cin >> n >> k >> p;
//    if (k < 0){
//        k = (-k);
//    }
//    if (k == 0){
//        cout << 0 << endl;
//        return;
//    }
//    if (k <= p){
//        cout << 1 << endl;
//        return;
//    }
//    if (k % p == 0){
//        if (k/p <= n){
//            cout << k/p << endl;
//            return;
//        }
//        cout << -1 << endl;
//    }else{
//        if(k/p < n){
//            cout << k/p+1 << endl;
//            return;
//        }
//        cout << -1 << endl;
//    }
//}

//void solve(){
//    int n;
//    cin >> n;
//    string s;
//    cin >> s;
//    int bgs = 0,sms = 0;
//    for (int i = 0; i < s.size(); ++i) {
//        if (s[i] == '_') bgs++;
//        else sms++;
//    }
//    if(sms < 2 || bgs == 0){
//        cout << 0 << endl;
//        return;
//    }
//    if(sms % 2 == 0){
//        cout << (sms/2)*bgs*(sms/2) << endl;
//        return;
//    }else{
//        cout << (sms/2)*bgs*(sms/2 + 1) << endl;
//        return;
//    }
//}

//void solve(){
//    int n,x;
//    cin >> n >> x;
//    if (n == 1){
//        cout << x << endl;
//        return;
//    }
//    {
//        int o = 0;
//        for (int i = 0; i < n; ++i) {
//            o |= i;
//        }
//        if (o == x){
//            for (int i = 0; i < n; ++i) {
//                cout << i << " ";
//            }
//            cout << endl;
//            return;
//        }
//    }
//    {
//        vector<int> ans;
//        for (int i = 0; i < n-1; ++i) {
//            if ((i|x) == x){
//                ans.push_back(i);
//            }
//        }
//        while (ans.size() != n){
//            ans.push_back(x);
//        }
//        for (int i = 0; i < n; ++i) {
//            cout << ans[i] << " ";
//        }
//        cout << endl;
//    }
//}

[[noreturn]] void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    int l = 0;
    int r = 0;
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int cnt = 0;
        for (int j = i+1; j < n; ++j) {
            if (a[i] > a[j]){
                cnt ++;
            }
            if (a[i] < a[j]){
                cnt --;
            }
            if (cnt > ans){
                l = i;
                r = j;
                ans = cnt;
            }
        }
    }

    cout << l+1 << " " << r+1 << endl;
}

int32_t main() {
    fast_io();
    int t = 1;
    cin>>t;
    while (t--){
        solve();
    }
    return 0;
}