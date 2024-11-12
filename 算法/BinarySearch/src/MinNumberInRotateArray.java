/**
 * @author chenyingtao
 * @version 1.0
 * @projectName BinarySearch
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.MinNumberInRotateArray
 * @date 2024/11/11 16:57
 * @description 有一个长度为 n 的非降序数组，比如[1,2,3,4,5]，将它进行旋转，即把一个数组最开始的若干个元素搬到数组的末尾，变成一个旋转数组，比如变成了[3,4,5,1,2]，或者[4,5,1,2,3]这样的。请问，给定这样一个旋转数组，求数组中的最小值。
 */
public class MinNumberInRotateArray {

    public int minNumberInRotateArray(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[right]) {
                left = mid+1;
            } else if (nums[mid] < nums[right]) {
                right = mid;
            } else {
                right--;
            }
        }
        return nums[right];
    }
}
