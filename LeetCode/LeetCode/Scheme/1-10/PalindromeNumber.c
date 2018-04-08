//
//  PalindromeNumber.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "PalindromeNumber.h"

bool isPalindrome(int x)
{
    if(x<0 || (x!=0 && x%10==0))
        return false;
    
    int sum=0;
    while(x>sum)
    {
        sum = sum*10+x%10;
        x = x/10;
    }
    return (x==sum)||(x==sum/10);
}
