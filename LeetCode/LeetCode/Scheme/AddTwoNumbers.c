//
//  AddTwoNumbers.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "AddTwoNumbers.h"

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode* res = (struct ListNode*)malloc(sizeof(struct ListNode));
    
    struct ListNode*p1 = l1;
    struct ListNode*p2 = l2;
    struct ListNode*p3 = res;
    
    int a=0,b=0,c=0,d=0;
    while(1)
    {
        if (p1 == NULL && p2 == NULL)
        {
            break;
        }
        a = (p1 !=NULL)?p1->val:0;
        b = (p2 !=NULL)?p2->val:0;
        c=(a+b+d)%10;
        d=(a+b+d)/10;
        
        struct ListNode *item = (struct ListNode*)malloc(sizeof(struct ListNode));
        item->val = c;
        item->next = NULL;
        
        p3->next = item;
        p3 = item;
        
        p1 = (p1 != NULL) ? p1->next:NULL;
        p2 = (p2 != NULL) ? p2->next:NULL;
    }
    
    if (d>0)
    {
        struct ListNode *item = (struct ListNode*)malloc(sizeof(struct ListNode));
        item->val = 1;
        item->next = NULL;
        p3->next = item;
    }
    return res->next;
}

