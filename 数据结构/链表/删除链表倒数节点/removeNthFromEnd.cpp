

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
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *dumpyHead = new ListNode(0);
        dumpyHead->next = head;

        ListNode *fast = dumpyHead;
        ListNode *slow = dumpyHead;

        for (int i = 0; i < n; i++)
        {
            fast = fast->next;
        }

        while (fast->next != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;

        slow->next = temp->next;
        temp->next = NULL;
        delete temp;

        head = dumpyHead->next;
        delete dumpyHead;
        return head;
    }
};