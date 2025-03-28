import com.sun.source.tree.BreakTree;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName BinarySearch
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.FindPeakElement
 * @date 2024/11/11 16:43
 * @description 描述 给定一个长度为n的数组nums，请你找到峰值并返回其索引。数组可能包含多个峰值，在这种情况下，返回任何一个所在位置即可。 1.峰值元素是指其值严格大于左右相邻值的元素。严格大于即不能有等于 2.假设 nums[-1] = nums[n] =  − ∞ −∞ 3.对于所有有效的 i 都有 nums[i] != nums[i + 1] 4.你可以使用O(logN)的时间复杂度实现此问题吗？  数据范围： 1 ≤ n u m s . l e n g t h ≤ 2 × 1 0 5   1≤nums.length≤2×10  5    − 2 31 < = n u m s [ i ] < = 2 31 − 1 −2  31  <=nums[i]<=2  31  −1  如输入[2,4,1,2,7,8,4]时，会形成两个山峰，一个是索引为1，峰值为4的山峰，另一个是索引为5，峰值为8的山峰，如下图所示：
 */
public class FindPeakElement {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * @param nums int整型一维数组
     * @return int整型
     */
    public int findPeakElement(int[] nums) {
        // write code here
        int left = 0;
        int right = nums.length;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if ((mid == 0 && nums[mid] > nums[mid + 1]) || (mid == nums.length - 1 && nums[mid] > nums[mid - 1])) {
                return mid;
            }
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                left = mid;
            } else {
                right = mid;
            }

        }

        return left;
    }
}