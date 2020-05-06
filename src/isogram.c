#include "isogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]){
    int length=strlen(phrase);
    for(int l1=0;l1<length;++l1){
        for(int l2=l1+1;l2<length;++l2){
            if(tolower(phrase[l1])==tolower(phrase[l2])){
                if(phrase[l1]!=' ')return false;
            }
        }
    }
    return true;
}
