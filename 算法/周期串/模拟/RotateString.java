package 模拟;

import java.util.Scanner;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package 模拟
 * @className 模拟.RetateString
 * @date 2024/10/15 20:37
 * @description
 */

public class RotateString {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
//        String input = scanner.nextLine(); // 读取输入字符串

//        int n = scanner.nextInt();
//        String input = "abqde";
        String input = "paectc";
        int n = 3;
        String result = rotateString(input); // 调用函数进行旋转操作
        System.out.println(result); // 输出结果
        scanner.close();
    }

    public static String rotateString(String s) {
        int n = s.length();
        char[] chars = s.toCharArray(); // 将字符串转换为字符数组以便操作

//        System.out.println(chars);
        for (int i = 0; i < n; i++) {
            char firstChar = chars[i]; // 获取当前字符串的第一个字符
            // 将剩余的字符前移
            for (int j = i; j < n - 1; j++) {
                chars[j] = chars[j + 1];
            }
            // 将第i个字符移动到字符串末尾
            chars[n - 1] = firstChar;
//            System.out.println(chars);
        }

        return new String(chars); // 将字符数组转换回字符串并返回
    }
}

