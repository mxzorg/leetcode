//
//  MaxSubArray.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/4/5.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "MaxSubArray.h"
/*
 先计算最优的左起点，然后求出累加的最优终点，
 如果终点是数组的最后一个元素，则所得最大和为所求，
 如果终点不是数组的最后一个元素，则应该反向计算一个最优右起点，
 如果最优的右起点在终点的左侧，则原计算结果为最大和，
 如果最优的右起点在终点的右侧，则应该反向计算一个终点，
 如果右终点在左起点的左侧，则原计算结果为最大和，
 否则比较两次计算的终点最大和。
 */
int maxSubArray(int* nums, int numsSize) {
    
    int maxSum = nums[0];
    int sum = maxSum;
    for(int i = 1; i < numsSize; i++){
        
        sum += nums[i];
        if (sum > maxSum) {
            //重新计算最优起点
            if (sum < nums[i]) {
                maxSum = nums[i];
                sum = maxSum;
            }else{
                maxSum = sum;
            }
        } else if (maxSum < nums[i]) {
            //重新计算最优起点
            sum = nums[i];
            maxSum = nums[i];
        } else if (sum < nums[i]) {
            //重新计算最优起点
            sum = nums[i];
        }
    }
    
    return maxSum;
}



