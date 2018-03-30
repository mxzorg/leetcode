//
//  MyStrStr.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/3/30.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "MyStrStr.h"

#include <string.h>

int MyStrStr(char* haystack, char* needle)
{
    if (haystack == NULL || needle == NULL) {
        return -1;
    }
    
    if (haystack == needle) {
        return 0;
    }
    
    size_t len1 = strlen(haystack);
    size_t len2 = strlen(needle);
    if (len2 == 0) {
        return 0;
    }
    
    int i = 0, j = 0;
    while (i < len1) {
        while (haystack[i] == needle[j]) {
            i++;
            j++;
            if (j==len2) {
                return i-j;
            }
        }
        i = i-j+1;
        j = 0;
    }
    return -1;
}
