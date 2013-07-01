#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector, *mvect;
	int i;

	m_vector = *vector("double", 5);
	addDouble(&m_vector, 1);
	addDouble(&m_vector, 2);
	addDouble(&m_vector, 3);
	addDouble(&m_vector, 4);
	addDouble(&m_vector, 5);

	mvect = cpyVector(&m_vector);
	for (i = 0; i < m_vector.size; i++) {
		printf("%lf ", ((double *) mvect->arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	remDoubleAt(&m_vector, 2);
	addDouble(&m_vector, 10);
	addDouble(&m_vector, 20);

	shrink_to_fit(&m_vector);

	for (i = 0; i < m_vector.size; i++) {
		printf("%lf ",((double *) m_vector.arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	return 0;
}
