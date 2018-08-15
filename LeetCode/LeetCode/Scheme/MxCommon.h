//
//  MxCommon.h
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/21.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#ifndef MxCommon_h
#define MxCommon_h

struct TreeNode {
    
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct ListNode {
    
    int val;
    struct ListNode *next;
};


struct StackNode {
    
    struct StackNode *pForword;
    struct StackNode *pNext;
    
    char value;
};

struct StackNode* stackPush(struct StackNode* stack, char cValue);

struct StackNode* stackPop(struct StackNode* stack);

void stackClean(struct StackNode* stack);


#endif /* MxCommon_h */
