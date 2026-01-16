// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    void insertionSort(vector<int>& arr) {
        for(int i = 0; i < arr.size(); i++) {
            int j = i - 1;
            while(j >= 0 && arr[j+1] < arr[j]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                j--;
            }
        }
        return;
    }
};
