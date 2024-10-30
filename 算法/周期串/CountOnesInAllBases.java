import java.util.Scanner;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.demo
 * @date 2024/10/13 19:18
 * @description
 * 我们已经知道 2 进制到 10 进制表示方法，与 16 进制类似，
 * 我们考虑 11~36 进制，即用a代表10，b代表11等。
 * 我们想知道给定一个 10 进制数n，其在2~36 进制下的所有进制表示中，含有1的数量最多是多少。
 * 比如 4在二进制下表示为(100)2，只有一个1。
 */
public class CountOnesInAllBases {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int maxOnes = countMaxOnes(n);
        System.out.println(maxOnes);
    }

    public static int countMaxOnes(int n) {
        int maxOnes = 0;
        for (int base = 2; base <= 36; base++) {
            int onesInBase = countOnesInBase(n, base);
            maxOnes = Math.max(maxOnes, onesInBase);
        }
        return maxOnes;
    }

    private static int countOnesInBase(int n, int base) {
        int count = 0;
        String baseRepresentation = Integer.toString(n, base).toLowerCase();
        for (char c : baseRepresentation.toCharArray()) {
            if (c == '1') {
                count++;
            }
        }
        return count;
    }
}
