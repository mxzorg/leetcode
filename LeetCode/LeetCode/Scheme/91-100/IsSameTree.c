//
//  IsSameTree.c
//  LeetCode
//
//  Created by zhongyafeng on 2018/8/13.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "IsSameTree.h"


bool isSameTree(struct TreeNode* p, struct TreeNode* q) {
    
    if ((p == NULL && q != NULL) || (q == NULL && p != NULL)) {
        return false;
    }
    
    if (p == NULL && q == NULL) {
        return true;
    }
    
    if (p->val != q->val) {
        return false;
    }
    
    return (isSameTree(p->left, q->left) && isSameTree(p->right, q->right));
}
