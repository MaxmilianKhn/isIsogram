#include "isogram.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

bool is_isogram(const char phrase[]){
    int length=strlen(phrase);
    int occur[36]={0};
    int numberOfDifferentLetter=0;
    for(int l1=0;l1<length;++l1){
        if((('a'>tolower(phrase[l1]))||(tolower(phrase[l1])>'z'))&&((0>phrase[l1])||(phrase[l1]>9))){
            continue;
        }
        for(int l2=l1+1;l2<length;++l2){
            if((('a'>tolower(phrase[l2]))||(tolower(phrase[l2])>'z'))&&((0>phrase[l2])||(phrase[l2]>9))){
                continue;
            }
            printf("%c",phrase[l1]);
            if(tolower(phrase[l1])==tolower(phrase[l2])){
                if((0<=phrase[l1])&&(phrase[l1]<=9)){
                    occur[phrase[l1]-'0']++;
                }
                else{
                    occur[tolower(phrase[l1])+10-'a']++;
                }
            }
        }
    }
    for(int l1=0;l1<36;++l1){
        printf("%d",occur[l1]);
        if(occur[l1]==0) continue;
        numberOfDifferentLetter++;
        for(int l2=l1+1;l2<36;++l2){
            if(occur[l2]==0) continue;
            if(occur[l2]!=occur[l1])return false;
        }
    }
    return (numberOfDifferentLetter>1)?true:false;
}
