import java.util.Scanner;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.SolutionThreee
 * @date 2024/10/13 15:49
 * @description 解决周期串问题
 */
public class SolutionThreee {

    public static boolean canBecomePeriodic(String S) {
        int n = S.length();
        // 检查所有可能的周期长度
        for (int d = 1; d <= n / 2; d++) {
            if (n % d == 0) {
                // 检查周期长度为d的情况
                if (isPeriodicWithLength(S, d)) {
                    return true;
                }
                // 如果不是周期串，尝试通过一次交换使其成为周期串
                if (canSwapToMakePeriodic(S, d)) {
                    return true;
                }
            }
        }
//        return "Y"
        return false;
    }

    private static boolean isPeriodicWithLength(String S, int d) {
        String pattern = S.substring(0, d);
        for (int i = d; i < S.length(); i += d) {
            if (!pattern.equals(S.substring(i, i + d))) {
                return false;
            }
        }
        return true;
    }

    private static boolean canSwapToMakePeriodic(String S, int d) {
        char[] chars = S.toCharArray();
        for (int i = 0; i < d; i++) {
            for (int j = i + d; j < S.length(); j += d) {
                if (chars[i] != chars[j]) {
                    // 尝试找到可以交换的字符
                    for (int k = j + 1; k < S.length(); k++) {
                        if (chars[i] == chars[k] && chars[j] == chars[k - d]) {
                            // 交换字符
                            swap(chars, j, k);
                            // 检查是否变为周期串
                            if (isPeriodicWithLength(new String(chars), d)) {
                                return true;
                            }
                            // 交换回来
                            swap(chars, j, k);
                        }
                    }
                    return false;
                }
            }
        }
        return false;
    }

    private static void swap(char[] chars, int i, int j) {
        char temp = chars[i];
        chars[i] = chars[j];
        chars[j] = temp;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        for(int i = 0; i < n; i++)
        {
            String str = scanner.nextLine();
            Boolean S = canBecomePeriodic(str);
            String result = S ? "YES" : "NO";
            System.out.println(result);  // 应该输出true
        }
    }
}
