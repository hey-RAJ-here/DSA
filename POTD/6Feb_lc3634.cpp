//Minimum Removals to Balance Array
class Solution {
public:
    int minRemoval(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int i = 0, j = 0;
        int maxLen = 1;

        while (j < n) {
            // jab condition toot jaye, i ko aage badhao
            while ((long long)nums[j] > (long long)nums[i] * k) {
                i++;
            }
            // valid window mil gaya
            maxLen = max(maxLen, j - i + 1);
            j++;
        }

        return n - maxLen;
    }
};
