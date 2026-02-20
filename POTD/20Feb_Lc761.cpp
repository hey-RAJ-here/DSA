//Special Binary String
// Level Hard
class Solution {
public:
    string makeLargestSpecial(string s) {
        vector<string> blocks;
        int count = 0;
        int start = 0;

        // Step 1: Split into top-level special substrings
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') count++;
            else count--;

            // When count becomes 0 → one complete special block
            if (count == 0) {
                // Recursively solve inside part
                string inside = s.substr(start + 1, i - start - 1);
                string processed = makeLargestSpecial(inside);

                // Wrap it again with outer 1 and 0
                blocks.push_back("1" + processed + "0");

                start = i + 1;
            }
        }

        // Step 2: Sort in descending lexicographical order
        sort(blocks.begin(), blocks.end(), greater<string>());

        // Step 3: Join all blocks
        string result = "";
        for (string &block : blocks) {
            result += block;
        }

        return result;
    }
};