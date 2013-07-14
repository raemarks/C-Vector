#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector, *mvect, n_vect, c_vect, vector_vect;
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

	print_vector(&m_vector, ' ');
	printf("\nsize: %d. capacity: %d\n\n\n", m_vector.size, m_vector.capacity);

	v_vector = *new_vector("Vector", 3);
	print_vector(&v_vector, ' ');
	printf("\n\n");
	addVector(&v_vector, *cpyVector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	addVector(&v_vector, *cpyVector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	addVector(&v_vector, *cpyVector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	//n_vect = *cpyVector(popVector(&v_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	print_vector(&v_vector, ' ');
	printf("\n\n");
	
	printf("val of array: %p\n", &n_vect);
	c_vect = *cpyVector(&v_vector);
	print_vector(&c_vect, ' ');
	printf("\n\n");
	
	printf("Starting vector of vectors of doubles.\n");
	vector_vect = *new_vector("Vector", 3);
	addVector(&vector_vect, *cpyVector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	addVector(&vector_vect, *cpyVector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	addVector(&vector_vect, *cpyVector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");

	
	return 0;
}
