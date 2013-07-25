#include "vector.h"
#include <stdio.h>

int main (void) {
	Vector m_vector, *mvect, n_vect, c_vect, vector_vect;
	Vector v_vector;
	int i;

	m_vector = *new_vector("char", 5);
	push_char(&m_vector, 'a');
	push_char(&m_vector, 'a');
	push_char(&m_vector, 'a');
	push_char(&m_vector, 'a');
	insert_char(&m_vector, 'b', 2);

	print_vector(&m_vector, ' ');
	insert_char(&m_vector, 'b', 5);
	print_vector(&m_vector, ' ');

	n_vect = *cpy_vector(&m_vector);
	push_char(&n_vect, 'f');
	
	v_vector = *new_vector("Vector", 4);
	push_vector(&v_vector, *cpy_vector(&m_vector));
	push_vector(&v_vector, *cpy_vector(&m_vector));
	push_vector(&v_vector, *cpy_vector(&m_vector));
	push_vector(&v_vector, *cpy_vector(&m_vector));
	
	print_vector(&v_vector, ' ');
	insert_vector(&v_vector, n_vect, 2);
	print_vector(&v_vector, ' ');
	/*
	m_vector = *new_vector("double", 5);
	push_double(&m_vector, 1);
	push_double(&m_vector, 2);
	push_double(&m_vector, 3);
	push_double(&m_vector, 4);
	push_double(&m_vector, 5);

	mvect = cpy_vector(&m_vector);
	for (i = 0; i < m_vector.size; i++) {
		printf("%lf ", ((double *) mvect->arr)[i]);
	}
	printf("\nsize: %d. capacity: %d\n", m_vector.size, m_vector.capacity);

	erase(&m_vector, 0);
	push_double(&m_vector, 10);
	push_double(&m_vector, 20);
	printf("\n popped value: %lf\n", pop_double(&m_vector));

	print_vector(&m_vector, ' ');
	printf("\nsize: %d. capacity: %d\n\n\n", m_vector.size, m_vector.capacity);

	v_vector = *new_vector("Vector", 3);
	print_vector(&v_vector, ' ');
	printf("\n\n");
	push_vector(&v_vector, *cpy_vector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	push_vector(&v_vector, *cpy_vector(&m_vector));
	print_vector(&v_vector, ' ');
	printf("\n\n");
	push_vector(&v_vector, *cpy_vector(&m_vector));
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
	push_vector(&vector_vect, *cpy_vector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	push_vector(&vector_vect, *cpy_vector(&v_vector));
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	erase(&vector_vect, 1);
	print_vector(&vector_vect, ' ');
	printf("\n\n");
	*/
	
	return 0;
}
