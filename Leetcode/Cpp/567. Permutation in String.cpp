class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size() > s2.size()) return false;
        char sig1[26] = {0};
        char sig2[26] = {0};
        for(auto ch : s1) {
            sig1[ch - 'a'] += 1;
        }
        auto r{0z};
        while (r < s1.size() - 1) {
            sig2[s2[r] - 'a'] += 1;
            r++;
        }
        auto l{0z};
        while (r < s2.size()) {
            sig2[s2[r++] - 'a'] += 1;
            if(check_equiv(sig1, sig2))
                return true;
            sig2[s2[l++] - 'a'] -= 1;
        }
        return false;
    }
private:
    bool check_equiv(char sig1[26], char sig2[26]) {
        for(int i{0}; i < 26; i++) {
            if(sig1[i] != sig2[i])
                return false;
        }
        return true;
    }
};
