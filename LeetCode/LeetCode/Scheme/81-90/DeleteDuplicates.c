//
//  DeleteDuplicates.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2018/8/9.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "DeleteDuplicates.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if(!head)
        return head;
    
    int t = head->val;
    struct ListNode *p = head->next;
    struct ListNode *pl = head;
    while(p){
        
        if(t == p->val){
            p = p->next;
        }else{
            pl->next = p;
            pl = p;
            t = pl->val;
        }
    }
    pl->next = NULL;
    return head;
}
