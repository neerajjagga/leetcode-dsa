/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> mpp;

        // traverse list 1
        ListNode* curr = headA;
        while(curr) {
            mpp[curr] = 1;
            curr = curr->next;
        }

        // traverse 2
        curr = headB;
        while(curr) {
            if(mpp.count(curr))
                return curr;
            curr = curr->next;
        }

        return nullptr;
    }
};