#include <iostream>
#include <sys/time.h>
#include <unistd.h>
using namespace std;
namespace TimerNamespace
{
    class Timer
    {
        struct timeval tv, ts;
        struct timezone tz;
        public:
        long get_timer()
        {
            gettimeofday(&tv, &tz);
            return (tv.tv_sec - ts.tv_sec) * 1000000 + tv.tv_usec - ts.tv_usec;
        }

        void init_timer()
        {
            gettimeofday(&ts, &tz);
        }
    };
}