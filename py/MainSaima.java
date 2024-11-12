
import java.util.*;

final class Solution {

    public static int addab(int a, int b) {
        return a + b;
    }
}

public class MainSaima {

    public static void main(String args[]) {
        Scanner cin = new Scanner(System.in);
        int a, b;
        while (cin.hasNextInt()) {
            a = cin.nextInt();
            b = cin.nextInt();
            // Solution s = new Solution();
            int c = Solution.addab(a, b);
            // int c = a + b;

            System.out.println(c);
        }
        cin.close();
    }
}
