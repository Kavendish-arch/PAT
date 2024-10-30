import java.util.*;

public class MainOne {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 读取评委数量 n 和选手数量 m
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        scanner.nextLine(); // 清空缓冲区
        // 用于存储每位选手的评分
        char[][] scores = new char[n][m];

        // 读取评委的评分
        for (int i = 0; i < n; i++) {
            String scoreLine = scanner.nextLine();
            scores[i] = scoreLine.toCharArray();
        }

        // 存储每个选手的最终评分
        int[] finalScores = new int[m];

        // 计算每位选手的最终评分
        for (int j = 0; j < m; j++) {
            List<Integer> ratings = new ArrayList<>();
            for (int i = 0; i < n; i++) {
                ratings.add(getRatingValue(scores[i][j]));
            }
            // 找出最大值和最小值
            int maxRating = Collections.max(ratings);
            int minRating = Collections.min(ratings);
            // 移除最大和最小评分
            ratings.remove(Integer.valueOf(maxRating));
            ratings.remove(Integer.valueOf(minRating));
            // 计算剩余评分的平均值
            int sum = ratings.stream().mapToInt(Integer::intValue).sum();
            int avgRating = ratings.size() > 0 ? (sum + ratings.size() / 2) / ratings.size() : 0; // 向上取整
            finalScores[j] = avgRating;
        }

        // 将选手编号和最终评分存储在列表中
        List<Contestant> contestants = new ArrayList<>();
        for (int j = 0; j < m; j++) {
            contestants.add(new Contestant(j + 1, finalScores[j]));
        }

        // 按评分从高到低排序，如果相同则按编号升序
        contestants.sort((c1, c2) -> {
            if (c1.score != c2.score) {
                return Integer.compare(c2.score, c1.score); // 降序
            }
            return Integer.compare(c1.id, c2.id); // 升序
        });

        // 输出选手编号
        for (Contestant contestant : contestants) {
            System.out.print(contestant.id + " ");
        }
        System.out.println();

        // 输出最终评分
        for (Contestant contestant : contestants) {
            System.out.print(getRatingChar(contestant.score) + " ");
        }
        System.out.println();
    }

    // 将字符评分转换为数值评分
    private static int getRatingValue(char c) {
        if (Character.isLowerCase(c)) {
            return c - 'a'; // 'a' = 0, 'b' = 1, ..., 'z' = 25
        } else {
            return c - 'A' + 26; // 'A' = 26, ..., 'Z' = 51
        }
    }

    // 将数值评分转换为字符评分
    private static char getRatingChar(int value) {
        if (value < 26) {
            return (char) (value + 'a'); // 'a' = 0, 'b' = 1, ..., 'z' = 25
        } else {
            return (char) (value - 26 + 'A'); // 'A' = 26, ..., 'Z' = 51
        }
    }

    // 用于存储选手编号和最终评分
    static class Contestant {
        int id;
        int score;

        Contestant(int id, int score) {
            this.id = id;
            this.score = score;
        }
    }
}
