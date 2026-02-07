//Max sum in the configuration


class Solution {
public:
    int maxSum(vector<int>& arr) {
        int n = arr.size();

        vector<int> sample = arr;
        sample.insert(sample.end(), arr.begin(), arr.end());

        int sum = 0, prdSum = 0;
        for (int i = 0; i < n; i++) {
            sum += arr[i];
            prdSum += i * arr[i];
        }

        int ans = prdSum;

        int l = 1, r = n;
        while (r < 2 * n) {

            
            prdSum = prdSum - (sum - sample[l - 1]) 
                     + sample[l - 1] * (n - 1);

            ans = max(ans, prdSum);

            sum = sum - sample[l - 1] + sample[r];
            l++;
            r++;
        }

        return ans;
    }
};
