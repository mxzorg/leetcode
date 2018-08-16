//
//  base64.c
//  LeetCode
//
//  Created by Gemini_Vincent on 2018/8/16.
//  Copyright © 2018年 Mxz. All rights reserved.
//

#include "base64.h"

#include <stdio.h>
#include <string.h>

// 全局常量定义
const char * base64char = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
const char padding_char = '=';

/*编码代码
 * const unsigned char * sourcedata， 源数组
 * char * base64 ，码字保存
 */
int base64_encode(const unsigned char * sourcedata, char * base64)
{
    int i=0, j=0;
    unsigned char trans_index=0;    // 索引是8位，但是高两位都为0
    const int datalength = (int)strlen((const char*)sourcedata);
    for (; i < datalength; i += 3){
        // 每三个一组，进行编码
        // 要编码的数字的第一个
        trans_index = ((sourcedata[i] >> 2) & 0x3f);
        base64[j++] = base64char[(int)trans_index];
        // 第二个
        trans_index = ((sourcedata[i] << 4) & 0x30);
        if (i + 1 < datalength){
            trans_index |= ((sourcedata[i + 1] >> 4) & 0x0f);
            base64[j++] = base64char[(int)trans_index];
        }else{
            base64[j++] = base64char[(int)trans_index];
            
            base64[j++] = padding_char;
            
            base64[j++] = padding_char;
            
            break;   // 超出总长度，可以直接break
        }
        // 第三个
        trans_index = ((sourcedata[i + 1] << 2) & 0x3c);
        if (i + 2 < datalength){ // 有的话需要编码2个
            trans_index |= ((sourcedata[i + 2] >> 6) & 0x03);
            base64[j++] = base64char[(int)trans_index];
            
            trans_index = sourcedata[i + 2] & 0x3f;
            base64[j++] = base64char[(int)trans_index];
        }
        else{
            base64[j++] = base64char[(int)trans_index];
            
            base64[j++] = padding_char;
            
            break;
        }
    }
    
    base64[j] = '\0';
    
    return 0;
}

/** 在字符串中查询特定字符位置索引
 * const char *str ，字符串
 * char c，要查找的字符
 */
int num_strchr(const char *str, char c)
{
    const char *pindex = strchr(str, c);
    if (NULL == pindex){
        return -1;
    }
    return (int)(pindex - str);
}

/* 解码
 * const char * base64 码字
 * unsigned char * dedata， 解码恢复的数据
 */
int base64_decode(const char * base64, unsigned char * dedata)
{
    int i = 0, j=0;
    int trans[4] = {0,0,0,0};
    for (;base64[i]!='\0';i+=4){
        // 每四个一组，译码成三个字符
        trans[0] = num_strchr(base64char, base64[i]);
        trans[1] = num_strchr(base64char, base64[i+1]);
        // 1/3
        dedata[j++] = ((trans[0] << 2) & 0xfc) | ((trans[1]>>4) & 0x03);
        
        if (base64[i+2] == '='){
            continue;
        }
        else{
            trans[2] = num_strchr(base64char, base64[i + 2]);
        }
        // 2/3
        dedata[j++] = ((trans[1] << 4) & 0xf0) | ((trans[2] >> 2) & 0x0f);
        
        if (base64[i + 3] == '='){
            continue;
        }
        else{
            trans[3] = num_strchr(base64char, base64[i + 3]);
        }
        
        // 3/3
        dedata[j++] = ((trans[2] << 6) & 0xc0) | (trans[3] & 0x3f);
    }
    
    dedata[j] = '\0';
    
    return 0;
}

