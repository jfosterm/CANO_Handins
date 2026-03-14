#include <stdio.h>
#include <time.h>

// Code for time measurements. startTimer() starts the timer.
// stopTimer() returns the elapsed time from the last startTimer() call
// as a double (floating point) in milliseconds.
// Time measurement for Windows
#if defined(_WIN32)
#include <sys/timeb.h>
struct _timeb startt,endt;
void startTimer()
{
    _ftime_s(&startt);
}
double stopTimer()
{
    _ftime_s(&endt);
    return (double)(endt.time-startt.time)*1000+(endt.millitm-startt.millitm);
}

// Time measurement for Unix
#elif defined(__unix__)
struct timespec prevtime,curtime;

#define CLOCK CLOCK_REALTIME
// returns the difference in mili seconds. 
double stopTimer() {
    clock_gettime(CLOCK,&curtime);
    return (double)(curtime.tv_sec - prevtime.tv_sec)*1000 + ((double)(curtime.tv_nsec - prevtime.tv_nsec))/1000000;
}
void startTimer()
{
    clock_gettime(CLOCK,&prevtime);
}

// Time measurement for MacOS
#elif defined(__APPLE__)
struct timespec prevtime,curtime;
#define CLOCK CLOCK_REALTIME
// returns the difference in mili seconds. 
double stopTimer() {
    clock_gettime(CLOCK,&curtime);
    return (double)(curtime.tv_sec - prevtime.tv_sec)*1000 + ((double)(curtime.tv_nsec - prevtime.tv_nsec))/1000000;
}
void startTimer()
{
    clock_gettime(CLOCK,&prevtime);
}
#elif

#error "Unrecognized system. Add functions for time measurement to the code"
#endif


void main(){
    int a=1;

    startTimer();
    for (int i=2 ; i< 1<<17 ; i++){
        a=(a+1)%i;
    }
    printf("Elapsed time: %.3f milliseconds.\n",stopTimer());
}
