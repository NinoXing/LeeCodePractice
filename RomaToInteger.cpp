//
//  IntegerToRoma.cpp
//
//
//  Created by 邢阳 on 2018/11/21.
//

#include <stdio.h>

class Solution {
public:
    int RomaToInteger(string s) {
        string dict[13] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        int val[13] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        fot(int i=0; i<13; i++){
            int count=0;
            for(int k=0,k<s.size();k++){
                
            }
        }

        int ans;
        for(int i=0; i<13; i++) {
            if(num>=val[i]) {
                int count = num/val[i];
                num %= val[i];
                for(int j=0; j<count; j++) {
                    ret.append(dict[i]);
                }
            }
        }
        return ret;
    }
};

所以可以将单个罗马字符扩展成组合形式，来避免需要额外处理类似IX这种特殊情况
