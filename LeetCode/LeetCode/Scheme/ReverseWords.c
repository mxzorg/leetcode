//
//  ReverseWords.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "ReverseWords.h"

#include <string.h>

char* reverseWords(char *s)
{
    char *start = s;
    char *end = s + strlen(s) - 1;
    char ch;
    
    if (s != NULL)
    {
        while (start < end)
        {
            ch = *start;
            *start++ = *end;
            *end-- = ch;
        }
    }
    
    return s;
}

char* reverseWords2(char *str)
{
    int i = 0;
    while (1)
    {
        if (str[i] == ' '){
            
            i++;
            continue;
        }
        if (i == strlen(str))
        {
            return "";
        }
        
        str[i] = str[strlen(str)-i-1]+str[i];
        str[strlen(str)-i-1] = str[i]-str[strlen(str)-i-1];
        str[i] = str[i]-str[strlen(str)-i-1];
        
        if (i > strlen(str) / 2)
        {
            break;
        }
        i++;
    }
    
    return str;
}
