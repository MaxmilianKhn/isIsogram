#include "isogram.h"
#include <string.h>
#include <ctype.h>
#include <stdio.h>

bool is_isogram(const char phrase[]){
    int length=strlen(phrase);
    int occur[256]={0};
    for(int l1=0;l1<length;++l1){
        if((('a'<=tolower(phrase[l1]))&&(tolower(phrase[l1])<='z'))||((0<=phrase[l1])&&(phrase[l1]<=9))){ //only characters in interval a to z, A to Z or 0 to 9 should pass
            occur[tolower(phrase[l1])]++;
        }
    }
    for(int l1=0;l1<256;++l1){
        if(occur[l1]==0){
            continue;
        }
        for(int l2=l1+1;l2<256;++l2){
            if(occur[l2]==0){
                continue;    
            } 
            if(occur[l2]!=occur[l1])return false;
        }
    }
    return true;
}
