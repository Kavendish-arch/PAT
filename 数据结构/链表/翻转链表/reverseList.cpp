

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
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }

        ListNode *pre = NULL, *cur = head, *next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};