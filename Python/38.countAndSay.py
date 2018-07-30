#!/usr/local/bin/python3
# coding=utf-8


class Solution:
    def countAndSay(self, n):

        count = '1'
        res = ''
        for i in range(0, n):
            if i == n - 1:
                res = count
                break
            res = ''
            length = len(count)
            t = '1'
            c = 0
            j = 0
            while (j < length):
                if t == count[j]:
                    c += 1
                    j += 1
                else:
                    if c > 0:
                        res += str(c) + t
                        t = count[j]
                        j += 1
                        c = 1
                    else:
                        t = count[j]

                if j == length:
                    res += str(c) + t
                    count = res

        return res


def main():
    s = Solution()

    for x in range(1, 10):
        print(s.countAndSay(x))


if __name__ == '__main__':
    main()