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
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* prev = nullptr;
    //     ListNode* curr = head;
    //     ListNode* next = nullptr;

    //     while(curr != nullptr) {
    //         next = curr->next;
    //         curr->next = prev;
    //         prev = curr;
    //         curr = next;
    //     }

    //     return prev;
    // }

    // ListNode* removeNthFromEnd(ListNode* head, int n) {
    //     ListNode* newHead = reverseList(head);
    //     if(n == 1) {
    //         ListNode* temp = newHead;
    //         newHead = newHead->next;
    //         delete temp;
    //     } else {
    //         ListNode* curr = newHead;

    //         for(int i=1; i<n-1; i++) {
    //             curr = curr->next;
    //         }

    //         ListNode* temp = curr->next;
    //         curr->next = curr->next->next;
    //         delete temp;
    //     }
    //     return reverseList(newHead);
    // }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        for(int i=0; i<n; i++) fast = fast->next;
        
        if(fast == nullptr) return head->next;

        while(fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;
        delete delNode;
        return head;
    }
};