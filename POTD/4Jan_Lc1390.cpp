class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int totalSum = 0;

        for (int n : nums) {
            int temp = n;
            vector<pair<int, int>> factors;

            for (int i = 2; i * i <= temp; i++) {
                if (temp % i == 0) {
                    int count = 0;
                    while (temp % i == 0) {
                        temp /= i;
                        count++;
                    }
                    factors.push_back({i, count});

                    // Early stopping
                    if (factors.size() > 2 || count > 3)
                        break;
                }
            }

            // Remaining prime factor
            if (temp > 1)
                factors.push_back({temp, 1});

            // Case 1: p^3
            if (factors.size() == 1 && factors[0].second == 3) {
                int p = factors[0].first;
                totalSum += 1 + p + p*p + p*p*p;
            }
            // Case 2: p * q
            else if (factors.size() == 2 &&
                     factors[0].second == 1 &&
                     factors[1].second == 1) {
                int p = factors[0].first;
                int q = factors[1].first;
                totalSum += 1 + p + q + p*q;
            }
        }

        return totalSum;
    }
};
