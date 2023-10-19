#include <stdio.h>

struct date {
        int year;
        int month;
        int day;
    };

/* function prototypes */
void printDate(struct date);
void readDate(struct date *);
struct date advanceDay(struct date);
int checkLeap(int);
int exist(int, int*, int);

int main(void) {
	struct date today, tomorrow;
	readDate(&today);
	printDate(today);
	tomorrow = advanceDay(today);
	printDate(tomorrow);
	return 0;
}

/* add your function definitions here */
int checkLeap(int year) {
    if((year%4 == 0 && year%100 != 0) || year%400 == 0){
        return 1;
    }
    return 0;
}

int exist(int n, int *arr, int size) {
    int i;
    for (i = 0; i < size; i++) {
        if (arr[i] == n){
            return 1;
        }
    }
    return 0;
}

void printDate(struct date day){
    printf("%02d/%02d/%4d\n", day.month, day.day, day.year);
}

void readDate(struct date * day){
    scanf("%d %d %d", &day->year, &day->month, &day->day);
}
struct date advanceDay(struct date today) {
    int months30[] = {4, 6, 9, 11};
    int d = today.day;
    int m = today.month;
    int y = today.year;
    
    if (d == 30 && exist(m, months30, 4)){
        today.day = 1;
    }else if (d == 31 || (d == 29 && m == 2)) {
        today.day = 1;
    }else if (d == 28 && m == 2) {
        if (checkLeap(y)) {
            today.day++;
        }else {
            today.day = 1;
        }
    }else {
        today.day++;
    }
    
    if (m == 12) {
        today.month = 1;
    }else {
        today.month++;
    }
    
    if (d == 31 && m == 12) {
        today.year++;
    }
    
    return (today);
}
