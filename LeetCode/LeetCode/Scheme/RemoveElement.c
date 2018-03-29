//
//  RemoveElement.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/3/30.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "RemoveElement.h"

int removeElement(int* nums, int numsSize, int val) {
 
    if (numsSize == 0) {
        return 0;
    }
    
    if (numsSize == 1) {
        if (nums[0] == val) {
            return 0;
        }else{
            return 1;
        }
    }
    
    int i = 1;
    while (i < numsSize) {
        if (val == nums[i-1]) {
            nums[i-1] = nums[i];
        }else{
            i++;
        }
    }
    return i;
}
