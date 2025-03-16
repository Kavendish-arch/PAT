
// void BackTrack(int t) {
// 	if (t > n) 
// 		OutPut(x);
// 	else{
// 		for (int i = f
// 	}
// }
#include <iostream>
#include <vector>

// 定义全局变量来存储结果
std::vector<std::vector<int>> results;
std::vector<int> path;

// 回溯的核心递归函数
void backtrack(int start) {
    // 首先检查是否找到一个有效解
    if (isSolution()) {
        results.push_back(path);  // 存储解
        return;
    }

    // 构造解的候选集
    for (int i = start; i < candidates.size(); ++i) {
        // 做选择
        choose(i);
        // 进入下一层决策树
        backtrack(nextChoice(start));
        // 撤销选择
        unchoose(i);
    }
}

// 判断路径是否构成一个解
bool isSolution() {
    // 实现具体问题的解判断逻辑
    // 示例：如果path满足某个条件，则返回true
    return false;
}

// 做选择的具体实现
void choose(int i) {
    // 将选择加入路径
    path.push_back(candidates[i]);
}

// 撤销选择的具体实现
void unchoose(int i) {
    // 从路径中移除最后一个选择
    path.pop_back();
}

// 获取下一个开始搜索的位置
int nextChoice(int start) {
    // 返回下一个开始搜索的位置
    return start + 1;
}

// 主函数，初始化并启动回溯过程
int main() {
    std::vector<int> candidates = {1, 2, 3}; // 初始化候选集合
    backtrack(0); // 从第一个位置开始尝试
    // 输出所有可能的解
    for (const auto& result : results) {
        for (int num : result) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}