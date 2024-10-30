def can_become_periodic_by_one_swap(s):
    n = len(s)
    s = list(s)  # 将字符串转换为列表以便交换字符

    # 检查字符串是否已经是周期串
    def is_periodic(length):
        pattern = s[:length]
        for i in range(length, n, length):
            if s[i:i+length] != pattern:
                return False
        return True

    # 尝试通过一次交换变为周期串
    def can_swap_to_periodic(length):
        for i in range(length):
            for j in range(i + length, n, length):
                if s[i] != s[j]:
                    # 尝试找到可以交换的位置
                    for k in range(j + 1, n):
                        if s[k] == s[i] and s[k - (k % length)] == s[j]:
                            # 执行交换
                            s[j], s[k] = s[k], s[j]
                            if is_periodic(length):
                                return True
                            # 撤销交换
                            s[j], s[k] = s[k], s[j]
        return False

    # 获取所有可能的周期长度
    for length in range(1, n // 2 + 1):
        if n % length == 0:
            if is_periodic(length) or can_swap_to_periodic(length):
                return True

    return False

# 示例使用
n = input()
# print(n)
n = int(n)
for i in range(n):
    s = input()
    result = "YES" if can_become_periodic_by_one_swap(s) else "NO"
    print(result)

# s = "abacabac"
# s = "abacabac"
# print(can_become_periodic_by_one_swap(s))  # 输出应该为 True 或 False
