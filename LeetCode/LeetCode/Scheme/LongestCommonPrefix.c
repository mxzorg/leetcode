//
//  LongestCommonPrefix.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/28.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "LongestCommonPrefix.h"

#include <string.h>
#include <stdlib.h>

char* commonPrefix(char *left, char *right)
{
    size_t minLen = strlen(left)>strlen(right)?strlen(left):strlen(right);

    for (int i = 0; i<minLen; i++) {
        
        if (left[i] != right[i]) {
            
            char *res = (char*)malloc(sizeof(char)*i+1);
            memset(res, 0, sizeof(char)*i+1);
            memcpy(res, left, i);
            return res;
        }
    }
    
    return left;
}

char* innerLongestCommonPrefix(char** strs, int l, int r)
{
    if (r == l) {
        return strs[l];
    }
    else {
        int mid = (l + r)/2;
        char *left = innerLongestCommonPrefix(strs, l , mid);
        char *right = innerLongestCommonPrefix(strs, mid + 1,r);
        
        return commonPrefix(left, right);
    }
}


char* longestCommonPrefix(char** strs, int strsSize)
{
    if (strs == NULL || strsSize == 0)
        return "";
    
    return innerLongestCommonPrefix(strs, 0 , strsSize - 1);
}
