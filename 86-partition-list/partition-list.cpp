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
    ListNode* partition(ListNode* head, int x) {
         ListNode* dummy1 = new ListNode(0);
    ListNode* dummy2 = new ListNode(0);

    // Pointers to build both lists
    ListNode* small = dummy1;
    ListNode* large = dummy2;

    // Traverse original linked list
    while (head != nullptr) {

        if (head->val < x) {

            small->next = head;
            small = small->next;

        }
        else {

            large->next = head;
            large = large->next;

        }

        head = head->next;
    }

    // Connect both lists
    large->next = nullptr;
    small->next = dummy2->next;

    ListNode* result = dummy1->next;

    delete dummy1;
    delete dummy2;

    return result;
    }
};