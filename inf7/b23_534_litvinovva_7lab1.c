//time
#include "../clib/src/title.h"
//comt INCLUDES START
#define PTRARR_TYPE char
#include "../clib/src/ptrarr.h"
#include "../clib/src/string.h"
#include <stdio.h>
#include <ctype.h>
#include <limits.h>
//comt PROGRAM START

int main(){
    char ** arrStr = ptrarr_init_char(0);
    char buff;
    int last=1,curr;
    uint64_t minLen=ULLONG_MAX;
    while((buff=getchar())!='\n'){
        curr=isspace(buff);
        if(last && !curr){
            ptrarr_pub_char(&arrStr,str_init(0));
            str_pub(&(arrStr[ptrarr_len_char(arrStr)-1]),buff);
        }
        if(!last && !curr){
            str_pub(&(arrStr[ptrarr_len_char(arrStr)-1]),buff);
        }
        last=curr;
    }
    char * mostShort;
    for(int i=0;i<ptrarr_len_char(arrStr);i++){
        printf("%s\n",arrStr[i]);
        if(str_len(arrStr[i])<minLen){
            minLen=str_len(arrStr[i]);
            mostShort=arrStr[i];
        }
    }
    printf("\n%s\n",mostShort);
}
//comt PROGRAM END