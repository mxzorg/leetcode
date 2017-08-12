//
//  IntegerToRoman.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/11.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "IntegerToRoman.h"

#include <stdlib.h>
#include <string.h>

char* intToRoman(int num)
{
    char* M[] = {"", "M", "MM", "MMM"};
    char* C[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* X[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* I[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    
    char* res = (char*)malloc(sizeof(char)*15);
    memset(res, 0, 5);
    
    int m = num/1000;
    int c = (num%1000)/100;
    int x = (num%100)/10;
    int i = (num%10);
    
    strcat(res, M[m]);
    strcat(res, C[c]);
    strcat(res, X[x]);
    strcat(res, I[i]);
    
    return res;
}
