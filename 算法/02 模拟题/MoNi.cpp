//
//  MoNi.cpp
//  Demo
//
//  Created by chenyingtao on 2025/3/16.
//

//
//  getMax.cpp
//  Demo
//
//  Created by chenyingtao on 2025/3/16.
//
#include <vector>
using namespace std;

class Solution {
public:
   /**
    258
    16.01
    133
    */
    
    // 模拟题目 258
    int addDigits(int num) {
        while(num >= 10){
            int sum = 0;
            while(num != 0){
                sum += num %10;
                num /= 10;
            }
            num = sum;
            //sum != 0
            //累加 个位，
            //sum / 10
        }
        return num;
    }
    
    // 1601 交换数字
    // 编写一个函数，不用临时变量，直接交换numbers = [a, b]中a与b的值。
    vector<int> swapNumbers(vector<int>& numbers) {
        numbers[0] = numbers[0] ^ numbers[1];
        numbers[1] = numbers[0] ^ numbers[1];
        numbers[0] = numbers[0] ^ numbers[1];
        return numbers;
    }
    
    /*
     LCR 133. 位 1 的个数
     编写一个函数，输入是一个无符号整数（以二进制串的形式），返回其二进制表达式中数字位数为 '1' 的个数（也被称为 汉明重量).）。
     */
    int hammingWeight(uint32_t n) {
        // &运算
        int sum = 0;
        while(n){
            sum += n & 1; // sum += n % 2;
            n = (n >> 1);  // n /= 2;
        }
        return sum;
    }
    //1991. 找到数组的中间位置
    int findMiddleIndex(vector<int>& nums) {
        
        for (int i = 0; i < nums.size(); ++i){
            int l = 0;
            int r = 0;
            for(int j = 0; j < i; ++j){
                l += nums[j];
            }
            for(int k = i+1; k < nums.size(); ++k){
                r += nums[k];
            }
            if(l == r){
                return i;
            }
        }
        return -1;
    }
};
