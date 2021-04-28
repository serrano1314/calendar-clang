#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int leap(int y){
    int is_leap;
    if (y%400 == 0)
        is_leap=1;
    else if (y%100 == 0)
        is_leap=0;
    else if (y%4 == 0)
        is_leap=1;
    else
        is_leap=0;
    return is_leap;
}
int main()
{
    char months[][10]={" ","JANUARY","FEBRUARY","MARCH",
                    "APRIL","MAY","JUNE",
                    "JULY","AUGUST","SEPTEMBER",
                    "OCTOBER","NOVEMBER","DECEMBER"};
    int days[]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    int year;
    int i,j,count=1;
    int f=0, k=1, m, c=0, d=0;
    printf("ENTER MONTH NUMBER(1-12): ");
    scanf("%d",&m);
    int cur_month=m;
    printf("ENTER A YEAR: ");
    scanf("%d",&year);
    c=year/100;
    d=year%100;
    if(leap(year))
        days[2] = 29;
    if(m<3){
        m=m+10;
        d=d-1;
    }
    else
        m=m-2;
    f = (k + ((13*m-1)/5) + d + (d/4) + (c/4)) - (2*c);
    if(f==0)
        f=f+7;
    while(f<0){
        f=f+7;
        if(f>0&&f<8){
            break;
        }
    }
    if(f>7)
        f=f%7;
    int day=f;
    i=1;
    printf("\n %s    %d\n",months[cur_month],year);
    printf("\n  M     T     W     TH    F     SA    SU  \n");
    printf("------------------------------------------\n");
    while(count<=days[cur_month])
        if(i<f){
            printf("      ");
            i++;
        }
        else{
            if(day>7){
                day=1;
                printf("\n");
            }
            printf("  %2d  ",count++);
            day++;
        }
    printf("\n");
    return 0;
}
