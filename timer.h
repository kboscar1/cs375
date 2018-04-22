#ifndef TIME
#define TIME

#include <sys/time.h>
#include <string>

using namespace std;

void timeval_print(char *str, struct timeval *tv);
int timeval_subtract(struct timeval *result, struct timeval *t2, struct timeval *t1);
void timer_start();
vector<time_t> timer_end();

#endif
