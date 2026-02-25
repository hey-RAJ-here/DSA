//Longest Subarray with Majority Greater than K

class Solution {
public:
    int longestSubarray(vector<int>& arr, int k) {
        
        int n = arr.size();
        
        // Step 1: Convert into +1 / -1 and compute prefix sum on the fly
        int prefix = 0;
        int maxLen = 0;
        
        unordered_map<int, int> firstIndex;
        
        for(int i = 0; i < n; i++) {
            
            // Convert element
            if(arr[i] > k)
                prefix += 1;
            else
                prefix -= 1;
            
            // Case 1: If prefix > 0, whole subarray (0 → i) is valid
            if(prefix > 0) {
                maxLen = i + 1;
            }
            
            // Store first occurrence of prefix
            if(firstIndex.find(prefix) == firstIndex.end()) {
                firstIndex[prefix] = i;
            }
            
            // Case 2:
            // If there exists prefix-1 earlier,
            // then subarray between that index+1 and i has positive sum
            if(firstIndex.find(prefix - 1) != firstIndex.end()) {
                maxLen = max(maxLen, i - firstIndex[prefix - 1]);
            }
        }
        
        return maxLen;
    }
};