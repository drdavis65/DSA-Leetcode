class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;
        std::set<int> c;
        size_t i = 0;
        int max = 0;
        for(size_t j{0}; j < s.size(); j++) {
            if (c.find(s[j]) == c.end()) {
                c.insert(s[j]);
            }
            else {
                while(s[i] != s[j]) {
                    c.erase(s[i]);
                    i++;
                }
                i++;
            }
            int len = j - i + 1;
            max = len > max ? len : max;
        }
        return max;
    }
};
