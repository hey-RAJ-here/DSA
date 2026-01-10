//leetcode Qno-66: Plus One


#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;                 // number of digits

    vector<int> digits(n);
    for (int i = 0; i < n; i++) {
        cin >> digits[i];
    }

    int carry = 1;            // we want to add 1
    vector<int> ans;

    for (int i = n - 1; i >= 0; i--) {
        if (carry == 0) {
            ans.push_back(digits[i]);
        } else {
            if (digits[i] == 9) {
                ans.push_back(0);
                carry = 1;
            } else {
                ans.push_back(digits[i] + 1);
                carry = 0;
            }
        }
    }

    if (carry == 1) {
        ans.push_back(1);
    }

    reverse(ans.begin(), ans.end());

    for (int x : ans) {
        cout << x << " ";
    }
    cout << "\n";

    return 0;
}
