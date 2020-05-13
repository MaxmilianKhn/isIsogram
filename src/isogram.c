#include "isogram.h"
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]){
    int length=strlen(phrase);
    int occur[36]={0};
    for(int l1=0;l1<length;++l1){
        if((0<=phrase[l1])&&(phrase[l1]<=9)){
            occur[phrase[l1]-'0']++;
        }
        else if(('a'<=tolower(phrase[l1]))&&(tolower(phrase[l1])<='z')){
            occur[tolower(phrase[l1])+10-'a']++;
        }
    }
    for(int l1=0;l1<36;++l1){
        if(occur[l1]==0) continue;
        for(int l2=l1+1;l2<36;++l2){
            if(occur[l2]==0) continue;
            if(occur[l2]!=occur[l1])return false;
        }
    }
    return true;
}
