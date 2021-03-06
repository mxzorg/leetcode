//
//  ViewController.m
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/9.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#import "ViewController.h"

#import "MxHeaders.h"
#import "MxFunctionList.h"


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
    
    [self on4];
}


- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)loadFunctionListData
{
    NSArray *temp = @[
                      @[@"2.Add Two Numbers", @"on2"],
                      @[@"3.Longest Substring Without Repeating", @"on3"],
                      @[@"4. Median of Two Sorted Arrays", @"on4"],
                      @[@"5.Longest Palindromic Substring", @"on5"],
                      @[@"7.Reverse Integer", @"on7"],
                      @[@"8.String to Integer (atoi) ", @"on8"],
                      @[@"9.Palindrome Number", @"on9"],
                      @[@"10. Regular Expression Matching", @"on10"],
                      @[@"11.Container With Most Water", @"on11"],
                      @[@"12.Integer to Roman", @"on12"],
                      @[@"13.Roman to Integer", @"on13"],
                      @[@"14.Longest Common Prefix", @"on14"],
                      
                      @[@"19. Remove Nth Node From End of List", @"on19"],
                      @[@"20.Valid Parentheses", @"on20"],
                      @[@"21.Merge Two Sorted Lists", @"on21"],
                      
                      @[@"26.Remove Duplicates from Sorted Array", @"on26"],
                      @[@"27.Remove Element", @"on27"],
                      @[@"28.Implement strStr", @"on28"],
                      
                      @[@"31. Next Permutation", @"on31"],
                      @[@"35.Search Insert Position", @"on35"],
                      
                      @[@"53.Maximum Subarray", @"on53"],
                      
                      @[@"58.Length of Last Word", @"on58"],
                      
                      @[@"66.Plus One", @"on66"],
                      @[@"67.Add Binary", @"on67"],
                      
                      @[@"83. Remove Duplicates from Sorted List", @"on83"],
                      @[@"88. Merge Sorted Array", @"on88"],
                      
                      @[@"100. Same Tree", @"on100"],
                      
                      @[@"151.Reverse Words in a String", @"on151"], //未通过
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

-(void)on4
{
    int num1[] = {3};
    int num2[] = {-2, -1};
    
    double output = findMedianSortedArrays(num1, 1, num2, 2);
    printf("%f", output);
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
    
    NSLog(@"%d", myAtoi(str));
}

-(void)on10
{
    
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

-(void)on19
{
    NSArray *num = @[@(1), @(2)];
    
    struct ListNode * list = [self createItemWithArray:num];
    
    struct ListNode * temp = removeNthFromEnd(list, 2);
    [self outputList:temp];
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
        NSLog(@"%d", array[i]);
    }
}

-(void)on27
{
    int array[10] = {2,3,3,3,44,44,50,66,66,66};
    int len = removeElement(array, 10, 3);
    for (int i = 0; i < len; i++) {
        NSLog(@"%d", array[i]);
    }
}

-(void)on28
{
    char *str1 = "hello world";
    char *str2 = "llo";
    int index = MyStrStr(str1, str2);
    NSLog(@"%d", index);
}

-(void)on31
{
    
}

-(void)on35
{
    int src[] = {1,2,3,4,6,7};
    int target = 0;
    int index = searchInsert(src, 6, target);
    NSLog(@"%d", index);
}

-(void)on53
{
    int src[9] = {-2,1,-3,4,-1,2,1,-5,4};   //6
    //int src[10] = {0,-3,-2,-3,-2,2,-3,0,1,-1}; //2
    //int src[3] = {-2,-1,-2};
    //int src[3] = {-1,0,-2};
    //int src[4] = {-1,0,-2,2};
    //int src[2] = {1,2};
    //int src[5] = {8,-19,5,-4,20}; //21
    
    int sum = maxSubArray(src,9);
    NSLog(@"%d\n", sum);
}

-(void)on58
{
    char *str = "Hello world ";
    NSLog(@"%d", lengthOfLastWord(str));
}

-(void)on66
{
    int data[] = {9};
    int len = 0;
    int *res = plusOne(data, 1, &len);
    for (int i = 0; i < len; i++) {
        NSLog(@"%d", res[i]);
    }
}

-(void)on67
{
//    char *a = "0";
//    char *b = "0";
    
//    char *a = "110";
//    char *b = "00011";

    char *a = "11101110101101111001001101111110010101010110101001001111001100001000001010000110010100";
    char *b = "110011101101100101010011101101100000110010100110011000110000";
    
    char *c = addBinary(a, b);
    printf("%s",c);
}

-(void)on83
{
    NSArray *num = @[@(1), @(2), @(2), @(2), @(3), @(4), @(5)];
    struct ListNode * numList = [self createItemWithArray:num];
    struct ListNode * resList = deleteDuplicates(numList);
    [self outputList:resList];
}

-(void)on88
{
    int num1[6] = {1,2,3,0,0,0};
    int num2[3] = {2,5,6};
    
    mergeSortedArray(num1, 3, num2, 3);
    for (int i = 0; i < 6; i++) {
        NSLog(@"%d", num1[i]);
    }
}

-(void)on100
{
    
}

-(void)on151
{

}

#pragma mark - 辅助函数
-(struct ListNode*)createItemWithArray:(NSArray*)num
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

-(void)outputList:(struct ListNode*)list
{
    while (list) {
        
        NSLog(@"%d", list->val);
        list = list->next;
    }
    
}


@end
