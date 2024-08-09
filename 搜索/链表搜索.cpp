/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
struct ListNode
{
    int val;
    struct ListNode *next;
};
struct ListNode *middleNode(struct ListNode *head)
{
    int sz = 0;
    while (head->next != nullptr)
    {
        sz++;
    }
    struct ListNode *p = head;
    int k = 0;
    int mid = sz % 2 == 0 ? sz / 2 + 1 : sz / 2;
    while (k <= mid)
    {
        p = p->next;
        k++;
    }
    return p;
}

/**
 * @brief
 * 有序数组，找两数和为目标值
 * @param numbers
 * @param numbersSize
 * @param target
 * @param returnSize
 * @return int*
 */
/**
 * n * n
 * n*logn
 */
int binarySearch(int *numbers, int numbersSize, int target)
{
    int left = 0, right = numbersSize - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (numbers[mid] == target)
        {
            return mid;
        }
        if (numbers[mid] < target)
        {
            left = mid + 1;
        }
        if (numbers[mid] > target)
        {
            right = mid;
        }
    }
    return -1;
}

int *twoSum(int *numbers, int numbersSize, int target, int *returnSize)
{
    // 记录答案
    int *ret = (int *)malloc(sizeof(int) * 2);
    *returnSize = 0;

    for (int i = 0; i < numbersSize; i++)
    {
        int a = numbers[i];
        int b = binarySearch(numbers, numbersSize, target - a);
        if (b != -1)
        {
            ret[0] = i < b ? i + 1 : b + 1;
            ret[1] = i > b ? i + 1 : b + 1;
            *returnSize = 2;
            return ret;
        }
    }
    return ret;
}
int main(int argc, char const *argv[])
{
    int a[] = {3, 24, 50, 79, 88, 150, 345};
    int target = 200;
    int b = 0;
    // int *ret = twoSum(a,7,target,&b);
    b = binarySearch(a, 7, 120);
    printf("%d ", b);
    for (int i = 0; i < b; i++)
    {
        // printf("%d ", ret[i]);
    }
    return 0;
}