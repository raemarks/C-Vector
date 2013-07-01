#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector;
	int i;

	m_vector = *vector("int", 5);
	addInt(&m_vector, 1);
	addInt(&m_vector, 2);
	addInt(&m_vector, 3);
	addInt(&m_vector, 4);
	addInt(&m_vector, 5);

	for (i = 0; i < m_vector.size; i++) {
		printf("%d ", ((int *) m_vector.arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	remIntAt(&m_vector, 2);
	addInt(&m_vector, 10);
	addInt(&m_vector, 20);

	for (i = 0; i < m_vector.size; i++) {
		printf("%d ",((int *) m_vector.arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	return 0;
}