//test
void dealImage(){
    
    char *p = "iVBORw0KGgoAAAANSUhEUgAAAhwAAAECCAMAAACCFP44AAABWVBMVEX////hBgEjGdzjFxL29v78/P8rId7U0vgnHt3z8v3Qzfh+eetBOOE0K9/a2PlmX+dTTOT6+v4wJ97i4PqxrfOLhu07MuDlIR3t7PykoPGRjO7xhYL//PwtJN7hCQTd3PpeVuVHPuLEwvbAvfWfmvCale+Dfew4L+AmHNz61tXkHBjMyve1svNzbelORuPm5fv+9vaUj+54cupLQuL1rKrq6fy8ufSqpvJuZ+j4wb/3vbvwfnztZGHpREHnNDDmLirjEw7iDwr97+9aUuX73dziDAf5+f7v7vyHguz85+ZjXOY9NODrWFXlKSXo5/v84uHylZK4tfT96+phWuZDOuH0oJ7ta2joPDjl5Pv++fnHxPZqY+f2tLLyj4zw8P3Jxvb4xcT0pqTpSUZ7deprZehfWOb5ycjoQDzlJSH3ubfzmZfxiYbucG7rXlvqTkv5z875zMvvdnT3urg5fTwpAAAM3ElEQVR42uzaTUtbQRQG4MNBoybVWI1BBVHxo4HWioKte6FKCwVpVwrtpv//N3RzDaa5d+jKxfg867Obw7zzcQIAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAB4Ab92huPl3rc/o4WA5xZ297KxerwYMLV2mM+sfw9o/N7IGeP9UiMdD67vjr4Er0K/l/8Yn0eHh5smfHZXgvptj3POx/ad4fY6p1bvg+oNs8VdtFiabaOtoHL32WayFHOO9nLW9dugZos/s9XBfG8szxUN3XqrNsoO/eKxtXEaVGw9O5zFjKt32eZTUK217NJbmUmfm2y1ehvUajc7jeKZk+wwCGo1TZVyrmz2ssNkM6jTwiQ7jWffQmwdr837LNiOJ/3stuGPv1I7WfAQTx6z4ENQpa0s+ByNq0kWXAZVOsuCi2hcZMmboErDLNiKxmEWme2o048sGDylSpbtBzX6mgWnTdFRli0FNXr8n1jZybK1oEaXWXAyfWIvOw9qVFz3UVN0l0V7hjrqNMqCflM0yKKD4C9799mWxhIGYPidV7p0VECKggXB3o29xq6Jx5poeu85///DSU4k7sDuMNtgF+f+aAzrtTwXu8zM7jalIDI4+OLoBKEpOTOoaJIaRlWWB6E5MQY6+vkGSANilXGzSqKivPR3xJT9PZQYQAUFJ9zKiyGwZudta93wT3b390RAaq7mzAokkGEPBLvz7rgQ5S5zHUR5nlEAnok3Hwg2N1hAicJQ7VPSVr5VHyEQbK7Ng7TWCJQFPSgjkADgWCXoEjOydjczgJX2HOwh9DaQGlGefhHsLRbFav9E4Jazu+bSv8co762YVrG7DZTzGsqeTSqWw1734Rc3cLG7tlrrhyERRkrIARWmO+TaENcz2Z3Tj/Iyo1DmaMU7nnEnVAlW1zF5CYLNtaGSN3DH111O400Q5IyGkTYhLmayvzDnANZl8nXoaetsAhQ4Zzvwzkge7kR6+jc6MujZ725/Lk5RbaQLDRvBcs5M+PE3/8QT6ga3AbyznxRXKthGp7GrPx0xd9czkHKfIs3/HAR7CCNDL+jW45J7WcEOtpHlH9DLXW5D3ITSfmaQpQA6Ofz4i/jssKdOZHKa9PIeMZNvA0+RaRp08WZQQU6sLLW+SVOvZOzFX8SBxa5cpl4DPYKKCmK4w+ocyDYIelwiQxsI1uY1NY5ZZNgAwdocpt5aoxUZBhIgWFtG2015Rmdbu3P+03CofcbBGn0Vdxm0sxwyeUGGtzeMd1xzz0FBAVl2QLC2OWSJQjXHeBQrbPhAjhOZnoJgbX3IMgJVhgooo9UB1UaRKQyCtblR1f1lvcMoLxdU+9o4CYLFdagZi+g6RSXRPFQatFYcRAoEDv2obGAaKO4AKvPMQIW8iMPmuvjv5hULIIsnD7QeZMpBLfcsDsJlNX5xsHC9a/LG4Y8Q70hEwo9sLrc4rOhB1Iiff0ybH4cbleScIPUWa+lI0HFY69tKc8XxSzx1YnYcMIEKZkAqibW9BSkf1y8TA4DOl7JGN0S11dSYyXF4/TzPBh3NIIc++nSGaULEQSMarPwwKQ72IuCwA6RCyMPVxT/l2ynioBEttl6aEwfz8oHwNkgNIZ+RCNyJIkubiINGtDkzNw4YDCD7StfpKHJq5Z6VDYo4DIkje21uHDD9FKUme4Di7EZujznXcwScIg4a0ahl14Q4KL5hF/5RGH4CFcaRXzTGdywaBhEHjWh1YEYcNMdgsrO9bygIVXoGkMJ72uF1obIZEUcFotkLM+NgC0ZRldc8D5fcd4o4DIvjoGFxjHagSn1wq2sAlcyC8XFY4R1uSBxb6w2KwzuJqs3UnPMdcQKHB/SADzDRcdTqxYI9Ee1eQkM4NlA9l6/8v0dQVrQLeCwRqdT9igMUjBXPDrKEdg6N4OhGLQKX8EdCtg7XE1D/wUGKIo6y74eEcgH1wW4D/kKmXKL8CsNYxe8GDR8cKyDi+OskTqRKUH/eDdQYB4544daTisBc7V7Q8sGRUhcHqc3a31aAKUWkslB3iRHkjIM9cdc1/rYD/4juzXqB0xKhFEUcElOEss57VltaXvy0C/rFTlFHHNj9ECS8Xb78c/c0yCA63cs45plxsGVfzev9KusroK44MBSBKiIOrXGwj7lplTtzaVNXHPkMsuPgqUPEUZ/DSovqnbl2pmPjQx7UHQfuPRRxmBTHApFa1rAzFzRvPDmABsSB3Q4RhzlxLBOpRS07c0HbxiP9iIbEgRsOEYcZcVwTyiNNO/OTlo0fhdGoODC8bXoc93AQrFgilKKmnbn1Tv3GnwfQuDgwdyniMDqOqRZCOdS4Mw/H1G581oNGxoEdQRGHkXHsnl2QCjdad+aCyo13Is01NzQKMpBbdFDEwYOwrbb8b1XmX9a17sytY1VxtCIlOr4N8uQ/R2R/6hri3inA6R7GoWwB+GwutJAKX5hxsNuYSwDoiaOsz6JxzDdDHCtjwGt9kdDWdvnjaEcpzyyAMXHgRMSKcRTjTRDHahFUSBHaZ+44kowlOfriwHCigXHQrDa+oS+OtXlQ5RuhrPDGMehh3IxFZxy4HxRxmBBH/B2o84DQOONIFFCqFwyNAwNBS8dxCKo1Po7s4gmoNKYtjjnWI7z0x4H7CSvHkQLVrBDHJqilKY4ZlHLFDI8DN5zWjeNwDNSyQByEbKWu6hBHxI9S/fCXoy+HZbriwF7LxnFYhIYj2rw/MT+OJEoNHEFZTwHRoDgyR5aMY2v58zo0HtEoXjQ7DqcfpfagLO9Bw+LA12bEYcnhTg2IVqVNoF1NHZQIg9o4ZpTuXXyKBsbhOTJop4g4pA6pD770WZwwaIgjpPDkPzcaGQe2izgUEe2+wp2TV4RBSxyODFIccGvc2Dj2nXWLg7BZbyyM9w8pLpRIpX+pdUAGx9GDFBeU/WNsHOiuWxxbzRoHwFVqi9CW4dZmnBgex7jSU3j8BscxXrc4Vps3DoD5NUJ7cDvtekiMj+MNUgJQFjU4jj0Rh7HXrdDrz78SE+KYREoGygoGx7FftzhamjoOeEUopTQ1q2ZoHB2ocEIaNjiOAWe94og3dxxThFaEXy5MiSOj9BD7ToPjwCNLx3F4DQ1DaCqn3qcA4AVhMC6OIbgVMzqOrnrF8YGotqb5KQT1j+MHqb6uaZFQsj+PDRk+LyCtH8rmDI4jWK/h881vhPatCLR/lwjl4Bi0qn8cHwktBXC1ylgjpiOOHNL8UDbdwRNHB3ccl/WbW/m4QijZxV34Kz11QSgr86Bd/eNIVccxTygvwaA4QsqDVUE/Rxzt3HF46xcHpG9aiPzTa9IvK8JZvUmDDvWPY7k6jkf0VD4YFUc74+kHjr4RV604IjsBvjg89Z2VPTnPEkr8LA1w9ekDoS3uQsNpGOegzznO6R8YFkcbVnAdcawEGwU2rJar95T99yVCW/54U6r80QuwADVxHMdJhWuAA/qoYlgcl1hpmOONT6qP403913NMxQlTy6OGH1HUxvEiTiodV151kDIsDvBjpbbab7z/oeo4+uofB4yl1oii7PkJWANvHLsvX5EqJaj85FhJGxbHDlL4rlvBHdVx+OoUB+34K1Fw8R2sguixCADnhPIlbVQcPqziaqv9xveqjCPqrFsctBfLREbpDKyD6DEPAI8I7f0Dg+KAHFab2K75xrdGVMUx3LA1pOmzLKn0xQrrig2JYwV+2SQ8tMTRizICndO13nh/m5o4eoyJ44X6OE4OSJXlqSuwDqLDFPz2nrDoiMMRQDmep8lYjTf+tD3IG0fBaUgcmytq4zheaCFySufXFhjh0B3HK2rwg0FjHNCL5tuBRiww3nz0KksUWHfKXoXSbeDpZcKgJ46HOTSbZ9T6t5oEXtaJY+0d3PqxRRh0xAGDA2iy1za4Dynwskwcq/Pw1yfCoCcOGEdzBbbNiGNNdRxL5RH1pohjuQgSPwmDnjhgDk01BGbEcaEyjqUHkL4dMm2COLI/x4DyOUsYdMQRCaGJ+sGUOG444qDS+G3z6+99aPs4tmTuzzH/gTBojwMiw2iaCacpcXwY448je/BO8uU2Tuwdx9bSo3WQMfa5RNj446AlM2iOHXOGjeNF4I0jvnAMUul3CxdZO8axVlpZWrx5MAZKrq6/HBIGrXFALIQ1BLpb+9ry7q5YLOYefJzsD516sJbAY9U7Za2lpvj7m3Xgi+PD+bw1JuZtzj3sQgX7e50zR1Al4usNZVCZp38bhCbheNzfvR/Fv6L+kVB/35DPC8oe5tvDAyino/0IhCbjfPYs9sv2M+DlzffNTbpQIro37nOCINyadvfMJnv7krOPfQkQBEEQBOG/9uCQAAAAAEDQ/9eeMAIAAAAAAAAAAAAAAAAAAAAAwC4tYlrOBhwFqQAAAABJRU5ErkJggg==";
    
    unsigned char dedata[10240];
    
    int len = base64_decode(p,dedata);
    printf("%d", len);
    
    FILE *f = fopen("/Users/gemini_vincent/Desktop/temp.jpg", "wb");
    fwrite(dedata, sizeof(char), len, f);
    fclose(f);
}

