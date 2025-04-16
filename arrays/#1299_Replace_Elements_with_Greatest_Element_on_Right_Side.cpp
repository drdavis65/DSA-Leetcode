class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        int max = arr[n-1];
        for(int i = n-1; i >= 0; i--) {
            if(max > arr[i]) {
                arr[i] = max;
            } else {
                int temp = arr[i];
                arr[i] = max;
                max = temp;
            }
        }
        arr[n-1] = -1;
        return arr;
    }
};
