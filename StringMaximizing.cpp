#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t = 0;
    cin >> t;
    while (t-->0){
        string str;
        cin >> str;
        vector<int> digits(str.size());
        for (int i = 0; i < str.size(); ++i) {
            digits[i] = str[i] - '0';
        } 

        for (int i = 1; i < str.size(); ++i) {
            int copy = i;
            while (copy >= 1 && digits[copy] > digits[copy - 1] + 1 && digits[copy] > 0){
                int temp = digits[copy];
                digits[copy] = digits[copy - 1];
                digits[copy - 1] = temp - 1;
                if (copy > 1){
                    copy--;
                } else break;
            }
        }
        string ans = "";
        for (int i : digits) {
            ans += to_string(i);
        }
        cout << ans << endl;
    }
    return 0;
}
