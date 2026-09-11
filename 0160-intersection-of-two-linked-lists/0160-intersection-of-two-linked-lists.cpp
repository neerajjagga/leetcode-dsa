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
    // Space comp = O(N1)
    // ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    //     unordered_map<ListNode*, int> mpp;

    //     // traverse list 1
    //     ListNode* curr = headA;
    //     while(curr) {
    //         mpp[curr] = 1;
    //         curr = curr->next;
    //     }

    //     // traverse 2
    //     curr = headB;
    //     while(curr) {
    //         if(mpp.count(curr))
    //             return curr;
    //         curr = curr->next;
    //     }

    //     return nullptr;
    // }


    // Optimized, Time comp - O(N1 + N2), Space - O(1)
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr) return nullptr;

        ListNode* temp1 = headA;
        ListNode* temp2 = headB;
        while(temp1 != temp2) {
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1 == temp2) return temp1;

            if(temp1 == nullptr) temp1 = headB;
            if(temp2 == nullptr) temp2 = headA;
        }

        return temp1;
    }
};