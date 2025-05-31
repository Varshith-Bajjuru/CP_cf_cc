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

vi sieveOfEratosthenes(int n) {
    vector<bool> isPrime(n + 1, true);
    isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    vi primes;
    for (int i = 0; i <= n; ++i) {
        if (isPrime[i]) primes.push_back(i);
    }

    return primes;
}

int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

int lcm(int a, int b) {
    return (a / __gcd(a, b)) * b;
}

void printAns(vi &a){
    cout << *max_element(all(a)) << endl;
    for (int i : a) {
        cout << i << " ";
    }
    cout << endl;
}

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    if (n%2 != 0 ){
        cout << -1 << endl;
        return;
    }
    int opened = 0,closed = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '(') opened++;
        else closed++;
    }
    if  (opened != closed){
        cout << -1 << endl;
        return;
    }else{
        vi ans(n,1);
        vi idxs;
        int o = 0;
        for (int i = 0; i < n; ++i) {
            int prev = o;
            if (s[i] == '(') o++;
            else o--;
            if (o < 0 || prev == -1)idxs.push_back(i);
        }
        for (int i : idxs) {
            ans[i] = 2;
        }
        if (*max_element(all(ans)) == *min_element(all(ans))){
            cout << 1 << endl;
            for (int i = 0; i < n; ++i) {
                cout << 1 << " ";
            }
            cout << endl;
        }else{
            printAns(ans);
        }
    }
}

int32_t main() {
    fast_io();
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}