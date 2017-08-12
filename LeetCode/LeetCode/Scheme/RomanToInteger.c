//
//  RomanToInteger.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/11.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "RomanToInteger.h"

#include <stdlib.h>
#include <string.h>

int getValue(char c);

int romanToInt(char* s)
{
    int sum = 0;
    
    for (int i = 0; i < strlen(s); i++)
    {
        if (getValue(s[i]) < getValue(s[i+1]))
        {
            sum -= getValue(s[i]);
        }
        else
        {
            sum += getValue(s[i]);
        }
    }
    
    return sum;
}

int getValue(char c)
{
    int value = 0;
    switch(c)
    {
        case 'I':
        {
            value = 1;
            break;
        }
        case 'V':
        {
            value = 5;
            break;
        }
        case 'X':
        {
            value = 10;
            break;
        }
        case 'L':
        {
            value = 50;
            break;
        }
        case 'C':
        {
            value = 100;
            break;
        }
        case 'D':
        {
            value = 500;
            break;
        }
        case 'M':
        {
            value = 1000;
            break;
        }
        default:
        {
            
        }
    }
    return value;
}
