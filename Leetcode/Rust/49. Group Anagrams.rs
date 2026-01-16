use std::collections::HashMap;

impl Solution {
    pub fn group_anagrams(strs: Vec<String>) -> Vec<Vec<String>> {
        let mut map = HashMap::<Vec<u8>, Vec<String>>::new();
        for curr_str in strs {
            let mut freq = vec![0u8; 26];

            for ch in curr_str.chars() {
                freq[ch as usize - 'a' as usize] += 1
            }

            map.entry(freq)
            .or_insert(Vec::new())
            .push(curr_str);
        }
        map.into_values().collect()
    }
}
