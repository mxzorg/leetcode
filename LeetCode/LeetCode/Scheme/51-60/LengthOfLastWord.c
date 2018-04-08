//
//  LengthOfLastWord.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/4/8.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "LengthOfLastWord.h"
#include <string.h>

int lengthOfLastWord(char* s) {
    
    size_t len = strlen(s);
    int count = 0;
    while (len > 0) {
        len--;
        if (s[len] != ' ') {
            count++;
        }else{
            if (count > 0) {
                break;
            }
        }
    }
    
    return count;
}
