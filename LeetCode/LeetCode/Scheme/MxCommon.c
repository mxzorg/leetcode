//
//  MxCommon.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/21.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "MxCommon.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct StackNode* stackPush(struct StackNode* stack, char cValue)
{
    struct StackNode *pNode = (struct StackNode*)malloc(sizeof(struct StackNode));
    pNode->value = cValue;
    pNode->pForword = stack;
    pNode->pNext = NULL;
    
    stack->pNext = pNode;

    return pNode;
}

struct StackNode* stackPop(struct StackNode* stack)
{
    struct StackNode *pNode = stack;
    
    if (stack->pForword) {
        stack = stack->pForword;
        stack->pNext = NULL;
    }
    else
    {
        stack = NULL;
    }
    free(pNode);
    pNode = NULL;
    
    return stack;
}

void stackClean(struct StackNode* stack)
{
    while (stack) {
        
        stack = stackPop(stack);
    }
}
