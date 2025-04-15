// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        std::unordered_map<int, int> seen;
        for(int i = 0; i < arr.size(); i++) {
            if(seen.find(arr[i]*2) != seen.end() ||
              (arr[i] % 2 == 0) && seen.find(arr[i] / 2) != seen.end()) {
                return true;
            }
            seen[arr[i]] = i;
        }
        return false;
    }
};
