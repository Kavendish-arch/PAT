
public class HeapSort {

    public static int[] sortArray(int[] nums) {
        int n = nums.length;
        for (int i = n / 2 - 1; i >= 0; i--) {
            HeapAdjust(nums, i, n - 1);
        }
        for (int i = n - 1; i > 0; i--) {
            // swap(nums[0], nums[i]);
            int tmp = nums[0];
            nums[0] = nums[i];
            nums[i] = tmp;
            HeapAdjust(nums, 0, i - 1);
        }
        for (Object elem : nums) {
            System.out.println(elem);
        }
        return nums;
    }

    public static void HeapAdjust(int[] nums, int s, int m) {
        int top = nums[s];
        for (int j = 2 * s + 1; j <= m;) {
            if (j < m && nums[j] < nums[j + 1]) {
                j++;
            }
            if (top >= nums[j]) {
                break;
            }
            nums[s] = nums[j];
            s = j;
            j = j * 2 + 1;
        }
        nums[s] = top;
    }

    // public static void swap(int a, int b) {
    //     int x = a;
    //     a = b;
    //     b = x;
    //     // a = b;
    //     // b = x;
    // }
    public static void main(String[] args) {
        int[] a = {5, 2, 3, 1};
        sortArray(a);
        for (Object elem : a) {
            System.out.println(elem);
        }
    }
}
