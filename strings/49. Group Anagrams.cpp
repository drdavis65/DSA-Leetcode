#include <array>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> str_map;
        for(const auto &str : strs) {
            std::array<int, 26> sig{};
            for(auto ch : str) {
                sig[ch - 'a']++;
            }
            std::string key;
            std::for_each(sig.cbegin(), sig.cend(), [&key](const auto &freq){key += std::to_string(freq) + ",";});
            str_map[key].push_back(str);
        }
        std::vector<std::vector<std::string>> result;
        for(const auto &item : str_map) {
            result.push_back(item.second);
        }
        return result;
    }
};
