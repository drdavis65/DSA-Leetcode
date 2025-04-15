


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        std::queue<int> q;
        for(auto num : arr) {
            if(num != 0) { 
                q.push(num);
            }else {
                q.push(num);
                q.push(0);
            }
        }
        for(int i = 0; i < arr.size(); i++) {
            arr[i] = q.front();
            q.pop();
        }
        
    }
};
