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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //optimal:
        //add the numbers together while traversing through the array
        //O(max(l1, l2))
        //num1, num2, carry. end when carry is 0 and both are null

        int carry = 0;
        ListNode* head = nullptr;
        ListNode* past = nullptr;

        while (carry != 0 || l1 != nullptr || l2 != nullptr) {

            int first = (l1 == nullptr) ? 0 : l1->val;
            int second = (l2 == nullptr) ? 0 : l2->val;

            int number = first + second + carry;

            //cout << first << ", " << second << ", " << number << "\n";

            ListNode* newNode = new ListNode(number % 10);
            carry = number / 10;

            if (head == nullptr) {
                head = newNode;
                past = newNode;
            } else {
                past->next = newNode;
                past = newNode;
            }
            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return head;

    }
};
