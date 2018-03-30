//
//  ViewController.m
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/9.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#import "ViewController.h"

#import "MxFunctionList.h"


#include "MxCommon.h"



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
                      @[@"2.Add Two Numbers", @"on2"],
                      @[@"3.Longest Substring Without Repeating", @"on3"],
                      
                      @[@"5.Longest Palindromic Substring", @"on5"],
                      @[@"7.Reverse Integer", @"on7"],
                      @[@"8.String to Integer (atoi) ", @"on8"],
                      @[@"9.Palindrome Number", @"on9"],
                      
                      @[@"11.Container With Most Water", @"on11"],
                      @[@"12.Integer to Roman", @"on12"],
                      @[@"13.Roman to Integer", @"on13"],
                      @[@"14.Longest Common Prefix", @"on14"],
                      
                      @[@"20.Valid Parentheses", @"on20"],
                      @[@"21.Merge Two Sorted Lists", @"on21"],
                      
                      @[@"26.Remove Duplicates from Sorted Array", @"on26"],
                      @[@"27.Remove Element", @"on27"],
                      @[@"28.Implement strStr", @"on28"],
                      
                      @[@"35.Search Insert Position", @"on35"],
                      
                      
                      @[@"LeetCode151", @"onReverseWords"],
                      ];
    
    self.functionList.dataArray = temp;
}

-(void)on2
{
    NSArray *num1 = @[@(1), @(2), @(3), @(4), @(5)];
    NSArray *num2 = @[@(3), @(2), @(1), @(9), @(2)];
    
    struct ListNode * numList1 = [self createItemWithArray:num1];
    struct ListNode * numList2 = [self createItemWithArray:num2];
    
    struct ListNode * resList = addTwoNumbers(numList1, numList2);
    
    [self outputList:resList];
}

-(void)on3
{
    char *input = "abcabcbb"; // abcabcbb bbb aab
    int output = lengthOfLongestSubstring(input);
    
    NSLog(@"%s=%d",input, output);
}

-(void)on5
{
    char *input = "abc"; // cbbd babad
    char *output = longestPalindrome(input);
    
    NSLog(@"%s=%s", input, output);
}

-(void)on7
{
    int input = -2147483648;
    int ouput = reverse(input);
    
    NSLog(@"%d=%d", input, ouput);
}


-(void)on8
{
    char *str = "123123";
    
    printf("%d", myAtoi(str));
}

-(void)on9
{
    int input = 1;
    int output = isPalindrome(input);
    
    NSLog(@"%d", output);
}

-(void)on11
{
    int input[] = {123,223,11};
    int output = maxArea(input, 3);
    
    NSLog(@"%d", output);
}

-(void)on12
{
    int input = 1234;
    char *output = intToRoman(input);
    
    NSLog(@"%s", output);
}

-(void)on13
{
    char *input = "MCMXCVI";
    int output = romanToInt(input);
    
    NSLog(@"%d", output);
    
}

-(void)on14
{
    char *input[] = {"ab", "aa"};
    char *output = longestCommonPrefix(input, 2);
    
    NSLog(@"%s", output);
}

-(void)on20
{
    char *input = "[";
    bool output = isValid(input);
    
    NSLog(@"%@", output?@"匹配":@"未匹配");
}

-(void)on21
{
    NSArray *num1 = @[@(1), @(2), @(7), @(8), @(9)];
    NSArray *num2 = @[@(2), @(4), @(6), @(9), @(9)];
    
    struct ListNode * numList1 = [self createItemWithArray:num1];
    struct ListNode * numList2 = [self createItemWithArray:num2];
    
    struct ListNode * resList = mergeTwoLists(numList1, numList2);
    
    [self outputList:resList];
}

-(void)on26
{
    int array[10] = {2,3,3,3,44,44,50,66,66,66};
    int len = removeDuplicates(array, 10);
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
    }
}

-(void)on27
{
    int array[10] = {2,3,3,3,44,44,50,66,66,66};
    int len = removeElement(array, 10, 3);
    for (int i = 0; i < len; i++) {
        printf("%d", array[i]);
    }
}

-(void)on28
{
    char *str1 = "hello world";
    char *str2 = "llo";
    int index = MyStrStr(str1, str2);
    printf("%d", index);
}

-(void)on35
{
    int src[] = {1,2,3,4,6,7};
    int target = 0;
    int index = searchInsert(src, 6, target);
    printf("%d", index);
}


-(void)onReverseWords
{
    char *str = "abc";
    char * tstr = (char*)malloc(strlen(str)+1);
    strcpy(tstr, str);
    
    NSLog(@"%s", reverseWords2(tstr));
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
