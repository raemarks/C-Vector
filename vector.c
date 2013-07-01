#include "vector.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Vector *vector(const char *type, int capacity) {
	Vector *newVector = (Vector *) calloc (1, sizeof(Vector));

	if (strcmp(type, "int") == 0) {
		newVector->type = Int;
		newVector->arr = (int *) calloc (capacity, sizeof(int));
		newVector->size_arr = capacity*sizeof(int);
		newVector->size = 0;
		newVector->capacity = capacity;
		newVector->index = 0;
	} else if (strcmp(type, "double") == 0) {
		newVector->type = Double;
		newVector->arr = (double *) calloc (capacity, sizeof(double));
		newVector->size_arr = capacity*sizeof(double);
		newVector->size = 0;
		newVector->capacity = capacity;
		newVector->index = 0;
	} else if (strcmp(type, "char") == 0) {
		newVector->type = Char;
		newVector->arr = (char *) calloc (capacity, 1);
		newVector->size_arr = capacity;
		newVector->size = 0;
		newVector->capacity = capacity;
		newVector->index = 0;
	} else if (strcmp(type, "unsigned char") == 0) {
		newVector->type = UnsignedChar;
		newVector->arr = (unsigned char *) calloc (capacity, 1);
		newVector->size_arr = capacity;
		newVector->size = 0;
		newVector->capacity = capacity;
		newVector->index = 0;
	} else if (strcmp(type, "Vector") == 0) { 
		newVector->type = Vect;
		newVector->arr = (Vector *) calloc (capacity, sizeof(Vector));
		newVector->size_arr = capacity*sizeof(Vector);
		newVector->size = 0;
		newVector->capacity = capacity;
		newVector->index = 0;
	} else {
		printf("invalid type, vector not initialized.\n");
		return NULL;
	}	
	newVector->index = -1; //needed to add the first item
	return newVector;
}


Vector *cpyVector(Vector *vector) {
	int i;
	Vector *newVector = (Vector *) calloc (1, sizeof(Vector));
	newVector->type = vector->type;
	newVector->capacity = vector->capacity;
	newVector->size = vector->size;
	newVector->index = vector->index;
	newVector->size_arr = vector->size_arr;

	switch (newVector->type) {
		case Int: 
			newVector->arr = (int *) calloc (newVector->capacity, sizeof(int));
			memcpy (newVector->arr, vector->arr, sizeof(int) * newVector->capacity);
			break;
		case Double: 
			newVector->arr = (double *) calloc (newVector->capacity, sizeof(double));
			memcpy (newVector->arr, vector->arr, sizeof(double) * newVector->capacity);
			break;
		case Char: 
			newVector->arr = (char *) calloc (newVector->capacity, 1);
			memcpy (newVector->arr, vector->arr, newVector->capacity);
			break;
		case UnsignedChar: 
			newVector->arr = (unsigned char *) calloc (newVector->capacity, 1);
			memcpy (newVector->arr, vector->arr, newVector->capacity);
			break;
		case Vect: 
			newVector->arr = (Vector *) calloc (newVector->capacity, sizeof(Vector));
			for (i = 0; i <newVector->capacity; i++) {
				((Vector *) (newVector->arr))[i] = *cpyVector(&((Vector *) (vector->arr))[i]);
			}
			break;
	}
	return newVector;
}

void addInt(Vector *vector, int n) {
	if (empty(vector)) {
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

void addDouble(Vector *vector, double d) {
//	if (empty(vector)) {
//			vector->arr = (double *) calloc (sizeof(double), 1);
//	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 4096) {
			printf("here! adding: %lf, size_arr: %d, capacity: %d\n", d, sizeof(double)*vector->size, vector->capacity);
			vector->arr = (double *) realloc ((double *) vector->arr, (vector->size_arr * 2));
			vector->size_arr*=2;
			vector->capacity*=2;
		} else {
			vector->arr = (double *) realloc ((double *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr*=1.5;
			vector->capacity*1.5;
		}
		vector->capacity*=2;
	}

	((double *) vector->arr)[vector->index] = d;
	vector->index++;
	vector->size++;

}

void addChar(Vector *vector, char c) {
	if (empty(vector)) {
			vector->arr = (char *) calloc (1, 1);
	};

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

void addUChar(Vector *vector, unsigned char uc) {
	if (empty(vector)) {
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

void addVector(Vector *vector, Vector m_vector) {
	if (empty(vector)) {
			vector->arr = (Vector *) calloc (sizeof(Vector), 1);
	}
	if (vector->size == vector->capacity) {
		if (vector->capacity < 496) {
			vector->arr = (Vector *) realloc ((Vector *) vector->arr, vector->size_arr * 2);
			vector->size_arr*2;
			vector->capacity*2;
		} else {
			vector->arr = (Vector *) realloc ((Vector *) vector->arr, vector->size_arr * 1.5);
			vector->size_arr*1.5;
			vector->capacity*1.5;
	}
	((Vector *) vector->arr)[vector->index] = m_vector;
	vector->index++;
	vector->size++;
}

void remIntAt(Vector *vector, int i) {
	//have to typecast everything. Just shift everything one unit to the left
	memcpy (&(((int *)vector->arr)[i]), &(((int *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(int));
	vector->size--;
	vector->index--;
}

void remDoubleAt(Vector *vector, int i) {
	memcpy (&(((double *)vector->arr)[i]), &(((double *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(double));
	vector->size--;
	vector->index--;
}

void remCharAt(Vector *vector, int i) {
	memcpy (&(((char *)vector->arr)[i]), &(((char *)vector->arr)[i+1]), (vector->size - i - 1));
	vector->size--;
	vector->index--;
}

void remUCharAt(Vector *vector, int i) {
	memcpy (&(((unsigned char *)vector->arr)[i]), &(((unsigned char *)vector->arr)[i+1]), (vector->size - i - 1));
	vector->size--;
	vector->index--;
}

void remVectorAt(Vector *vector, int i) {
	memcpy (&(((Vector *)vector->arr)[i]), &(((Vector *)vector->arr)[i+1]), (vector->size - i - 1) * sizeof(Vector));
	free(((Vector *) vector->arr)[i].arr);
	vector->size--;
	vector->index--;
}


void shrink_to_fit(Vector *vector) {
	int data_size = vector->size_arr / vector->size; 
	vector->size_arr = data_size * vector->size;
	vector->arr = (void *) realloc(vector->arr, vector->size_arr);
	vector->capacity = vector->size;
}

void clear(Vector *vector) arr_size{
	int i;
	int size;
	if (vector->type == Vect) {
		size = vector->size;
		for (i = size - 1; i >= 0; i--) {
			remVectorAt(vector, i);
		}
	}
	free(vector->arr);
	vector->arr = NULL;
	vector->capacity = 0;
	vector->size = 0;
	vector->size_arr = 0;
	vector->index = -1; //so when the first item is added, index is 0
}

int empty(Vector *vector) {
	if (vector->size == 0)
		return 1;
	else 
		return 0;
}

