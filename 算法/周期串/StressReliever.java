import java.util.Scanner;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package PACKAGE_NAME
 * @className PACKAGE_NAME.Demo1
 * @date 2024/10/13 19:12
 * @description
 * 牛牛工作一天压力就会增加A，休息一天压力就会减少1.
 * 牛牛当初的压力值为0，从第一天一直工作到第B天，
 * 从B+1天开始请假休息，直到牛牛压力值再度为0。
 *
 * 现在给出A,B的值，请你编写一个程序，求出牛牛从压力值为0到再度为0历时多少天。使用java编写
 */
public class StressReliever {
        public static void main(String[] args) {
            // 假设 A 和 B 的值已经通过某种方式提供，例如命令行参数或用户输入
            Scanner in = new Scanner(System.in);
            int n = in.nextInt();
            for(int i = 0; i < n; i++){
                int A = in.nextInt(); // 示例值，可以替换为实际值
                int B = in.nextInt(); // 示例值，可以替换为实际值

                int days = calculateDaysUntilNoStress(A, B);
                System.out.println(days);

            }
        }

        public static int calculateDaysUntilNoStress(int A, int B) {
            int stress = 0;
            int days = 0;
            // 工作阶段，压力每天增加 A
            for (int i = 1; i <= B; i++) {
                stress += A;
                days++;
            }

            // 休息阶段，压力每天减少 1，直到压力为 0
            while (stress > 0) {
                stress -= 1;
                days++;
            }

            return days;
        }

}
