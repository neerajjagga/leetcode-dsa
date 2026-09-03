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
    // two pass solution
    // ListNode* middleNode(ListNode* head) {
    //     int length = 0;
    //     ListNode* temp = head;
    //     while(temp != nullptr) {
    //         length++;
    //         temp = temp->next;
    //     }

    //     int mid = length / 2;

    //     temp = head;
    //     for(int i=0; i<mid; i++) {
    //         temp = temp->next; 
    //     }

    //     return temp;
    // }
    

    // one pass solution - slow and fast pointers
    ListNode* middleNode(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};