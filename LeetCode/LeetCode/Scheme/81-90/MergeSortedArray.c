//
//  MergeSortedArray.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/8/10.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "MergeSortedArray.h"


void change(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void changeArray(int *array, int left, int right){
    
    for (int i = left; i < right; i++) {
        if (array[i] > array[i+1]) {
            change(&array[i], &array[i+1]);
        }
    }
    
}

void mergeSortedArray(int* nums1, int m, int* nums2, int n) {
    
    int i = 0, j = 0;
    while (i < m+n) {
        
        if (i < m && j < n) {
            if (nums1[i] <= nums2[j]) {
                i++;
            }else{
                change(&nums1[i], &nums2[j]);
                changeArray(nums2, j, n);
                i++;
            }
        }else if (i >= m) {
            change(&nums1[i], &nums2[j]);
            i++;
            j++;
        }else if (j >= n) {
            printf("...");
        }else {
            printf("...");
        }
    }
}
