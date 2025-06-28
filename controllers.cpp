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

void solve(){
    int n;cin >> n;
    string s;cin >> s;
    int pluses = 0,minuses = 0;
    for (int i = 0; i < n; ++i) {
        if (s[i] == '+') pluses++;
        else minuses++;
    }
    int c;cin >> c;
    while (c--){
        int a,b;cin >> a >> b;
        if (a < b) swap(a,b);
        if (pluses == minuses){
            cout << "Yes" << endl;
            continue;
        }

        auto f = [&](auto &&f,int mid){
            int ans = 0;
            if (mid == pluses){
                ans += pluses*a - minuses*b;
            }
            else if (mid > pluses){
                ans += (pluses*a - (mid-pluses)*a);
                ans -= (n-mid)*b;
            }else{
                ans += mid*a;
                ans += (pluses - mid)*b;
                ans -= (n-mid)*b;
            }
            return ans;
        };
        bool ok = false;

        int l = 0,r = n;
        while (l <= r){
            int mid = l + (r-l)/2;
            int val = f(f,mid);
            if (val == 0){
                cout << "Yes" << endl;
                ok = true;
                break;
            }

            if (val < 0){
                if (mid < pluses){
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }else{
                if (mid < pluses){
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            cout << val << endl;
        }
        if (!ok){
            swap(a,b);
            int low = 0,high = n;
            while (low <= high){
                int mid = low + (high-low)/2;
                int val = f(f,mid);
                if (val == 0){
                    cout << "Yes" << endl;
                    ok = true;
                    break;
                }
                if (val < 0){
                    if (mid < pluses){
                        high = mid-1;
                    }else{
                        low = mid+1;
                    }
                }else{
                    if (mid < pluses){
                        low = mid+1;
                    }else{
                        high = mid-1;
                    }
                }
                cout << val << endl;
            }
        }
        if (!ok){
            cout << "No" << endl;
        }
    }
}

int32_t main() {
    setIO();
    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
