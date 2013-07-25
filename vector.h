#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct {
	int type;
	void *arr;
	int capacity;
	int size_arr; //size of memory block
	int size; //how many elements
} Vector;

//can be a vector of ints, doubles, strings, and chars
typedef enum {
	INT, DOUBLE, CHAR, UNSIGNEDCHAR, VECTOR
} type;

Vector *new_vector(const char *type, int capacity);

void print_vector (Vector *vector, char delimeter);

Vector *cpy_vector(Vector *vector);

//void pushBack(Vector *vector, void *val);

void push_int(Vector *vector, int n);

void push_double(Vector *vector, double d);

void push_char(Vector *vector, char c);

void push_uchar(Vector *vector, unsigned char uc);

void push_vector(Vector *vector, Vector m_vector);

void insert_int(Vector *vector, int n, int i);

void insert_double(Vector *vector, double d, int i);

void insert_char(Vector *vector, char c, int i);

void insert_uchar(Vector *vector, unsigned char uc, int i);

void insert_vector(Vector *vector, Vector vect, int i);

void erase(Vector *vector, int i);

int pop_int(Vector *vector);

double pop_double(Vector *vector);

char pop_char(Vector *vector);

unsigned char pop_uchar(Vector *vector);

Vector pop_vector(Vector *vector);

void resize(Vector *vector, int size);

void shrink_to_fit(Vector *vector);

void clear(Vector *vector);

int empty(Vector *vector);








#endif 
