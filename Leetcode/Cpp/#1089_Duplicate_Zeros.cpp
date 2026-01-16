// Date last reviewed:
// 4/15/2025
// ==================================================
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size();
        int i;
        int count = 0;
        for(i = 0; i < n; i++) {
            count++;
            if(arr[i] == 0) {
                count++;
            }
            if(count >= n) break;
        }
        int k = n - 1;
        // The only case where count > n is when 0 is the last element
        if(count > n) { 
            arr[k--] = 0;
            i--;
        }

        for(int j = i; j >= 0; j--) {
            if(arr[j] == 0) {
                arr[k--] = 0;
                arr[k--] = 0;
            } else {
                arr[k--] = arr[j];
            }
        }
    }
};

// SOLUTION USING QUEUE (EXTRA SPACE)
// class Solution {
// public:
//     void duplicateZeros(vector<int>& arr) {
//         std::queue<int> q;
//         for(auto num : arr) {
//             if(num != 0) { 
//                 q.push(num);
//             }else {
//                 q.push(num);
//                 q.push(0);
//             }
//         }
//         for(int i = 0; i < arr.size(); i++) {
//             arr[i] = q.front();
//             q.pop();
//         }
        
//     }
// };
