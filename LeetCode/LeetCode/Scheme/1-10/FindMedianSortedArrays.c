//
//  FindMedianSortedArrays.c
//  LeetCode
//
//  Created by Gemini_Vincent on 2018/8/15.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "FindMedianSortedArrays.h"


double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    
    int l = 0, r = 0, m = 0;
    int t = (nums1Size + nums2Size) % 2;
    if (t == 0) {
        l = (nums1Size + nums2Size) / 2;
        r = l + 1;
    }else{
        m = (nums1Size + nums2Size) / 2 + 1;
    }
    
    int i = 0, j = 0;
    if (l != 0) {
        while (1) {
            r--;
            if (i >= nums1Size) {
                if (r == 0) {
                    double t1 = l;
                    double t2 = nums2[j];
                    return (t1 + t2) / 2.0;
                }else{
                    l = nums2[j];
                    j++;
                }
            }else if (j >= nums2Size) {
                if (r == 0) {
                    double t1 = l;
                    double t2 = nums1[i];
                    return (t1 + t2) / 2.0;
                }else{
                    l = nums1[i];
                    i++;
                }
            }else if (nums1[i] <= nums2[j]) {
                if (r == 0) {
                    double t1 = l;
                    double t2 = nums1[i];
                    return (t1 + t2) / 2.0;
                }else{
                    l = nums1[i];
                    i++;
                }
            }else{
                if (r == 0) {
                    double t1 = l;
                    double t2 = nums2[j];
                    return (t1 + t2) / 2.0;
                }else{
                    l = nums2[j];
                    j++;
                }
            }
        }
    }else{
        while (1) {
            m--;
            if (i >= nums1Size) {
                if (m == 0) {
                    return nums2[j];
                }else{
                    j++;
                }
            }else if (j >= nums2Size) {
                if (m == 0) {
                    return nums1[i];
                }else{
                    i++;
                }
            }else if (nums1[i] <= nums2[j]) {
                if (m == 0) {
                    return nums1[i];
                }else{
                    i++;
                }
            }else{
                if (m == 0) {
                    return nums2[j];
                }else{
                    j++;
                }
            }
        }
    }
}
