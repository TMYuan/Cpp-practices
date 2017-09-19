#include <stdlib.h>
#include <stdio.h>

int main(){
    int num;
    scanf("%d", &num);
    while(num--){
        int month, day, start_day, count=0;
        scanf("%d %d", &month, &day);
        if(month == 3){
            day += 28;
            month = 2;
        }
        switch(month){
            case 5:
                start_day = 9;
                break;
            case 9:
                start_day = 5;
                break;
            case 7:
                start_day = 11;
                break;
            case 11:
                start_day = 7;
                break;
            case 1:
                start_day = 10;
                break;
            case 2:
                start_day = 21;
                break;
            default:
                start_day = month;
                break;
        }
        while(day < start_day){
            day += 7;
        }
        while(start_day < day){
            ++count;
            ++start_day;
        }
        switch(count % 7){
            case 0:
                printf("Monday\n");
                break;
            case 1:
                printf("Tuesday\n");
                break;
            case 2:
                printf("Wednesday\n");
                break;
            case 3:
                printf("Thursday\n");
                break;
            case 4:
                printf("Friday\n");
                break;
            case 5:
                printf("Saturday\n");
                break;
            case 6:
                printf("Sunday\n");
                break;
        }
    }

    return 0;
}