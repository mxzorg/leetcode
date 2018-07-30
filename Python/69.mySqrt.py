#!/usr/local/bin/python3
# -*- coding:utf-8 -*-


class Solution:

    def mySqrt(self, x):

        if x == 0 or x == 1: return x

        start = 1
        end = x

        while start + 1 < end:
            mid = start + (end - start) // 2
            if mid * mid == x:
                return mid
            elif mid * mid < x:
                start = mid
            else:
                end = mid

        if start * start <= x and end * end <= x:
            if start * start < end * end:
                return end

            return start

        if start * start <= x:
            return start

        return end

def main():
    s = Solution()

    print(s.mySqrt(9))


if __name__ == '__main__':
    main()