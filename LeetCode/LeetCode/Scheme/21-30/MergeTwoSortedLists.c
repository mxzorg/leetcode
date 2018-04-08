//
//  MergeTwoSortedLists.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/20.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "MergeTwoSortedLists.h"

#include <stdlib.h>

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2)
{
    if(l1 == NULL)
        return l2;
    
    if(l2 == NULL)
        return l1;
    
    if(l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l2->next, l1);
        return l2;
    }
}
