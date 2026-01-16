// Maximum Square Area by Removing Fences From a Field
class Solution {
public:
    int maximizeSquareArea(int m, int n,
                           vector<int>& hFences,
                           vector<int>& vFences) {

        const int MOD = 1e9 + 7;

        // Add boundaries
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        unordered_set<int> hGaps;

        // All horizontal gaps
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hGaps.insert(hFences[j] - hFences[i]);
            }
        }

        long long best = -1;

        // Check vertical gaps
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                int gap = vFences[j] - vFences[i];
                if (hGaps.count(gap)) {
                    best = max(best, (long long)gap);
                }
            }
        }

        if (best == -1) return -1;
        return (best * best) % MOD;
    }
};
