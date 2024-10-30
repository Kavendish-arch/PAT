import java.util.*;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.SolutionTwo
 * @date 2024/10/13 15:50
 * @description 最长字串（子串内两两最大公因数为1）
 * 用java编写下面的代码。一个数学社小组的小伙伴们最近提出了一个有趣的挑战，他们有一个包含n个数字的数据a1,a1,…,an，这个数据可以看作是他们通过各种数学技巧和算法得到的一组数据现在他们需要采用这个数据完成一个新的数学游戏。 小红书的这个数学游戏要求我们在给定的数字数组a1,a1,…,an中找到最长的连续子区间，使得这个区间的任意两个数的最大公约数(gcd)为1，最终，我们需要输出这个最长区间的长度。 输入描述：第一行有一个整数n（1≤n≤10^5），表示数组的长度。 第二行有n个整数ai（1≤ai≤10^6），表示数组的元素。 输出描述：输出一个整数，代表最长区间的长度。 示例输入 7 1 2 2 3 5 7 9 示例输出 4
 */
public class SolutionTwo {


    private static Set<Integer> factor(int n) {
        Set<Integer> facotrs = new HashSet<>();
        facotrs.add(1);
        facotrs.add(n);
        for (int i = 2; i <= Math.sqrt(n); i++) {
            if (n % i == 0) {
                facotrs.add(i);
                facotrs.add(n / i);
            }
        }

        return facotrs;
    }

    public static int solution(int[] nums) {
        HashMap<Integer, Set<Integer>> hm = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            hm.put(nums[i], factor(nums[i]));
        }

        Set<Integer>  union = new HashSet<>();
        int maxLength = 1;
        int tmplength = 1;

        union.addAll(hm.get(nums[0]));
        for(int i = 1; i < nums.length; i++)
        {
            Set<Integer> tmp = new HashSet<>(union);
            tmp.retainAll(hm.get(nums[i]));
            if(tmp.size() == 1)
            {
                tmplength++;
            }
            else{
                union.clear();
//                union.addAll(hm.get(nums[i]));
                tmplength= 1;
            }
            union.addAll(hm.get(nums[i]));
            maxLength = Math.max(maxLength, tmplength);
        }
        return maxLength;
    }



    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        // 读取输入
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        int maxLen = 0; // 初始化最长区间长度

        maxLen = solution(arr);

        System.out.println(maxLen);

//        ArrayList<Integer> arr1 = new ArrayList<>();
//        Arrays.sort(arr1, (c1, c2)->{
//            return Integer.compare((Integer) c1, (Integer) c2);
//        });
    }
}
