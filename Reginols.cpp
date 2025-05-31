#include <bits/stdc++.h>
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;

int main() {
    int t;
    scanf("%d", &t);
    forn(_, t) {
        int n;
        scanf("%d", &n);

        vector<int> s(n), u(n);
        forn(i, n) {
            scanf("%d", &s[i]);
            --s[i]; // 0-based indexing
        }
        forn(i, n) {
            scanf("%d", &u[i]);
        }

        vector<vector<int>> bst(n);
        forn(i, n) {
            bst[s[i]].push_back(u[i]);
        }

        // Sort each university's skill list in decreasing order
        forn(i, n) {
            sort(bst[i].begin(), bst[i].end(), greater<int>());
        }

        // Build prefix sums
        vector<vector<long long>> pr(n);
        forn(i, n) {
            pr[i].push_back(0);
            for (int x : bst[i]) {
                pr[i].push_back(pr[i].back() + x);
            }
        }

        // Result array
        vector<long long> ans(n, 0);
        forn(i, n) {
            int sz = bst[i].size();
            for (int k = 1; k <= sz; ++k) {
                int full = (sz / k) * k;
                ans[k - 1] += pr[i][full];
            }
        }

        forn(i, n) {
            printf("%lld ", ans[i]);
        }
        puts("");
    }
    return 0;
}
