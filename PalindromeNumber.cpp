//
//  PalindromeNumber.cpp
//  
//
//  Created by 邢阳 on 2018/11/21.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int main(){
    
    int x = 12321;
    int xs;
    xs=x;
    int ans;
    while(x!=0){
        ans=ans*10+x%10;
        x=x/10;
    }
    cout<<"x is :"<<xs<<endl;
    cout<<"ans is :"<<ans<<endl;
    if(ans==xs && ans>0)
        cout<<"true";
    
    else
        cout<<"false";
    
    return 0;
}
