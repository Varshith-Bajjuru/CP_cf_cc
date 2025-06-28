#include <bits/stdc++.h>
using namespace std;

#define int long long

void fast_io() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}

int32_t main() {
    fast_io();

    int test_cases;
    cin >> test_cases;

    while (test_cases--) {
        int num_nodes;
        cin >> num_nodes;

        vector<vector<int>> adjacency_list(num_nodes + 1);

        for (int i = 0; i < num_nodes - 1; ++i) {
            int u, v;
            cin >> u >> v;
            adjacency_list[u].push_back(v);
            adjacency_list[v].push_back(u);
        }

        vector<array<int, 3>> diameters_info;
        vector<int> is_visited(num_nodes + 1, 0);
        vector<int> parent(num_nodes + 1);
        int total_processed = 0;

        auto dfs = [&](auto self, int node, int par) -> pair<int, int> {
            pair<int, int> deepest = {1, node};
            parent[node] = par;

            for (int neighbor : adjacency_list[node]) {
                if (neighbor == par || is_visited[neighbor])
                    continue;

                auto res = self(self, neighbor, node);
                res.first += 1;

                if (res > deepest)
                    deepest = res;
            }

            return deepest;
        };

        while (total_processed < num_nodes) {
            for (int node = 1; node <= num_nodes; ++node) {
                if (is_visited[node]) continue;

                auto [depth1, far_node1] = dfs(dfs, node, -1);
                auto [diameter_length, far_node2] = dfs(dfs, far_node1, -1);

                diameters_info.push_back({diameter_length, max(far_node1, far_node2), min(far_node1, far_node2)});

                while (far_node2 != -1) {
                    is_visited[far_node2] = 1;
                    far_node2 = parent[far_node2];
                    total_processed++;
                }
            }
        }
        sort(diameters_info.begin(), diameters_info.end(), greater<>());

        for (auto triplet : diameters_info) {
            cout << triplet[0] << " " << triplet[1] << " " << triplet[2] << " ";
        }
        cout << '\n';
    }

    return 0;
}
