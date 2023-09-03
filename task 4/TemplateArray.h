#pragma once
#ifndef _TEMPLATEARRAY_H_
#define _TEMPLATEARRAY_H_

#include<iostream>
template<class T>
class TemplateArray
{
private:
	T* m_data;
	int m_size;
	int m_capacity;
public:
	TemplateArray() :m_data(0), m_size(0), m_capacity(0) {};
	TemplateArray(int size, T value = 0);
	TemplateArray(const TemplateArray& ba);
	template<class T1>TemplateArray(const TemplateArray<T1>& ba)
	{
		m_size = ba.size();
		m_capacity = ba.capacity();
		m_data = new T[m_capacity];
		for (int i = 0; i < m_capacity; ++i)
		{
			m_data[i] = ba[i];
		}
	};
	TemplateArray& operator=(const TemplateArray& array);
	template<class T1>TemplateArray& operator=(const TemplateArray<T1>& array)
	{
		TemplateArray ha;
		ha.m_size = array.m_size;
		ha.m_capacity = array.m_capacity;
		ha.m_data = new T[ha.m_capacity];
		for (int i = 0; i < ha.m_size; ++i)
			ha.m_data[i] = array.m_data[i];
		return ha;
	};
	~TemplateArray() { delete[]m_data; }
	int size()const { return m_size; }
	int capacity()const { return m_capacity; }
	int reserve(int num, T elem = 0);
	T at(int ind);
	T operator[](int ind)const;
	T& operator[](int ind);
	int push_back(T elem);
	int insert(int ind, T value);
	void erase(int ind);
	friend std::ostream& operator<<(std::ostream& os, const TemplateArray &ba);
private:
	inline bool isValidateIndex(int ind);
};
template<class T>
TemplateArray<T>::TemplateArray(int size, T value)
{

	m_size = size;
	m_capacity = size;
	m_data = new T[m_capacity];
	if (NULL == m_data)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < size; ++i)
		m_data[i] = value;

}
template<class T>
TemplateArray<T>::TemplateArray(const TemplateArray& ba)
{



	m_size = ba.m_size;
	m_capacity = ba.m_capacity;
	m_data = new T[m_capacity];
	if (NULL == m_data)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < m_size; ++i)
		m_data[i] = ba.m_data[i];
	for (int i = m_size; i < m_capacity; ++i)
		m_data[i] = 0;
}








template<class T>
int TemplateArray<T>::reserve(int num, T elem)
{

	if (num <= m_capacity && num >= m_size)
	{
		for (int i = m_size; i < num; ++i)
			m_data[i] = elem;
		m_size = num;
		return 1;
	}


	TemplateArray pa;

	if (num > m_capacity)


	{
		pa.m_size = m_size;
		pa.m_capacity = m_capacity;
		pa.m_data = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
			pa.m_data[i] = m_data[i];
		for (int i = m_size; i < m_capacity; ++i)
			pa.m_data[i] = 0;
		delete[]m_data;
		while (num > m_capacity)
			m_capacity *= 2;
		m_data = new T[m_capacity];

		for (int i = 0; i < m_size; ++i)
			m_data[i] = pa.m_data[i];
		for (int i = m_size; i < num; ++i)
			m_data[i] = elem;
		m_size = num;
		return 1;
	}


	if (num < m_size)
	{

		m_size = num;
		return 1;
	}





}

template<class T>
T TemplateArray<T>::at(int ind)
{

	if (ind < 0 || ind >= m_size)

		return 0;



	return m_data[ind];
}

template<class T>
T TemplateArray<T>::operator[](int ind)const
{
	if (ind < 0 || ind >= m_size)

		return 0;

	return m_data[ind];
}


template<class T>
T& TemplateArray<T>::operator[](int ind)
{


	return m_data[ind];
}



template<class T>
int TemplateArray<T>::push_back(T elem)
{

	if (m_capacity >= m_size + 1)
	{
		m_data[m_size] = elem;
		return m_size;
	}


	if (m_capacity == 0)
	{
		delete[]m_data;
		m_data = new T[1];
		m_size = 1;
		m_data[0] = elem;
		return m_size;
	}

	if (m_capacity < m_size + 1)
	{
		TemplateArray pa;
		pa.m_size = m_size;
		pa.m_capacity = m_capacity;
		pa.m_data = new T[m_capacity];
		for (int i = 0; i < m_capacity; ++i)
			pa.m_data[i] = m_data[i];
		delete[]m_data;
		m_data = new T[m_capacity * 2];
		for (int i = 0; i < m_size; ++i)
			m_data[i] = pa.m_data[i];
		m_data[m_size] = elem;
		m_size = m_size + 1;
		m_capacity = m_capacity * 2;
		return m_size;
	}

}


template<class T>
int TemplateArray<T>::insert(int ind, T value)
{

	if (m_capacity == 0)
	{
		delete[]m_data;
		m_data = new T[1];
		m_size = 1;
		m_data[0] = value;
		return m_size;
	}
	if (ind < 0 || ind >= m_size)

		return 0;


	if (m_size + 1 > m_capacity)

	{
		TemplateArray pa;
		pa.m_size = m_size;
		pa.m_capacity = m_capacity;
		pa.m_data = new T[m_capacity];
		for (int i = 0; i < m_size; ++i)
			pa.m_data[i] = m_data[i];
		delete[]m_data;
		m_data = new T[m_capacity * 2];
		for (int i = 0; i < ind; ++i)
			m_data[i] = pa.m_data[i];
		m_data[ind] = value;
		for (int i = ind + 1; i < m_size + 1; ++i)
			m_data[i] = pa.m_data[i - 1];

		m_size = m_size + 1;
		m_capacity = m_capacity * 2;

		return m_size;
	}

	if (m_size + 1 <= m_capacity)
	{
		for (int i = m_size; i >= ind; i--)

			m_data[i] = m_data[i - 1];

		m_data[ind] = value;
		m_size = m_size + 1;
		return m_size;

	}


}



template<class T>
void TemplateArray<T>::erase(int ind)
{
	if (ind < m_size)
	{
		for (int i = ind + 1; i < m_size; ++i)
			m_data[i - 1] = m_data[i];
		m_size = m_size - 1;

	}


}

template<class T>
TemplateArray<T>& TemplateArray<T>::operator=(const TemplateArray& array)
{
	TemplateArray ha;
	ha.m_size = array.m_size;
	ha.m_capacity = array.m_capacity;
	ha.m_data = new T[ha.m_capacity];
	for (int i = 0; i < ha.m_size; ++i)
		ha.m_data[i] = array.m_data[i];
	return ha;
}



template<class T>
std::ostream& operator<<(std::ostream& os, const TemplateArray<T> &ba)
{
	os << "size:" << ba.m_size << " ";
	for (int i = 0; i < ba.m_size; ++i)
		os << "data" << i << ba.m_data[i] << " ";
	return os;


}




template<class T>
bool TemplateArray<T>::isValidateIndex(int ind)
{
	return ind > -1 && ind < m_size;
}


#endif

