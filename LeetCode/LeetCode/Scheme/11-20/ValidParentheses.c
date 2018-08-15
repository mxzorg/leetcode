//
//  ValidParentheses.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/21.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "ValidParentheses.h"

#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#include "MxHeaders.h"

static struct StackNode *gloabStack;
static int StackSize = 0;


bool isValid(char* s)
{
    //初始化全局栈
    if (StackSize != 0) {
        stackClean(gloabStack);
        gloabStack = NULL;
    }
    
    gloabStack = (struct StackNode*)malloc(sizeof(struct StackNode));
    gloabStack->pNext = NULL;
    gloabStack->pForword = NULL;
    gloabStack->value = '\0';
    
    StackSize = 0;
    
    bool flag = true;
    
    size_t len = strlen(s);
    
    for (int i = 0; i < len; i++) {
        
        char c = s[i], t = '\0';
        
        if (gloabStack) {
            
            t = gloabStack->value;
        }
        
        if (c == t || StackSize == 0) {
            
            gloabStack = stackPush(gloabStack, c);
            StackSize++;
        }
        else
        {
            switch (c) {
                case ')':
                    if (t == '(') {
                        gloabStack = stackPop(gloabStack);
                        StackSize--;
                    } else {
                        flag = false;
                    }
                    break;
                    
                case ']':
                    if (t == '[') {
                        gloabStack = stackPop(gloabStack);
                        StackSize--;
                    } else {
                        flag = false;
                    }
                    break;
                    
                case '}':
                    if (t == '{') {
                        gloabStack = stackPop(gloabStack);
                        StackSize--;
                    } else {
                        flag = false;
                    }
                    break;
                    
                default:
                    gloabStack = stackPush(gloabStack, c);
                    StackSize++;
                    break;
            }
        }
        
        if (!flag) {
            break;
        }
    }
    
    if (StackSize != 0) {
        flag = false;
    }
    
    return flag;
}
