//The k-th Lexicographical String of All Happy Strings of Length n
class Solution {
public:
    void MagicSet(int n, string s, vector<string>& sett) {

        if (s.length() == n) {
            sett.push_back(s);
            return;
        }
        char prev = '#';
        if (s.length() != 0) {
            prev = s.back();
        }
        for (char c : {'a', 'b', 'c'}) {
            if (c != prev) {
                MagicSet(n, s + c, sett);
            }
        }
        // MagicSet(n,s+'a',sett);
        // MagicSet(n,s+'b',sett);
        // MagicSet(n,s+'c',sett);
    }
    string getHappyString(int n, int k) {

        string s = "";
        vector<string> ansSet;
        MagicSet(n, s, ansSet);
        // sort(ansSet.begin(),ansSet.end());
        if (k > ansSet.size())
            return "";
        return ansSet[k - 1];
    }
};