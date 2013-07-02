#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct {
	int type;
	void *arr;
	int capacity;
	int size_arr; //size of memory block
	int size; //how many elements
	int index; //how many elements it can hold
} Vector;

//can be a vector of ints, doubles, strings, and chars
typedef enum type {
	Int, Double, Char, UnsignedChar, Vect
} type;

Vector *vector(const char *type, int capacity);

Vector *cpyVector(Vector *vector);

void addInt(Vector *vector, int n);

void addDouble(Vector *vector, double d);

void addChar(Vector *vector, char c);

void addUChar(Vector *vector, unsigned char uc);

void addVector(Vector *vector, Vector m_vector);

void remIntAt(Vector *vector, int i);

void remDoubleAt(Vector *vector, int i);

void remCharAt(Vector *vector, int i);

void remUCharAt(Vector *vector, int i);

void remVectorAt(Vector *vector, int i);

void shrink_to_fit(Vector *vector);

void clear(Vector *vector);

int empty(Vector *vector);








#endif 
