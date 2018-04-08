//
//  ReverseInteger.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "ReverseInteger.h"

#include <limits.h>

int reverse(int x)
{
    long res = 0;

    while (1)
    {
        if (INT_MAX < res+x%10 || INT_MIN > res+x%10)
        {
            return 0;
        }
        res = res+x%10;
        
        x = x/10;
        if (x == 0)
        {
            break;
        }
        
        if (INT_MAX < res*10 || INT_MIN > res*10)
        {
            return 0;
        }
        res = res*10;
    }
    
    return (int)res;
}
