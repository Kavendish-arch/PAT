/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 算法
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.FinMin
 * @date 2024/10/15 22:00
 * @description 描述 农场里有一群牛，每头牛都有一个身高，这些身高按照从高到低的顺序排列在一个 n 的牛棚中。
 * 为了混乱猎豹的视线，农场主人决定旋转牛群的排列顺序，也就是将牛棚中的牛按照一定的次数向后旋转。
 * 例如，原数组 heights = [7,6,5,4,3,2,1] 在变化后可能得到： 若旋转 4 次，则可以得到 [4,3,2,1,7,6,5] 若旋转 7 次，则可以得到 [7,6,5,4,3,2,1]
 * 注意，数组 [a[0], a[1], a[2], ..., a[n-1]] 旋转一次 的结果为数组 [a[n-1], a[0], a[1], a[2], ..., a[n-2]] 。
 * 请你找出并返回数组中的 最小元素 。  你必须设计一个时间复杂度为 O(log n) 的算法解决此问题。
 *
 * 招一个target
 * 二分查找的问题
 */
public class FinMin {
    public int findMin(int[] heights) {
        // write code here
        int lefft = 0;
        int right = heights.length - 1;
        int last = heights.length - 1;
        int first = 0;
        while (lefft < right) {
            int mid = lefft + (right - lefft) / 2;
            if (heights[mid] < heights[first]) {
                if ((mid == 0 && heights[mid] < heights[mid + 1]) || (mid == last && heights[mid] < heights[mid - 1]) ||
                        (heights[mid] < heights[mid - 1] && heights[mid] < heights[mid + 1])
                ) {
                    return heights[mid];
                }
                lefft = mid;
            } else {
                right = mid;
            }
        }
        return heights[lefft];
    }

    public int searchInsert (int[] labels, int target) {
        // write code here
        int left = 0;
        int right = labels.length -1;
        if(target < labels[0])
        {
            return 0;
        }
        if(target > labels[labels.length-1])
        {
            return labels.length;
        }
        while (left < right)
        {
            int mid = left + (right - left) / 2;
            if(labels[mid] == target)
            {
                return mid;
            }
            if (labels[mid] < target) {
                left = mid + 1;
            }else{
                right = mid;
            }
        }
        return right;
    }

//    public int[] searchRange (int[] weights, int target) {
        // write code here
//    }
    public static void main(String[] args) {
        int [] a = {5,4,3,2,1,7,6};
        FinMin finMin = new FinMin();
        System.out.println(finMin.findMin(a));

        int [] b = {1,2,4,5,6,7};
        System.out.println(finMin.searchInsert(b, 9));
    }
}
