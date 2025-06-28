#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
#define INF(t) numeric_limits<t>::max()

int n;

ll rect(int mn_x, int mx_x, int mn_y, int mx_y) {
    ll h = mx_x - mn_x + 1, w = mx_y - mn_y + 1;
    if(h*w < n) return min((h+1)*w, h*(w+1));
    return h*w;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);

    int tc; cin >> tc;
    while(tc--) {
        cin >> n;
        vector<pair<int,int>> x(n), y(n);

        for(int i = 0; i < n; i++) {
            cin >> x[i].first >> y[i].first;
            x[i].second = y[i].second = i;
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        ll ans = rect(x[0].first, x[n-1].first, y[0].first, y[n-1].first);

        if(n == 1) {
            cout << ans << "\n";
            continue;
        }

        set<int> ii = {x[0].second,x[n-1].second, y[0].second, y[n-1].second};
        for (int i : ii) {
            int mnx = x[0].second == i ? x[1].first : x[0].first;
            int mxx = x[n-1].second == i ? x[n-2].first : x[n-1].first;
            int mny = y[0].second == i ? y[1].first : y[0].first;
            int mxy = y[n-1].second == i ? y[n-2].first : y[n-1].first;
            ans = min(ans, rect(mnx, mxx, mny, mxy));
        }

        cout << ans << "\n";
    }

    return 0;
}