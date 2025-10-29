class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> map;
        for(const auto& str : strs) {
            vector<int> freq(26, 0);
            for(char ch : str) {
                freq[ch - 'a']++;
            }
            string key = to_string(freq[0]);
            for(int i = 1; i < 26; i++) {
                key += ',' + to_string(freq[i]);
            }
            map[key].push_back(str);
        }
        vector<vector<string>> res;
        for(const auto& freq : map) {
            res.push_back(freq.second);
        }
        return res;
    }
};
