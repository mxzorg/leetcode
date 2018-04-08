//
//  PlusOne.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/4/8.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "PlusOne.h"

#include <stdlib.h>
#include <string.h>

int* plusOne(int* digits, int digitsSize, int* returnSize) {
    
    int isCarry = 0;
    
    for (int i = digitsSize-1; i >=0; i--) {
        if (digits[i]==9) {
            digits[i]=0;
        }else{
            digits[i]++;
            isCarry = 1;
            break;
        }
    }
    
    if (isCarry == 1) {
        *returnSize = digitsSize;
        return digits;
    }
    
    int len = digitsSize+1;
    int *returnArray = (int *)malloc(sizeof(int)*(len));
    memcpy(returnArray+1, digits, sizeof(int)*(len));
    returnArray[0] = 1;
    *returnSize = len;
    return returnArray;
}
