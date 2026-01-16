void countingSort(vector<int>& arr) {
  if(arr.empty()) return;
  int minVal = *std::min_element(arr.begin(), arr.end());
  int maxVal = *std::max_element(arr.begin(), arr.end());
  int range = maxVal - minVal + 1;
  vector<int> counts(range, 0);
  for(int i = 0; i < arr.size(); i++) {
    counts[arr[i]-minVal]++;
  }
  int i = 0;
  for(int n = 0; n < range; n++) {
    for(int j = 0; j < counts[n]; j++) {
      arr[i++] = n + minVal;
    }
  }
  return;
}
