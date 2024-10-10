

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/**
 *
 * 追及问题
 *
 * 快慢指针
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return NULL;

        ListNode *slow = head, *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast)
            {
                break;
            }
        }

        if (fast == slow)
        {
            ListNode *index1 = head;
            ListNode *index2 = fast;
            if (index1 == index2)
            {
                return index1;
            }
            while (index1 != index2)
            {
                index1 = index1->next;
                index2 = index2->next;
                if (index1 == index2)
                {
                    return index1;
                }
            }
        }
        else
        {

            return NULL;
        }
    }
};