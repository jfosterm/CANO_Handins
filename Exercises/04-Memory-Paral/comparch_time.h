#ifndef COMPARCH_TIME 
#define COMPARCH_TIME 

#include <time.h>

// Time measurement for Windows
#if defined(_WIN32)
#include <sys/timeb.h>
struct _timeb startt,endt;
void startTimer() {
    _ftime_s(&startt);
}
double stopTimer() {
    _ftime_s(&endt);
    return (double)(endt.time-startt.time)*1000+(endt.millitm-startt.millitm);
}
// Time measurement for Unix and MacOS
#elif defined(__unix__) || defined(__APPLE__)
struct timespec prevtime,curtime;
#define CLOCK CLOCK_MONOTONIC
// returns the difference in mili seconds. 
double stopTimer(void)
{
    clock_gettime(CLOCK,&curtime);
    return (double)(curtime.tv_sec - prevtime.tv_sec)*1000 
               + ((double)(curtime.tv_nsec - prevtime.tv_nsec))/1000000;
}
void startTimer(void)
{
    clock_gettime(CLOCK,&prevtime);
}
#elif
#error "Unrecognized system. Add functions for time measurement to the code"
#endif



#endif
