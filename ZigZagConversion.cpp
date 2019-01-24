//
//  ZigZagConversion.cpp
//  
//
//  Created by 邢阳 on 2018/11/20.
//

#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    string s = "PAYPALISHIRING";
    int n=3;
    int l=s.size()/n
    char ans[l][n];
    memset(&ans,"0",sizeof(ans))
    
    for (int i=0 ; i<n ; i++){
        
        int rownumber = i/(n-1);
        if (rownumber % 2 == 0){
            ans[i % (rownumber*4) ][ rownumber*2 ] = s[i];
        }

    }
    
    for (int m=0 ; m<l ; m++){
        for (int k=0 ; k<n; k++){
            if(ans[m][k]!="0"){
                cout<<ans[m][k]<<" ";
            }
        }
        cout<<endl;
    }
}
