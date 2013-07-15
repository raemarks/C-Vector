#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector, *mvect, n_vect, c_vect, vector_vect;
	Vector v_vector;
	int i;

	m_vector = *new_vector("double", 5);
	add_double(&m_vector, 1);
	add_double(&m_vector, 2);
	add_double(&m_vector, 3);
	add_double(&m_vector, 4);
	add_double(&m_vector, 5);

	mvect = cpy_vector(&m_vector);
	for (i = 0; i < m_vector.size; i++) {
		printf("%lf ", ((double *) mvect->arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	erase(&m_vector, 0);
	add_double(&m_vector, 10);
	add_double(&m_vector, 20);
	printf("\n popped value: %lf\n", pop_double(&m_vector));

	print_vector(&m_vector, ' ');
	printf("\nsize: %d. capacity: %d\n\n\n", m_vector.size, m_vector.capacity);

	v_vector = *new_vector("Vector", 3);
	print_vector(&v_vector, ' ');
	printf("\n\n");
	add_vector(&v_vector, *cpy_vector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	add_vector(&v_vector, *cpy_vector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	add_vector(&v_vector, *cpy_vector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	//n_vect = *cpy_vector(popVector(&v_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	print_vector(&v_vector, ' ');
	printf("\n\n");
	
	printf("val of array: %p\n", &n_vect);
	c_vect = *cpy_vector(&v_vector);
	print_vector(&c_vect, ' ');
	printf("\n\n");
	
	printf("Starting vector of vectors of doubles.\n");
	vector_vect = *new_vector("Vector", 3);
	add_vector(&vector_vect, *cpy_vector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	add_vector(&vector_vect, *cpy_vector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	erase(&vector_vect, 2);
	print_vector(&vector_vect, ' ');
	printf("\n\n");

	
	return 0;
}
