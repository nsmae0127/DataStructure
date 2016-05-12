#include "MyArray.h"

template<class Datatype>
MyArray<Datatype>::MyArray(int p_size)
{
	m_Array = new Datatype[p_size];
	m_Size = p_size;
}

template<class Datatype>
MyArray<Datatype>::~MyArray()
{
	// 배열값이 0이 아니면 삭제
	if (m_Array != 0)
		delete[] m_Array;
	m_Array = 0;
}

template<class Datatype>
void MyArray<Datatype>::Resize(int p_Size)
{
	// 새로운 크기의 배열 생성
	Datatype* newArray = new Datatype[p_Size];

	// 새 배열이 할당되지 않았다면 반환
	if (newArray == 0)
		return;

	int min;
	if (p_Size < m_Size)
		min = p_Size;
	else
		min = m_Size;

	// 새로 지정된 크기만큼 인덱스 저장
	for (int index = 0; index < min; index++)
		newArray[index] = m_Array[index];

	m_Size = p_Size;

	if (m_Array != 0)
		delete[] m_Array;

	// 포인터 복사
	m_Array = newArray;
}

template<class Datatype>
void MyArray<Datatype>::Insert(Datatype p_item, int p_index)
{
	for (int index = m_Size - 1; index > p_index; index--)
		m_Array[index] = m_Array[index - 1];

	m_Array[p_index] = p_item;
}

template<class Datatype>
void MyArray<Datatype>::Remove(int p_index)
{
	for (int index = p_index + 1; index < m_Size; index++)
		m_Array[index - 1] = m_Array[index];
}

template<class Datatype>
int MyArray<Datatype>::Size()
{
	return m_Size;
}

template<class Datatype>
Datatype & MyArray<Datatype>::operator[](int p_Index)
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_Array[p_Index];
}

template<class Datatype>
MyArray<Datatype>::operator Datatype*()
{
	return m_Array;
}
