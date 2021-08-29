#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct _bign{
    int symp;
    int array[1000];
    int len;
} bign;

bign sub(bign a, bign b);
bign add(bign a, bign b);
int cmpare(bign *a, bign *b);

bign sub(bign a, bign b){
    /**
     * 前提条件 a > b
     */
    bign c;
    if (compare(a, b));
    int len = a.len > b.len ? a.len : b.len;
    int borrow = 0;
    for (int i = 0; i < len; i++) {
        
        int tmp = a.array[i] - b.array[i] - borrow;
        if (tmp < 0 && tmp > -10) {
            borrow = 1;
        } else {
            borrow = 0;
        }
        c.array[i] = tmp + 10;
    }
}
bign add(bign a, bign b){
    /**
     * 实现两个正数之间的加法运算
     * 
     */
    bign c;
    int len = a.len > b.len ? a.len : b.len;
    // printf("lenth = %d", len);

    int carry = 0;
    for (int i = 0; i < len; i++){
        int tmp = a.array[i]+ b.array[i] + carry;
        if (tmp < 10){
            carry = 0;
        } else { 
            //
            // carry = tmp / 10;
            carry = 1;
        }
        c.array[i] += tmp % 10 + carry;
        // printf("[%d + %d = %d ----- carry = %d]\n", a.array[i], b.array[i], tmp, carry);
        
    }
    c.len = len;
    return c;
}
int cmpare(bign *a, bign *b) {
    /**
     * 比较两个数组表示的大数 的大小
     */
    if (a->len > b->len) {
        return 1;
    } else if (a->len < b->len) {
        return -1;
    } else {
        for (int i = a->len - 1; i >= 0; i--) {
            if (a->array[i] > b->array[i]) {
                return 1;
            } else if (a->array[i] < b->array[i]) {
                return -1;
            }
        }
    } 
    return 0;
}


bign  char2int(char * chs, int lenth, int ** arrary) {
    bign result;
    int * tmp_array;
    tmp_array = (int *) malloc (sizeof(int) * lenth);
    memset(result.array, 0, sizeof(result.array));
    int j = 0;
    for (int i = lenth-1; i >= 0; i--){
        if (chs[i] >= '0' && chs[i] <= '9'){
            tmp_array[j] = chs[i] - '0';
            result.array[j++] = (chs[i] - '0');
        }
    }
    result.len = lenth;
    *arrary = tmp_array;
    return result;
}
void int2char(bign * bign_in, char ** res) {
    char * result;
    result = (char *) malloc (sizeof(char) * bign_in->len);
    for (int i = 0; i < bign_in->len; i++){
        if (bign_in->array[i] >= 0 && bign_in->array[i] <= 9){
            result[i] = bign_in->array[i] + '0';
        }
    }
    *res = result;
}

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head;
    head = (struct ListNode *) malloc (sizeof(struct ListNode));
    head->val = 0;
    head->next = NULL;
    struct ListNode * tail = head;
    
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        struct ListNode * tmp; 
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        tmp->next = NULL;
        
        int sum = 0;
        int a = l1 != NULL ? l1->val : 0;
        int b = l2 != NULL ? l2->val : 0;

        sum = a + b + carry;

        carry = sum > 9 ? 1 : 0;
        
        tmp->val = sum % 10;
        
        tail->next = tmp; 
        tail = tail->next;
        l1 = l1 != NULL ? l1->next : NULL;
        l2 = l2 != NULL ? l2->next : NULL;
    }
    if (carry != 0) {
        struct ListNode * tmp; 
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = carry;
        tail->next = tmp;
    }
    return head->next; 
}
struct ListNode* addTwoNumbers2(struct ListNode* l1, struct ListNode* l2){
    struct ListNode * head = l1;
    struct ListNode * head2 = l2;
    struct ListNode * tail = head;
    
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        struct ListNode * tmp = l1; 
         
        int sum = 0, a = 0, b = 0;
        if (l1 != NULL) {
            a = l1->val;
            l1 = l1->next;
        }
        if (l1 == NULL) {
            tail = head2;
        }
        if (l2 != NULL) {
            a = l2->val;
            l2 = l2->next;
        }
        sum = a + b + carry;

        carry = sum > 9 ? 1 : 0;
        
        tmp->val = sum % 10;
        
        tail->next = tmp; 
        tail = tail->next;
    }
    if (carry != 0) {
        struct ListNode * tmp; 
        tmp = (struct ListNode *) malloc (sizeof(struct ListNode));
        tmp->next = NULL;
        tmp->val = carry;
        tail->next = tmp;
    }
    return head->next; 
}
int main(int argc, char const *argv[])
{
    char num[] = "654321";
    char num2[] = "6543210";
    int *array;
    int *array2;
    bign b;
    bign a;
    bign c;
    b = char2int(num, 6, &array);
    a = char2int(num2, 7, &array2);

    c = add(a, b);

    char x[] = "";
    char * p2 = x;
    int2char(&c, &p2);
    printf("%s\n",p2);
    return 0;
}

