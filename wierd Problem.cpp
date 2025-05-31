#include <iostream>
using namespace std;

int main() {
    long long t;
    cin >> t;
    while (t-- > 0) {
        long long n, k, x;
        cin >> n >> k >> x;

        long long minSum = k * (k + 1) / 2;
        long long maxSum = (n * (n + 1)) / 2 - ((n - k) * (n - k + 1)) / 2;

        if (x >= minSum && x <= maxSum) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
    return 0;
}
