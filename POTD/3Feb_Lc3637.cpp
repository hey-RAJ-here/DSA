//Trionic Array I
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if (n < 3)
            return false;

        bool first = true;  // Phase 1: Increasing
        bool second = true; // Phase 2: Decreasing
        bool third = true;  // Phase 3: Increasing

        vector<int> ans;
        ans.push_back(nums[0]);

        // We use counters to ensure each segment actually exists
        int c1 = 0, c2 = 0, c3 = 0;

        for (int i = 1; i < n; i++) {
            if (first && second && third) {
                if (nums[i - 1] < nums[i]) {
                    ans.push_back(nums[i]);
                    c1++;
                } else if (nums[i - 1] > nums[i] && c1 > 0) {
                    // Transition to Phase 2 (Decreasing)
                    first = false;
                    ans.push_back(nums[i]);
                    c2++;
                } else {
                    break; // Invalid start or equal elements
                }
            } else if (first == false && second && third) {
                if (nums[i - 1] > nums[i]) {
                    ans.push_back(nums[i]);
                    c2++;
                } else if (nums[i - 1] < nums[i] && c2 > 0) {
                    // Transition to Phase 3 (Increasing)
                    second = false;
                    ans.push_back(nums[i]);
                    c3++;
                } else {
                    break;
                }
            } else if (first == false && second == false && third) {
                if (nums[i - 1] < nums[i]) {
                    ans.push_back(nums[i]);
                    c3++;
                } else {
                    break;
                }
            }
        }

        // Return true only if we processed every element AND finished in Phase
        // 3
        return (ans.size() == n && !first && !second && c3 > 0);
    }
};