/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 算法
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.FindMedian
 * @date 2024/10/15 20:54
 * @description 查找中位数
 *
 * 描述
 * 在一个牧场中，有两个牛群，牛群A和牛群B，分别有m头和n头牛。每头牛都有一个独特的体重，体重由一个整数表示。
 *
 * 牛群A和牛群B的牛都按照体重从小到大进行排序。你的任务是找出这两个牛群的所有牛的体重的中位数。
 *
 * 请你设计一个算法，使得算法的时间复杂度为O(log (m+n))。
 *
 * # 二分查找：
 * 中段，左段，右段
 *
 * 0,1,2,3,4
 * 5/2 = 2
 *
 * 0,1,2,3,4,5
 * 6/2 = 3
 *
 */
public class FindMedian {
//    public double findMedianSortedArrays(int[] weightsA, int[] weightsB) {
//        // write code here
//        // O（n+m)
//        int A_left = 0;
//        int B_left = 0;
//        if((weightsA.length + weightsB.length) % 2 ==0)
//        {
//            //偶数
//            int med = (weightsA.length + weightsB.length) / 2;
//            for (int i = 1; i < med; i++)
//            {
//                if(weightsA[A_left] < weightsB[B_left])
//                {
//                    A_left++;
//                }
//                else{
//                    B_left++;
//                }
//
//            }
//            if(A_left == weightsA.length)
//            {
//                return (double)(weightsB[B_left] + weightsB[B_left + 1] / 2);
//            }
//            else if(B_left == weightsB.length)
//            {
//                return (double)(weightsA[A_left] + weightsA[A_left + 1] / 2);
//            }
//
//            else{
//
//            return (double)(weightsA[A_left] + weightsB[B_left]) / 2;
//            }
//        }
//        else{
//            int med = (weightsA.length + weightsB.length) / 2 + 1;
//            for (int i = 1; i < med; i++)
//            {
//                if(weightsA[A_left] < weightsB[B_left])
//                {
//                    A_left++;
//                }
//                else{
//                    B_left++;
//                }
//
//            }
//            if(A_left == weightsA.length)
//            {
//                return (double)(weightsB[B_left]);
//            }
//            else if(B_left == weightsB.length)
//            {
//                return (double)(weightsA[A_left]);
//            }
//            else{
//                return (weightsA[A_left] < weightsB[B_left]) ?  (double)(weightsA[A_left]):(double)(weightsB[B_left]);
//            }
//        // 奇数
//        }
//
//    }
    public double findMedianSortedArrays(int[] weightsA, int[] weightsB) {
        if((weightsA.length + weightsB.length) % 2 == 0)
        {
            int k1 = (weightsA.length + weightsA.length) / 2;
            int k2 = k1 + 1;

            return (0.5 * findKth(k1, weightsA, weightsB) + 0.5 * findKth(k2, weightsA, weightsB));
        }
        else {
            int k1 = (weightsA.length + weightsA.length) / 2 + 1;
            return findKth(k1, weightsA, weightsB);
        }
    }

    public double findKth(int k, int[] weightsA, int[] weightsB)
    {
        int midA = weightsA.length / 2;
        int midB = weightsB.length / 2;
        if(weightsA[midA] < weightsB[midB])
        {

        }
        else
        {

        }

        return 0.0;
    }

    public static void main(String[] args) {
        int[] a = {100, 300, 500, 700, 800};
        int[] b = {200};
        FindMedian findMedian = new FindMedian();
        System.out.println(findMedian.findMedianSortedArrays(a, b));
    }
}
