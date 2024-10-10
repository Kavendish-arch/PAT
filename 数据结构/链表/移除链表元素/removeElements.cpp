/**
 * Definition for singly-linked list.

 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        /**
         * 那么因为单链表的特殊性，只能指向下一个节点，刚刚删除的是链表的中第二个，和第四个节点，那么如果删除的是头结点又该怎么办呢？
         * 1. 删除头结点
         * 2. 删除非头节点
         * 这里就涉及如下链表操作的两种方式：直接使用原来的链表来进行删除操作。
         * 设置一个虚拟头结点在进行删除操作。
         * 来看第一种操作：直接使用原来的链表来进行移除
         */
        while (head != NULL && head->val == val)
        {
            ListNode *tmp = head;
            head = head->next;
            delete tmp;
        }

        ListNode *cur = head;
        while (cur != NULL && cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }
        return head;
    }
    ListNode *removeElements2(ListNode *head, int val)
    {
        /**
         * 那么因为单链表的特殊性，只能指向下一个节点，刚刚删除的是链表的中第二个，和第四个节点，那么如果删除的是头结点又该怎么办呢？
         * 1. 删除头结点
         * 2. 删除非头节点
         * 这里就涉及如下链表操作的两种方式：直接使用原来的链表来进行删除操作。
         * 设置一个虚拟头结点在进行删除操作。
         * 来看第一种操作：直接使用原来的链表来进行移除
         */

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *cur = dummy;
        while (cur->next != NULL)
        {
            if (cur->next->val == val)
            {
                ListNode *tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }
            else
            {
                cur = cur->next;
            }
        }

        head = dummy->next;
        delete dummy;
        return head;
    }
}