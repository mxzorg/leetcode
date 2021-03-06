//
//  MaxSubArray.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/4/5.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "MaxSubArray.h"
/*
 
 思考1:（经过多次验证，还是未能通过，于是换了思考方式）
 先计算最优的左起点，然后求出累加的最优终点，
 如果终点是数组的最后一个元素，则所得最大和为所求，
 如果终点不是数组的最后一个元素，则应该反向计算一个最优右起点，
 如果最优的右起点在终点的左侧，则原计算结果为最大和，
 如果最优的右起点在终点的右侧，则应该反向计算一个终点，
 如果右终点在左起点的左侧，则原计算结果为最大和，
 否则比较两次计算的终点最大和。
 
 思考2:参考注释思路
 */

int maxSubArray(int* nums, int numsSize) {
    
    //先将起点设为第一个元素
    int maxSum = nums[0];
    int sum = nums[0];
    for(int i = 1; i < numsSize; i++){
        
        //累加求和
        sum += nums[i];
        if (sum > maxSum) {
            
            //记录增量
            maxSum = sum;
        }
        
        //如果累计和比单个元素小，则重新累计
        if (sum < nums[i]) {
            sum = nums[i];
        }
        
        //如果最大值比单个元素小，则重置最大值，并且重新累计
        if (maxSum < nums[i]) {
            maxSum = nums[i];
            sum = nums[i];
        }
    }
    
    return maxSum;
}



