impl Solution {
    pub fn zero_filled_subarray(nums: Vec<i32>) -> i64 {
        let mut count = 0;
        let mut res : i64 = 0;
        for num in nums {
            if num == 0 {
                count += 1;
            }
            else if count > 0 {
                res += (count*(count + 1)) / 2;
                count = 0;
            }
        }
        res += (count*(count + 1)) / 2;
        res
    }
}
