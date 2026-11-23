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
    ListNode *reverseList(ListNode *head){
        ListNode *curr = head, *prev = NULL, *nxt = NULL;
        while(curr != NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;

        while(fast != NULL and fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *secondhalf = reverseList(slow->next);
        slow->next = NULL;
        ListNode *firsthalf = head;
        

        while(secondhalf != NULL){
            ListNode *ptr1 = firsthalf->next, *ptr2 = secondhalf->next;
            firsthalf->next = secondhalf;
            secondhalf->next = ptr1;
            firsthalf = ptr1;
            secondhalf = ptr2;

        }
    }
};
