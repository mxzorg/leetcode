//
//  MxFunctionList.m
//  GCDTFW
//
//  Created by Gemini_Mxz on 2017/7/27.
//  Copyright © 2017年 Z. All rights reserved.
//

#import "MxFunctionList.h"

@interface MxFunctionList ()<UITableViewDelegate, UITableViewDataSource>

@property (strong, nonatomic) UITableView *tableView;

@end

@implementation MxFunctionList

- (instancetype)init
{
    self = [super init];
    if (self) {
        
        [self configeViewInfo];
    }
    return self;
}

- (instancetype)initWithFrame:(CGRect)frame
{
    self = [super initWithFrame:frame];
    if (self) {
        
        [self configeViewInfo];
    }
    return self;
}

-(void)layoutSubviews
{
    [super layoutSubviews];
    
    _tableView.frame = self.bounds;
}

-(void)configeViewInfo
{
    _tableView = [[UITableView alloc] init];
    
    _tableView.delegate = self;
    _tableView.dataSource = self;
    
    [self addSubview:_tableView];
}

#pragma mark - UITableViewDataSource
-(NSInteger)tableView:(UITableView *)tableView numberOfRowsInSection:(NSInteger)section
{
    return _dataArray.count;
}

-(UITableViewCell *)tableView:(UITableView *)tableView cellForRowAtIndexPath:(NSIndexPath *)indexPath
{
    static NSString *nsCell = @"cell";
    
    UITableViewCell *cell = [tableView dequeueReusableCellWithIdentifier:nsCell];
    if (!cell)
    {
        cell = [[UITableViewCell alloc]initWithStyle:UITableViewCellStyleValue1 reuseIdentifier:nsCell];
    }
    
    cell.detailTextLabel.font = [UIFont systemFontOfSize:13];
    cell.accessoryType = UITableViewCellAccessoryDisclosureIndicator;
    cell.selectionStyle = UITableViewCellSelectionStyleNone;
    
    if (_dataArray.count > 0)
    {
        NSArray *array = [_dataArray objectAtIndex:indexPath.row];
        cell.textLabel.text = array[0];
        cell.detailTextLabel.text = array[1];
    }
   
    return cell;
}

#pragma mark － UITableViewDelegate
-(CGFloat)tableView:(UITableView *)tableView heightForRowAtIndexPath:(NSIndexPath *)indexPath
{
    return 50;
}

-(void)tableView:(UITableView *)tableView didSelectRowAtIndexPath:(NSIndexPath *)indexPath
{
    if (indexPath.row < _dataArray.count)
    {
        NSArray *array = [_dataArray objectAtIndex:indexPath.row];
        if ([self.objResponder respondsToSelector:NSSelectorFromString(array[1])])
        {
            SuppressPerformSelectorLeakWarning([self.objResponder performSelector:NSSelectorFromString(array[1])]);
        }
    }
}

@end
