package 模拟;

/**
 * @author chenyingtao
 * @version 1.0
 * @projectName 周期串
 * @package 模拟
 * @className 模拟.TeamDivision
 * @date 2024/10/15 18:04
 * @description 小亮负责管理一个团队，团队中有N个成员，小亮需要将成员分成若干个小组来同时完成更多的项目。为了 更加直观准确的完成这一目标，小亮对项目的难度估计为M，而每个成员有一个能力值A:。对于K个成员组 成的小组，能处理的最高项目难度为KxA，其中A为小组成员中能力值最高成员的能力值。 例如，一个小组的成员能力值分别为3、5、7，则这个3人小组能处理项目难度不超过3x7=21的项目。 如果一个小组能处理大于等于M难度的项目，那么这个小组就是可以完成项目的一个合理分组。 小亮告诉你项目的难度M，以及她的团队信息，希望你能帮她算一算她的团队最多能分成多少个小组同时处理不同的项目。 java 答题
 */

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class TeamDivision {

        public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int M = in.nextInt();
        int[] abilities = new int[n];
        for(int i = 0; i < n; i++)
        {
            abilities[i] = in.nextInt();
        }
        int maxTeams = maxTeams(abilities, M);
        System.out.println(maxTeams);
    }
//
//    public static int maxTeams(int[] abilities, int M) {
//        // 对成员能力值进行降序排序
//        Arrays.sort(abilities);
//        int n = abilities.length;
//        int teams = 0; // 可以组成的小组数量
//        // 从能力最强的成员开始，尝试组成小组
//        for (int left = 0, right = n - 1; left < right; right--) {
//            int maxAbility = abilities[right]; // 当前小组能力值最高的成员
//            if (maxAbility >= M) {
//                teams++;
//            } else {
//                int p = 1;
//                while (p < right - left) {
//                    if (maxAbility * (p + 1) >= M) {
//                        left += p;
//                        teams++;
//                    }
//
//                    else{
//                        p++;
//                    }
//                }
//            }
//        }
//        return teams;
//    }
public static int maxTeams(int[] abilities, int M) {
    // 对成员能力值进行降序排序
    Arrays.sort(abilities);
    int n = abilities.length;
    int teams = 0; // 可以组成的小组数量
    int index = n - 1; // 能力最高的成员的索引

    // 当还有成员未被分配时，继续尝试组成小组
    while (index >= 0) {
        // 从能力最高的成员开始，尝试组成小组
        int maxAbility = abilities[index];
        int membersInTeam = 0;
        int difficulty = 0;

        // 尝试将成员加入小组，直到小组能处理的项目难度大于等于M
        while (index - membersInTeam > 0 && difficulty < M) {
            difficulty = maxAbility * (membersInTeam + 1);
            membersInTeam++;
        }

        // 如果组成的小组能处理的项目难度大于等于M，则小组数量加一
        if (difficulty >= M) {
            teams++;
            index -= membersInTeam; // 减去已经分配的成员
        } else {
            // 如果无法组成有效小组，则减少成员数，并重新计算
            membersInTeam--;
            difficulty = maxAbility * membersInTeam;
            if (difficulty >= M) {
                teams++;
                index -= membersInTeam;
            } else {
                // 如果仍然无法组成有效小组，则移动到下一个成员
                index--;
            }
        }
    }

    return teams;
}
}
