//
//  SearchInsert.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/3/30.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "SearchInsert.h"

int searchInsert(int* nums, int numsSize, int target) {
    
    int index = 0;
    while (index < numsSize) {
        if (nums[index] == target || nums[index] > target) {
            break;
        } else {
            index++;
            if (index < numsSize && nums[index] > target) {
                break;
            }
        }
    }
    
    return index;
}
