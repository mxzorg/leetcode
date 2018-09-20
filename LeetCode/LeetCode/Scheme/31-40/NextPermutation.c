//
//  NextPermutation.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/9/20.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "NextPermutation.h"

static void swap(int *nums, int t1, int t2) {
    int t = nums[t1];
    nums[t1] = nums[t2];
    nums[t2] = t;
}

static void reverse(int *nums, int start, int end) {
    
    int i = start;
    int j = end;
    
    while(i<j) {
        swap(nums, i, j);
        i++;
        j--;
    }
}

void nextPermutation(int* nums, int numsSize) {
    
    int i = numsSize - 2;
    while(i >= 0 && nums[i+1] <= nums[i]) {
        i--;
    }
    
    if(i >= 0) {
        int j = numsSize -1;
        while(j >= 0 && nums[j]<=nums[i]) {
            j--;
        }
        swap(nums, i, j);
    }
    
    reverse(nums, i+1, numsSize-1);
}
