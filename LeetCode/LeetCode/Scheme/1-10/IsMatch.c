//
//  IsMatch.c
//  LeetCode
//
//  Created by Gemini_Vincent on 2018/8/16.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "IsMatch.h"
#include <string.h>

bool isMatch(char* s, char* p) {
 
    int sLen = (int)strlen(s);
    int pLen = (int)strlen(p);
    int i = 0, j = 0;
    while (i < sLen && j < pLen) {
        if (p[i] >= 'a' && p[i] <= 'z') {
            if (p[i] != s[j]) {
                return false;
            }else{
                i++;
                j++;
            }
        }else if (p[i] == '.') {
            i++;
            j++;
        }else if (p[i] == '*') {
            char t = p[i-1];
            while (t == s[j]) {
                j++;
            }
            i++;
        }else{
            // input error and do nothing
        }
    }
    
    if (i != sLen || j != pLen) {
        return false;
    }
    return true;
}
