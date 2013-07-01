#ifndef __CVEC_BENCH
#define __CVEC_BENCH
#include <time.h>
#include <stdio.h>

#define BILLION 1000000000

typedef struct timespec Timespec;

Timespec Start() {
	Timespec ts;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &ts);
	return ts;
}

Timespec Stop(Timespec h) {
	Timespec end;
	clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &end);
	end.tv_sec -= h.tv_sec;
	if (h.tv_nsec > end.tv_nsec) {
		end.tv_sec--;
		end.tv_nsec += BILLION;
	}
	end.tv_nsec -= h.tv_nsec;
	return end;
}

void PrintTimeSpec(Timespec t) {
	printf("%lld.%09llds\n",(long long)t.tv_sec,(long long)t.tv_nsec);
}

#endif
