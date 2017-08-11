//
//  LongestPalindromicSubstring.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "LongestPalindromicSubstring.h"

#include <string.h>

#include <stdlib.h>

int isPalindromic(char* s, int left, int right)
{
    if (left > right)
    {
        return 0;
    }
    
    while (s[left] == s[right]) {
        
        left++;
        right--;
        
        if (left == right || left > right) {
            
            return 1;
        }
    }
    
    return 0;
}

char* longestPalindrome(char* s)
{
    int currLength = 0;
    
    char *res = NULL;
    
    for(int i = 0; i < strlen(s); i++)
    {        
        if (isPalindromic(s,i-currLength,i))
        {
            if (res)
            {
                free(res);
            }
            res = (char*)malloc(sizeof(char)*(currLength+2));
            memset(res, 0, currLength+2);
            memcpy(res, s+(i-currLength), currLength+1);
            currLength = currLength+1;
        }
        else if (isPalindromic(s,i-currLength-1,i))
        {
            if (res)
            {
                free(res);
            }
            res = (char*)malloc(sizeof(char)*(currLength+3));
            memset(res, 0, currLength+3);
            memcpy(res, s+(i-currLength-1), currLength+2);
            currLength = currLength+2;
        }
    }
    
    return res;
}
