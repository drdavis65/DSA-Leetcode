class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i+1 < n && arr[i] < arr[i+1])
            i++;
            
        if(i == 0 || i == n-1) return false;
        
        while(i+1 < n && arr[i] > arr[i+1])
            i++;

        return i == n - 1;
    }
};

// INITIAL SOLUTION
// class Solution {
// public:
//     bool validMountainArray(vector<int>& arr) {
//         int decIdx = 0;
//         for(int i = 1; i < arr.size(); i++) {
//             if(arr[i] < arr[i-1]) {
//                 decIdx = i-1;
//                 break;
//             }
//             if(arr[i] == arr[i-1]) return false;
//         }
//         if(decIdx == 0) return false;
        
//         for(int i = decIdx+1; i < arr.size(); i++) {
//             if(arr[i] > arr[i-1] || arr[i] == arr[i-1]) return false;
//         }
//         return true;
//     }
// };
