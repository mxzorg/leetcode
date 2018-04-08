//
//  WithoutRepeatingCharacters.c
//  LeetCode
//
//  Created by Gemini_Mxz on 2017/8/10.
//  Copyright © 2017年 Mxz. All rights reserved.
//

#include "WithoutRepeatingCharacters.h"

#include <string.h>

int lengthOfLongestSubstring(char* s)
{    
    size_t len = strlen(s);
    int max = 0;
    int left = 0, right = 0;
    for (int i = 0; i < len; i++)
    {
        int hasRepeat = 0;
        right = i;
        for(int j = right-1; j >= left; j--)
        {
            if (s[i] == s[j])
            {
                max = (right-left)>max?(right-left):max;
                
                left = j+1;
                
                hasRepeat = 1;
                break;
            }
        }
        
        if (hasRepeat == 0)
        {
            max = (right-left+1)>max?(right-left+1):max;
        }
    }
    
    return max;
}
