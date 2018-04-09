//
//  AddBinary.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/4/9.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "AddBinary.h"

#include <string.h>
#include <stdlib.h>

char* addBinary(char* a, char* b) {
//    size_t lenA = strlen(a);
//    size_t lenB = strlen(b);
//    size_t lenC = lenA >= lenB ? lenA+2:lenB+2;
//    char *c = (char*)calloc(lenC, sizeof(char));
//    //char *c = (char*)malloc(sizeof(char)*lenC);
//    memset(c, 0, lenC);
//
//    long long i = (int)lenA;
//    long long j = (int)lenB;
//    long long k = (int)lenC-1;
//    i--;
//    j--;
//    k--;
//    int t = 0;
//    while (i >= 0 && j >= 0) {
//        int t1 = a[i] - '0';
//        int t2 = b[j] - '0';
//        int t3 = t1+t2+t;
//        if (t3 >= 2) {
//            t3 = t3 - 2;
//            t = 1;
//        }
//        c[k] = '0'+t3;
//
//        i--;
//        j--;
//        k--;
//    }
//
//    while (i >= 0) {
//        if (t==1) {
//            c[k]=a[i]+t;
//            t=0;
//        }else{
//            c[k]=a[i];
//        }
//        i--;
//        k--;
//    }
//
//    while (j >= 0) {
//        if (t==1) {
//            c[k]=b[j]+t;
//            t=0;
//        }else{
//            c[k]=a[j];
//        }
//        j--;
//        k--;
//    }
//
//    while (k >= 0) {
//        if (t==1) {
//            c[k]=t;
//            t=0;
//        }else{
//            c[k]='0';
//        }
//        k--;
//    }
//
//    int m = 0;
//    for (int n = 0; n < lenC; n++) {
//        if (c[n] == '0' && c[n+1] == '0' && m == 0) {
//            continue;
//        }else{
//            c[m++]=c[n];
//        }
//    }
//
//    c[m]='\0';
//    return c;
    
    int la = (int)strlen(a);
    int lb = (int)strlen(b);
    int lr = la > lb ? la : lb;
    int carry = 0;
    char *res = (char*)calloc(lr + 2, sizeof(char));
    res[lr + 1] = '\0';
    la--; lb--;
    while (la >= 0 || lb >= 0) {
        int ba = la >= 0 ? a[la--] - '0' : 0;
        int bb = lb >= 0 ? b[lb--] - '0' : 0;
        int br = ba ^ bb ^ carry;
        carry = (ba & bb) | (carry & (ba ^ bb));
        res[lr--] = br + '0';
    }
    if (!carry)
        return res + 1;
    res[0] = '1';
    return res;
}
