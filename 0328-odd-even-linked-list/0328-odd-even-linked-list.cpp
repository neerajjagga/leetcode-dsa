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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* oddHead = new ListNode(-1), *oddTail = oddHead;
        ListNode* evenHead = new ListNode(-1), *evenTail = evenHead;

        ListNode* curr = head;
        ListNode* temp;
        int currIndex = 1;

        while(curr) {
            // detach current node from list
            temp = curr;
            curr = curr->next;
            temp->next = nullptr;

            if(currIndex & 1) {
                oddTail->next = temp;
                oddTail = temp;
            }
            else {
                evenTail->next = temp;
                evenTail = temp;
            }
            currIndex++;
        }

        oddTail->next = evenHead->next;
        return oddHead->next; 
    }
};