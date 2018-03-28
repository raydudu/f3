#include <windows.h>

const __int64 DELTA_EPOCH_IN_MICROSECS= 11644473600000000;

struct timeval2 {
    long    tv_sec;         /* seconds */
    long    tv_usec;        /* microseconds */
};

struct timezone2
{
    int  tz_minuteswest; /* minutes W of Greenwich */
    int  tz_dsttime;     /* type of dst correction */
};


int gettimeofday(struct timeval2 *tv, struct timezone2 *tz)
{
    if (tv != NULL) {
        __int64 tmpres = 0;
        FILETIME ft;

        ZeroMemory(&ft, sizeof(ft));
        GetSystemTimeAsFileTime(&ft);

        tmpres = ft.dwHighDateTime;
        tmpres <<= 32;
        tmpres |= ft.dwLowDateTime;

        /*converting file time to unix epoch*/
        tmpres /= 10;  /*convert into microseconds*/
        tmpres -= DELTA_EPOCH_IN_MICROSECS;
        tv->tv_sec = (__int32)(tmpres * 0.000001);
        tv->tv_usec = (tmpres % 1000000);
    }

    if (tz != NULL) {
        int rez=0;
        TIME_ZONE_INFORMATION tz_winapi;

        ZeroMemory(&tz_winapi,sizeof(tz_winapi));
        //_tzset(),don't work properly, so we use GetTimeZoneInformation
        rez = GetTimeZoneInformation(&tz_winapi);
        tz->tz_dsttime = (rez == 2);
        tz->tz_minuteswest = tz_winapi.Bias + ((rez == 2) ? tz_winapi.DaylightBias : 0);
    }

    return 0;
}