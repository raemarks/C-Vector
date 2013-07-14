#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector, *mvect, n_vect;
	Vector v_vector;
	int i;

	m_vector = *new_vector("double", 5);
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

	erase(&m_vector, 0);
	addDouble(&m_vector, 10);
	addDouble(&m_vector, 20);
	printf("\n popped value: %lf\n", popDouble(&m_vector));

	for (i = 0; i < m_vector.size; i++) {
		printf("%lf ",((double *) m_vector.arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n\n\n", m_vector.size, m_vector.capacity);

	v_vector = *new_vector("Vector", 3);
	addVector(&v_vector, *cpyVector(&m_vector));
	addVector(&v_vector, *cpyVector(&m_vector));
	addVector(&v_vector, *cpyVector(&m_vector));
	//n_vect = *cpyVector(popVector(&v_vector));
	n_vect = popVector(&v_vector);
	remVectorAt(&v_vector, 0);
	
	printf("val of array: %p\n", &n_vect);
	for (i = 0; i < n_vect.size; i++) {
		printf("%lf ",((double *) n_vect.arr)[i]);
	}

	return 0;
}
