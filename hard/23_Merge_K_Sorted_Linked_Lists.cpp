/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int k = lists.size();
        ListNode* head = new ListNode(-1, nullptr);
        ListNode* curr = head;
        while(curr) {
            int minVal = INT_MAX;
            int minIdx = 0;
            for(int i = 0; i < k; i++) {
                if(lists[i] && lists[i]->val <= minVal) {
                    minVal = lists[i]->val;
                    minIdx = i;
                }
            }
            if(minVal == INT_MAX) {
                break;
            }
            curr->next = lists[minIdx];
            lists[minIdx] = lists[minIdx]->next;
            curr = curr->next;
        }
        return head->next;
    }
};

// O(n * k) solution
