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
    ListNode* mergeTwoSortedLLs(ListNode* left, ListNode* right) {
        ListNode* dummyNode = new ListNode(-1);
        ListNode* t1 = left, *t2 = right;
        ListNode* temp = dummyNode;

        while(t1 != nullptr && t2 != nullptr) {
            if(t1->val < t2->val) {
                temp->next = t1;
                temp = t1;
                t1 = t1->next;
            } else {
                temp->next = t2;
                temp = t2;
                t2 = t2->next;
            }
        }

        if(t1) temp->next = t1;
        else temp->next = t2;
        return dummyNode->next;
    }

    ListNode* findMiddle(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* sortLL(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;
        
        ListNode* middle = findMiddle(head);

        ListNode* right = middle->next;
        middle->next = nullptr;
        ListNode* left = head;

        left = sortLL(left);
        right = sortLL(right);

        return mergeTwoSortedLLs(left, right);
    }

    ListNode* sortList(ListNode* head) {
        return sortLL(head);
    }
};