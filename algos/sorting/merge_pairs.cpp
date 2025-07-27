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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        mergeSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }
    void mergeSortHelper(vector<Pair>& pairs, int s, int e) {
        if(e - s + 1 <= 1) {
            return;
        }
        int m = (s + e) / 2;
        mergeSortHelper(pairs, s, m);
        mergeSortHelper(pairs, m+1, e);
        merge(pairs, s, m, e);
        return;
    }
    void merge(vector<Pair>& pairs, int s, int m, int e) {
        vector<Pair> left(pairs.begin() + s, pairs.begin() + m + 1);
        vector<Pair> right(pairs.begin() + m + 1, pairs.begin() + e + 1);
        int i = 0;
        int j = 0;
        int k = s;
        while(i < left.size() && j < right.size()) {
            if(left[i].key <= right[j].key) {
                pairs[k++] = left[i];
                i++;
            }
            else {
                pairs[k++] = right[j];
                j++;
            }
        }
        while(i < left.size()) {
            pairs[k++] = left[i++];
        }
        while(j < right.size()) {
            pairs[k++] = right[j++];
        }
        return;
    }
};
