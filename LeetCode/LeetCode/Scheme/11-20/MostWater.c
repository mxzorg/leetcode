//
//  MostWater.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "MostWater.h"


int maxArea(int* height, int heightSize)
{    
    int water = 0;
    int i = 0, j = heightSize - 1;
    while (i < j)
    {
        int h = height[i] < height[j] ? height[i] : height[j];
        water = water > ((j-i) * h) ? water : ((j-i)*h);
        
        while (height[i] <= h && i < j)
            i++;
        while (height[j] <= h && i < j)
            j--;
    }
    return water;
}

