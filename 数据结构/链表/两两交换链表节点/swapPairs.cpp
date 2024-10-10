#include <stdlib.h>
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
        {
            return head;
        }
        ListNode *newHead = new ListNode(0);
        newHead->next = head;
        ListNode *pre = NULL, *cur = newHead, *next = NULL;
        ListNode *last = NULL;

        while (cur->next != NULL && cur->next->next != NULL)
        {
            ListNode *node1 = cur->next;
            ListNode *node2 = cur->next->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            cur = node1;
        }

        return newHead->next;
    }
};

int main(int argc, char const *argv[])
{
    ListNode *h1 = new ListNode(1);
    ListNode *h2 = new ListNode(2);
    ListNode *h3 = new ListNode(3);
    ListNode *h4 = new ListNode(4);
    h1->next = h2;
    h2->next = h3;
    h3->next = h4;

    Solution s;

    ListNode *tmp = s.swapPairs(h1);
    while (tmp != NULL)
    {
        cout << tmp->val << endl;
        tmp = tmp->next;
    }

    return 0;
}
