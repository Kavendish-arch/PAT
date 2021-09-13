#include <stdio.h>

void printf_array(int A[], int high) {
    high --;
    printf("[");
    for (int i = 0; i < high; i++) {
        printf("%2d,",A[i]);
    }
    printf("%2d]\n",A[high]);
}

void shell_sort(int a[], int len) {
    int d, i, j;

    for (d = len/2; d >= 1; d /= 2) {
        for(i = d + 1; i <= len; i++) {
            if (a[i] < a[i-d]) {
                int tmp = a[i];
                for (j = i - d; i >= 0 && a[j] >= tmp; j -= d){
                    a[j + d] = a[j];
                }
                a[j + d] = tmp;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    int a[] = {12,34,13,15,12,56,54,46,36};
    printf_array(a, 9);
    shell_sort(a, 9);
    printf_array(a, 9);
    return 0;
}
