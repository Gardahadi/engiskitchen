#include <stdio.h>
#include <time.h>
#include <stdlib.h>


int main(){
    time_t seconds;
    seconds = time(NULL);
    long int hour = (seconds%86400)/3600;
    long int minute = (seconds%3600)/60;
    long int second = (seconds%60);
    printf("%ld %ld %ld\n",hour, minute,second);
}