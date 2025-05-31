#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

#define fastio() ios::sync_with_stdio(0); cin.tie(0);
#define ll long long
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)(x).size()

[[noreturn]] void solve() {
    string s;
    cin >> s;
    ll ones = count(all(s), '1');
    ll zeros = s.length() - ones;
    int i;
    for ( i = 0; i < s.length(); ++i) {
        if (s[i] == '1'){
            if (zeros > 0){
                zeros-- ;
            } else break;
        } else{
            if (ones > 0){
                ones --;
            } else{
                break;
            }
        }
    }
    cout << s.length() - i << endl;
}

int main() {
    fastio();
    int t;
    cin >> t;
    while (t--) solve();
    return 0;
}
