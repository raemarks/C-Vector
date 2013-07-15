#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void _rem_int_at(Vector *vector, int i);

void _rem_double_at(Vector *vector, int i);

void _rem_char_at(Vector *vector, int i);

void _rem_uchar_at(Vector *vector, int i);

void _rem_vector_at(Vector *vector, int i);

Vector *new_vector(const char *type, int capacity) {
	Vector *new_vector = (Vector *) calloc (1, sizeof(Vector));

	if (strcmp(type, "int") == 0) {
		new_vector->type = INT;
		new_vector->arr = (int *) calloc (capacity, sizeof(int));
		new_vector->size_arr = capacity*sizeof(int);
		new_vector->size = 0;
		new_vector->capacity = capacity;
		new_vector->index = 0;
	} else if (strcmp(type, "double") == 0) {
		new_vector->type = DOUBLE;
		new_vector->arr = (double *) calloc (capacity, sizeof(double));
		new_vector->size_arr = capacity*sizeof(double);
		new_vector->size = 0;
		new_vector->capacity = capacity;
		new_vector->index = 0;
	} else if (strcmp(type, "char") == 0) {
		new_vector->type = CHAR;
		new_vector->arr = (char *) calloc (capacity, 1);
		new_vector->size_arr = capacity;
		new_vector->size = 0;
		new_vector->capacity = capacity;
		new_vector->index = 0;
	} else if (strcmp(type, "unsigned char") == 0) {
		new_vector->type = UNSIGNEDCHAR;
		new_vector->arr = (unsigned char *) calloc (capacity, 1);
		new_vector->size_arr = capacity;
		new_vector->size = 0;
		new_vector->capacity = capacity;
		new_vector->index = 0;
	} else if (strcmp(type, "Vector") == 0) { 
		new_vector->type = VECTOR;
		new_vector->arr = (Vector *) calloc (capacity, sizeof(Vector));
		new_vector->size_arr = capacity*sizeof(Vector);
		new_vector->size = 0;
		new_vector->capacity = capacity;
		new_vector->index = 0;
	} else {
		printf("invalid type, vector of \"%s\" not initialized.\n", type);
		return NULL;
	}	
	return new_vector;
}


void print_vector(Vector *vector, char delimeter) {
	int i;
	switch (vector->type) {
		case INT:
			for (i = 0; i < vector->size; i++) {
				printf("%d%c", ((int *) vector->arr)[i], delimeter);
			}
			break;
		case DOUBLE:
			for (i = 0; i < vector->size; i++) {
				printf("%lf%c", ((double *) vector->arr)[i], delimeter);
			}
			break;
		case CHAR:
			for (i = 0; i < vector->size; i++) {
				printf("%c%c", ((char *) vector->arr)[i], delimeter);
			}
			break;
		case UNSIGNEDCHAR:
			for (i = 0; i < vector->size; i++) {
				printf("%hhu%c", ((int *) vector->arr)[i], delimeter);
			}
			break;
		case VECTOR:
			for (i = 0; i < vector->size; i++) {
				print_vector(&(((Vector *) vector->arr)[i]), delimeter);
				putchar('\n');
			}
			break;
	}
}


Vector *cpy_vector(Vector *vector) {
	int i;
	Vector *new_vector = (Vector *) calloc (1, sizeof(Vector));
	new_vector->type = vector->type;
	new_vector->capacity = vector->capacity;
	new_vector->size = vector->size;
	new_vector->index = vector->index;
	new_vector->size_arr = vector->size_arr;

	switch (new_vector->type) {
		case INT: 
			new_vector->arr = (int *) calloc (new_vector->capacity, sizeof(int));
			memcpy (new_vector->arr, vector->arr, sizeof(int) * new_vector->capacity);
			break;
		case DOUBLE: 
			new_vector->arr = (double *) calloc (new_vector->capacity, sizeof(double));
			memcpy (new_vector->arr, vector->arr, sizeof(double) * new_vector->capacity);
			break;
		case CHAR: 
			new_vector->arr = (char *) calloc (new_vector->capacity, 1);
			memcpy (new_vector->arr, vector->arr, new_vector->capacity);
			break;
		case UNSIGNEDCHAR: 
			new_vector->arr = (unsigned char *) calloc (new_vector->capacity, 1);
			memcpy (new_vector->arr, vector->arr, new_vector->capacity);
			break;
		case VECTOR: 
			new_vector->arr = (Vector *) calloc (new_vector->capacity, sizeof(Vector));
			for (i = 0; i <new_vector->capacity; i++) {
				((Vector *) (new_vector->arr))[i] = *cpy_vector(&((Vector *) (vector->arr))[i]);
			}
			break;
	}
	return new_vector;
}

void add_int(Vector *vector, int n) {
	if (vector->capacity == 0) {
		vector->arr = (int *) calloc (sizeof(int), 1);
	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 4096) { 
			vector->arr = (int *) realloc ((int *) vector->arr, vector->size_arr * 2);
			vector->size_arr*=2;
			vector->capacity*=2;
		}
		else {
			vector->arr = (int *) realloc ((int *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr*=1.5;
			vector->capacity*=1.5;
		}
	}
	((int *) vector->arr)[vector->index] = n;
	vector->index++;
	vector->size++;
}

void add_double(Vector *vector, double d) {
	int new;
	if (vector->capacity == 0) {
		vector->arr = (double *) calloc (sizeof(double), 1);
	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 4096) {
			new = vector->size_arr * 2;
			vector->arr = realloc (vector->arr, new);
			vector->size_arr*=2;
			vector->capacity*=2;
		} else {
			vector->arr = (double *) realloc ((double *) vector->arr, (vector->size_arr) * 1.5);
			vector->size_arr*=1.5;
			vector->capacity*=1.5;
		}
	}
	((double *) vector->arr)[vector->index] = d;
	vector->index++;
	vector->size++;

}

