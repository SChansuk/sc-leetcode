/*
 * Brute force method
 * Time complexity: O(n^2)
 * Space complexity: O(1)
 */
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) 
    {
        ListNode *current = nullptr;
        ListNode *point = nullptr;

        unsigned int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry != 0) 
        {
            int x = (l1 != nullptr) ? l1->val : 0;
            int y = (l2 != nullptr) ? l2->val : 0;

            int sum = x + y + carry;
            carry = sum / 10;

            if (current == nullptr)
            {
                current = new ListNode(sum % 10);
                point = current;
            }
            else
            {
                point->next = new ListNode(sum % 10);
                point = point->next;
            }

            if (l1 != nullptr)
            {
                l1 = l1->next;
            }
            if (l2 != nullptr)
            { 
                l2 = l2->next;
            }
        }

        return current;
    }
};
