#include "../vector.h"
#include "bench.h"

void BenchAddInts() {
	printf("Add 1,000,000 Integers:\n");
	Vector *mvec = vector("int", 1);
	int i;

	Timespec t = Start();
	for (i =0; i < 9000; i++) {
		addInt(mvec, i);
	}
	t = Stop(t);
	PrintTimeSpec(t);
}

int main() {
	BenchAddInts();
	return 0;
}
