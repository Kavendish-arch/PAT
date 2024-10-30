import java.util.Scanner;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.demo
 * @date 2024/10/13 19:24
 * @description
 * 给定两个整数几和 m，询问满足如下条件的序列a的数量
 * ● 序列 a 的长度为 n;
 * ● 序列 a的值均大于等于 0 且小于等于 m ，形式化的说,0 ≤ai≤m(1 ≤i≤n);
 * ● a1 < a2 ≤ a3 <...≤ an，表示序列a是一个非递减序列;
 * ● a1 ^ a2 ^ a3...^ an = m，表示序列 a所有元素的异或值为 m。
 */
public class SequenceCounter {

        public static final int MOD = 1000000007; // 10^9 + 7

//        public static int countSequences(int n, int m) {
//            int[] dp = new int[m + 300];
//            dp[0] = 1; // 空序列的异或和为 0
//
//            // 计算每个数字的二进制表示中1的个数
//            int[] countBits = new int[1024];
//            for (int i = 1; i < 1024; i++) {
//                countBits[i] = countBits[i >> 1] + (i & 1);
//            }
//
//            // 动态规划计算序列数量
//            for (int i = 1; i <= n; i++) {
//                int[] nextDp = new int[m + 1];
//                for (int j = 0; j <= m; j++) {
//                    for (int k = 0; k < 1024; k++) {
//                        if (countBits[j ^ k] <= i) {
//                            nextDp[j] = (nextDp[j] + dp[j ^ k]) % MOD;
//                        }
//                    }
//                }
//                dp = nextDp;
//            }
//
//            return dp[m];
//        }

    public static long countSequences(int n, int m) {
        // dp[i][j] 表示长度为 i 的序列，其所有元素异或和为 j 的序列数量
        long[][] dp = new long[n + 1][m + 1];
        // 初始化，长度为 0 的序列只有一个，其异或和为 0
        dp[0][0] = 1;

        // 填充动态规划表
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                // 计算长度为 i，异或和为 j 的序列数量
                for (int k = 0; k <= m; k++) {
                    // 序列的最后一个元素是 k
                    if ((j ^ k) <= m) {
                        dp[i][j] = (dp[i][j] + dp[i - 1][j ^ k]);
                    }
                }
            }
        }

        // 返回长度为 n，异或和为 m 的序列数量
        return dp[n][m] % MOD;
    }



    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();// 序列长度
        int m = in.nextInt(); // 异或值
        System.out.println(countSequences(n, m));
    }
}
