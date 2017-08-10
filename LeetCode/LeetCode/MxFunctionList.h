//
//  MxFunctionList.h
//  GCDTFW
//
//  Created by Gemini_Mxz on 2017/7/27.
//  Copyright © 2017年 Z. All rights reserved.
//

#import <UIKit/UIKit.h>

//去掉preformSelector警告宏
#define SuppressPerformSelectorLeakWarning(Stuff) \
do { \
_Pragma("clang diagnostic push") \
_Pragma("clang diagnostic ignored \"-Warc-performSelector-leaks\"") \
Stuff; \
_Pragma("clang diagnostic pop") \
} while (0)


@interface MxFunctionList : UIView

@property (strong, nonatomic) NSArray *dataArray;

@property (weak, nonatomic) id objResponder;

@end
