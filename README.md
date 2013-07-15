C-Vector
========

A Vector struct defined by vector.h can be passed to functions in vector.h to mimic the Vector class in C++.
It can currently create a vector of integers, doubles, chars, unsigned chars, and more Vectors (to mimic  arrays 
of strings and other multidimensional arrays). 

A Vector struct contains 6 members. int type is an enumerated value describing the data type it contains, void *arr
contains the array of data, int capacity is the amount of entries that can fit in the vector, int size_arr is the 
size in bytes of *arr and its contents, int size is the number of elements, and int index is the index of the last
element in the vector.

To construct a vector, call the new_vector() function and pass it a string representation of the data type and the
initial capacity. For example, type:

          Vector c_vector = *new_vector("char", 6)

cpy_vector() returns the address of a deep copy of the vector it is passed. The add functions (add_char, add_int, etc)
work just like push_back() in C++. The erase() function mimics its counterpart in the C++ class. All functions in vector.h involve heavy typecasting, so the programmer does not have
to pass in void pointers, which could cause bugs down the road if they accidentally change the values contained
in those pointers. 

Examples:

          Vector *i_vector;
          Vector *i_vect = vector("int", 3);
          add_int(i_vect, 1);
          add_int(i_vect, 2);
          add_int(i_vect, 3);
          add_int(i_vect, 4); //memory is reallocated to capacity of 6 ints          
          printf("%d ", ((int *) i_vector->arr)[i_vector->index]); //output: 4
          remIntAt(i_vect, 2); //removes the 3
          i_vector = cpy_vector(i_vect);
          
More functionality to come!
          


