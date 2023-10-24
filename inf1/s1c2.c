//                          _      _       __   _        _       
//  _ __ ___    ___  _ __  | |__  (_)     / /  (_)  ___ (_) ___  
// | '_ ` _ \  / _ \| '_ \ | '_ \ | |    / /   | | / __|| |/ __| 
// | | | | | ||  __/| |_) || | | || |   / /    | || (__ | |\__ \ 
// |_| |_| |_| \___|| .__/ |_| |_||_|  /_/     |_| \___||_||___/ 
//                  |_|                                          
//
//              Created by Vlad Litvinov Б23-534
//                                                    
                                                             
#include <stdio.h>
typedef struct{
    int dayCount;
    int day;
    int month;
    int year;
}Date;
void solveDayCount(Date * date);
void setDate(Date * date, int day_t, int month_t, int year_t){
    date->day=day_t;
    date->month=month_t;
    date->year=year_t;
}
int getMonthDays(Date * date){
    switch(date->month){
        case 1:return 31;
        case 2:return (date->year%4==0?29:28);
        case 3:return 31;
        case 4:return 30;
        case 5:return 31;
        case 6:return 30;
        case 7:return 31;
        case 8:return 31;
        case 9:return 30;
        case 10:return 31;
        case 11:return 30;
        case 12:return 31;
        default:return 0;
    }
}
void solveDayCount(Date * date){
    date->dayCount=0;
    Date buff;
    setDate(&buff,0,0,date->year);
    date->dayCount+=(date->day-1);

    // ниже с использованием for
    
    for(int i=1;i<date->month;i++){
        setDate(&buff,0,i,date->year);
        date->dayCount+=getMonthDays(&buff);
    }
    // ниже код без использования for

    // if(date->month>=12)setDate(&buff,0,11,date->year);date->dayCount+=getMonthDays(&buff); 
    // if(date->month>=11)setDate(&buff,0,10,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=10)setDate(&buff,0,9,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=9)setDate(&buff,0,8,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=8)setDate(&buff,0,7,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=7)setDate(&buff,0,6,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=6)setDate(&buff,0,5,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=5)setDate(&buff,0,4,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=4)setDate(&buff,0,3,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=3)setDate(&buff,0,2,date->year);date->dayCount+=getMonthDays(&buff);
    // if(date->month>=2)setDate(&buff,0,1,date->year);date->dayCount+=getMonthDays(&buff);

    date->dayCount+=(date->year-1)*365+(date->year-1)/4;
    if(date->dayCount>=577735)date->dayCount-=+(date->year-1)/100-(date->year-1)/400-2;

} 
int main(){
    int d1,m1,y1,d2,m2,y2;
    scanf("%d %d %d\n%d %d %d",&d1,&m1,&y1,&d2,&m2,&y2);
    Date date1, date2;
    setDate(&date1,d1,m1,y1);
    solveDayCount(&date1);
    setDate(&date2,d2,m2,y2);
    solveDayCount(&date2);
    if(date1.day>getMonthDays(&date1) || date1.month>12 || date1.day<1 || date1.month<1 || date1.year<1 ||
        date2.day>getMonthDays(&date2) || date2.month>12 || date2.day<1 || date2.month<1 || date2.year<1 ||
        date1.dayCount>577726 && date1.dayCount<577737 || date2.dayCount>577726 && date2.dayCount<577737){
        printf("uncorrect date\n");
    }else{
        printf("%d\n",date2.dayCount-date1.dayCount);
    }
}