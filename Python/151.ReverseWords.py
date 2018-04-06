#!/usr/bin/python
#coding=utf-8

class Solution(object):
    def reverseWords(self, str):
        list = str.split()
        list = list[::-1]
        str = ' '.join(list)
        return str