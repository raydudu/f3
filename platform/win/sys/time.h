#ifndef _TIME_H_
#define _TIME_H_
struct timeval {
    long    tv_sec;         /* seconds */
    long    tv_usec;        /* microseconds */
};

struct timezone
{
    int  tz_minuteswest; /* minutes W of Greenwich */
    int  tz_dsttime;     /* type of dst correction */
};

int gettimeofday(struct timeval *tv, struct timezone *tz);

#endif //_TIME_H_