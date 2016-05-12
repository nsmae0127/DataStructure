#pragma once
#ifndef MYARRAY_H
#define MYARRAY_H

template<class Datatype>
class MyArray
{
public:
	Datatype* m_Array;

	int m_Size;

public:
	MyArray(int p_size);
	~MyArray();

	void Resize(int p_size);

	void Insert(Datatype p_item, int p_index);

	void Remove(int p_index);

	int Size();

	Datatype& operator[] (int p_index);

	operator Datatype* ();
};

#endif // !MYARRAY_H
