int rob(int* nums, int numsSize) {
    if(numsSize < 2) return nums[0];
    int num = nums[0] > nums[1] ? nums[0] : nums[1];
    int money[] = {nums[0], num};
    int i, j, k;
    for(i = 2; i < numsSize; i++) {
        j = (i-1)&1;
        k = j ^ 1;
        money[i&1] = money[j] > money[k] + nums[i] ? money[j] : money[k] + nums[i];
    }
    return money[(numsSize-1)&1];
}
