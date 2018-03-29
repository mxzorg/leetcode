//
//  MxCommon.h
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/21.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#ifndef MxCommon_h
#define MxCommon_h

#include "AddTwoNumbers.h"
#include "ReverseWords.h"
#include "StringToInteger.h"
#include "WithoutRepeatingCharacters.h"
#include "LongestPalindromicSubstring.h"
#include "ReverseInteger.h"
#include "PalindromeNumber.h"
#include "MostWater.h"
#include "IntegerToRoman.h"
#include "RomanToInteger.h"
#include "MergeTwoSortedLists.h"
#include "ValidParentheses.h"
#include "LongestCommonPrefix.h"
#include "RemoveDuplicates.h"
#include "RemoveElement.h"


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
