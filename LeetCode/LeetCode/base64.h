//
//  base64.h
//  LeetCode
//
//  Created by Gemini_Vincent on 2018/8/16.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#ifndef base64_h
#define base64_h

#include <stdio.h>

int base64_decode(const char * base64, unsigned char * dedata);

int base64_encode(const unsigned char * sourcedata, char * base64);

void dealImage();
#endif /* base64_h */
