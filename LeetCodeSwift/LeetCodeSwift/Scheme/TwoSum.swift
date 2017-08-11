//
//  TwoSum.swift
//  LeetCodeSwift
//
//  Created by Gemini_Mxz on 2017/8/11.
//  Copyright © 2017年 Mxz. All rights reserved.
//

import Foundation

class TwoSum: NSObject {
    
    override init() {
        
    }
    
    func twoSum(_ nums: [Int], _ target: Int) -> [Int] {
        
        let dic = NSMutableDictionary.init();
        
        var index = 0;
        
        for item in nums {
        
            dic[NSString.init(format: "%d", item)] = NSString.init(format: "%d", index);
            index += 1;
        }
        
        index = 0;
        for one in nums {
        
            let two = target - one;
            
            let key = NSString.init(format: "%d", two);
            
            let obj = dic.object(forKey: key);
            
            if obj != nil {
            
                //return [index, obj];
            }
            
            index += 1;
            
        }
        
        
        let res = [0,0];
        return res;
    }
}
