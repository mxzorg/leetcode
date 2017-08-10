//
//  ViewController.m
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/9.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#import "ViewController.h"

#import "MxFunctionList.h"

#import "AddTwoNumbers.h"
#import "ReverseWords.h"
#import "StringToInteger.h"


@interface ViewController ()

@property (nonatomic, weak) MxFunctionList *functionList;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view, typically from a nib.
    
    MxFunctionList *list = [[MxFunctionList alloc] initWithFrame:CGRectMake(0, 20, self.view.bounds.size.width, self.view.bounds.size.height-20)];
    list.objResponder = self;
    [self.view addSubview:list];
    
    self.functionList = list;
    
    [self loadFunctionListData];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

-(void) loadFunctionListData
{
    NSArray *temp = @[
                      @[@"LeetCode2", @"onAddTwoNumbers"],
                      @[@"LeetCode8", @"onStringToInteger"],
                      @[@"LeetCode151", @"onReverseWords"],
                      ];
    
    self.functionList.dataArray = temp;
}

-(void)onAddTwoNumbers
{
    NSArray *num1 = @[@(1), @(2), @(3), @(4), @(5)];
    NSArray *num2 = @[@(3), @(2), @(1), @(9), @(2)];
    
    struct ListNode * numList1 = [self createItemWithArray:num1];
    struct ListNode * numList2 = [self createItemWithArray:num2];
    
    struct ListNode * resList = addTwoNumbers(numList1, numList2);
    
    [self outputList:resList];
}

-(void)onStringToInteger
{
    char *str = "123123";
    
    printf("%d", myAtoi(str));
}

-(void)onReverseWords
{
    char *str = "Hello world";
    char * tstr = (char*)malloc(strlen(str)+1);
    strcpy(tstr, str);
    
    NSLog(@"%s", reverseWords(tstr));
}









#pragma mark - 辅助函数

-(struct ListNode*) createItemWithArray:(NSArray*)num
{
    struct ListNode* numList = NULL;
    struct ListNode* temp = NULL;
    for (NSNumber *item in num) {
        
        struct ListNode* num = (struct ListNode*)malloc(sizeof(struct ListNode));
        if (temp == NULL)
        {
            numList = num;
        }
        else
        {
            temp->next = num;
        }
        
        num->val = item.intValue;
        num->next = NULL;
        temp = num;
    }
    
    return numList;
}

-(void) outputList:(struct ListNode*)list
{
    while (list) {
        
        NSLog(@"%d", list->val);
        list = list->next;
    }
    
}


@end