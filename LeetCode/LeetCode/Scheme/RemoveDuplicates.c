//
//  RemoveDuplicates.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/3/29.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "RemoveDuplicates.h"

//[2,3,3,3,44,44,50,66,66,66]

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize == 0) {
        return 0;
    }
    
    int i=0, j=1;
    while (j < numsSize) {
        if (nums[i] == nums[j]) {
            nums[j] = nums[j+1];
            j++;
        } else {
            nums[i+1]=nums[j];
            i++;
            j++;
        }
    }
    return i+1;
}
