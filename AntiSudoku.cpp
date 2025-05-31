#include <iostream>
using namespace std;

void solve() {
    char grid[9][9];
    for (auto & i : grid) {
        string s;
        cin >> s;
        for (int j = 0; j < 9; ++j) {
            i[j] = s[j];
        }
    }
    int change_coords[9][2] = {
            {0, 0}, {1, 3}, {2, 6},
            {3, 1}, {4, 4}, {5, 7},
            {6, 2}, {7, 5}, {8, 8}
    };
    for (auto & change_coord : change_coords) {
        int i = change_coord[0];
        int j = change_coord[1];
        grid[i][j] = (grid[i][j] == '1') ? '2' : '1';
    }
    for (auto & i : grid) {
        for (char j : i) {
            cout << j;
        }
        cout << '\n';
    }
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
