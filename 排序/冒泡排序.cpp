#include<stdio.h>
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
bool cmp(int a, int b) {
    return a > b;
}
void bubble_sort(int a[], int n) {
    bool flag = false;
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j++){
            if (cmp(a[i], a[j])) {
                swap(&a[i], &a[j]);
                flag = true;
            }
        }
        if (!flag) {
            return;
        }
    }
}

int main(int argc, char const *argv[])
{
    printf("%d", !true);
    return 0;
}
