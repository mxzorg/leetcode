//
//  removeNthFromEnd.c
//  LeetCode
//
//  Created by zhongyafeng on 2018/8/15.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "removeNthFromEnd.h"

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    
    struct ListNode *p = head;
    struct ListNode *q = head;
    for (int i = 0; i < n+1; i++) {
        if (q != NULL) {
            q = q->next;
        }else{
            if (n == 1 && i == 1) {
                return NULL;
            } else if (n == i) {
                head = head->next;
            }
            return head;
        }
    }
    
    while (q != NULL) {
        q = q->next;
        p = p->next;
    }
    
    p->next = p->next->next;
    return head;
}