void add_char(Vector *vector, char c) {
	if (vector->capacity == 0) {
		vector->arr = (char *) calloc (1, 1);
	}

	if (vector->size == vector->capacity) {
		if (vector->capacity < 4096) {
			vector->arr = (char *) realloc ((char *) vector->arr, vector->size_arr * 2);
			vector->size_arr *=2;
			vector->capacity*=2;
		} else {	
			vector->arr = (char *) realloc ((char *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr *=1.5;
			vector->capacity*=1.5;
		}
	}
	((char *) vector->arr)[vector->index] = c;
	vector->index++;
	vector->size++;
}

void add_uchar(Vector *vector, unsigned char uc) {
	if (vector->capacity == 0) {
		vector->arr = (unsigned char *) calloc (1, 1);
	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 4096) {
			vector->arr = (unsigned char *) realloc ((unsigned char *) vector->arr, vector->size_arr * 2);
			vector->size_arr*=2;
			vector->capacity*=2;
		} else { 
			vector->arr = (unsigned char *) realloc ((unsigned char *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr*=1.5;
			vector->capacity*=1.5;
		}
	}
	((unsigned char *) vector->arr)[vector->index] = uc;
	vector->index++;
	vector->size++;
}

void add_vector(Vector *vector, Vector m_vector) {
	if (vector->capacity == 0) {
		vector->arr = (Vector *) calloc (sizeof(Vector), 1);
	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 496) {
			vector->arr = (Vector *) realloc ((Vector *) vector->arr, vector->size_arr * 2);
			vector->size_arr*=2;
			vector->capacity*=2;
		} else {
			vector->arr = (Vector *) realloc ((Vector *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr*=1.5;
			vector->capacity*=1.5;
		}
	}
	((Vector *) vector->arr)[vector->index] = m_vector;
	vector->index++;
	vector->size++;
}

void erase(Vector *vector, int i) {
	if (vector->type == INT) {
		_rem_int_at(vector, i);
	} else if (vector->type == DOUBLE) {
		_rem_double_at(vector, i);
	} else if (vector->type == CHAR) {
		_rem_char_at(vector, i);
	} else if (vector->type == UNSIGNEDCHAR) {
		_rem_uchar_at(vector, i);
	} else if (vector->type == VECTOR) {
		_rem_vector_at(vector, i);	
	}
}

int pop_int(Vector *vector) {
	return ((int *) vector->arr)[--(vector->size)];
}

double pop_double(Vector *vector) {
	return ((double *) vector->arr)[--(vector->size)];
}


char pop_char(Vector *vector) {
	return ((char *) vector->arr)[--(vector->size)];
}

unsigned char pop_uchar(Vector *vector) {
	return ((unsigned char *)vector->arr)[--(vector->size)];
}

Vector pop_vector(Vector *vector) {
	return ((Vector *) vector->arr)[--(vector->size)];
}

void shrink_to_fit(Vector *vector) {
	int data_size = vector->size_arr / vector->capacity;
	vector->size_arr = data_size * vector->size;
	vector->arr = (void *) realloc(vector->arr, vector->size_arr);
	vector->capacity = vector->size;
}

void clear(Vector *vector) {
	int i;
	int size;
	if (vector->type == VECTOR) {
		size = vector->size;
		for (i = size - 1; i >= 0; i--) {
			_rem_vector_at(vector, i);
		}
	}
	free(vector->arr);
	vector->arr = NULL;
	vector->capacity = 0;
	vector->size = 0;
	vector->size_arr = 0;
	vector->index = 0; //so when the first item is added, index is 0
}

int empty(Vector *vector) {
	if (vector->size == 0) {
		return 1;
	} else {
		return 0;
	}
}

void _rem_int_at(Vector *vector, int i) {
	//have to typecast everything. Just shift everything one unit to the left
	memcpy (&(((int *)vector->arr)[i]), &(((int *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(int));
	vector->size--;
	vector->index--;
}

void _rem_double_at(Vector *vector, int i) {
	memcpy (&(((double *)vector->arr)[i]), &(((double *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(double));
	vector->size--;
	vector->index--;
}

void _rem_char_at(Vector *vector, int i) {
	memcpy (&(((char *)vector->arr)[i]), &(((char *)vector->arr)[i+1]), (vector->size - i - 1));
	vector->size--;
	vector->index--;
}

void _rem_uchar_at(Vector *vector, int i) {
	memcpy (&(((unsigned char *)vector->arr)[i]), &(((unsigned char *)vector->arr)[i+1]), (vector->size - i - 1));
	vector->size--;
	vector->index--;
}

void _rem_vector_at(Vector *vector, int i) {
	free(((Vector *) vector->arr)[i].arr);
	memcpy (&(((Vector *)vector->arr)[i]), &(((Vector *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(Vector));
	vector->size--;
	vector->index--;
}


