#pragma once
#ifndef _EBASICARRAY_H_
#define _EBASICARRAY_H_

#include<iostream>

class EBasicArray
{
private:
	double* data_;
	int size_;
	int capacity_;
public:
	EBasicArray() :data_(0), size_(0),capacity_(0) {}
	EBasicArray(int size, double value = 0);
	EBasicArray(const EBasicArray& ba);
	EBasicArray& operator=(const EBasicArray& array);
	~EBasicArray() { delete[]data_; }
	
	void cap();
	
	
	int size()const { return size_; }
	int reserve(int num, double elem = 0.0);
	double at(int ind);
	double operator[](int ind)const;
	double& operator[](int ind);
	int push_back(double elem);
	int insert(int ind, double value);
	void erase(int ind);
	friend std::ostream& operator<<(std::ostream& os, const EBasicArray &ba);
private:
	inline bool isValidateIndex(int ind);
};

EBasicArray::EBasicArray(int size, double value)
{

	size_ = size;
	capacity_ = size;
	data_ = new double[capacity_];
	if (NULL == data_)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < size; i++)
		data_[i] = value;

}

EBasicArray::EBasicArray(const EBasicArray& ba)
{



	size_ = ba.size_;
	capacity_ = ba.capacity_;
	data_ = new double[capacity_];
	if (NULL == data_)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < size_; i++)
		data_[i] = ba.data_[i];
	for (int i = size_; i < capacity_; i++)
		data_[i] = 0;
}



void EBasicArray::cap()
{
	std::cout << capacity_;
}


int EBasicArray::reserve(int num, double elem)
{

	if (num <= capacity_&& num >= size_)
	{
		for (int i = size_; i < num; i++)
			data_[i] = elem;
		size_ = num;
		return 1;
	}
	
	
	EBasicArray pa;
	
	if (num > capacity_)

	{
		pa.size_ = size_;
		pa.capacity_ = capacity_;
		pa.data_ = new double[capacity_];
		for (int i = 0; i < size_; i++)
			pa.data_[i] = data_[i];
		for (int i = size_; i < capacity_; i++)
			pa.data_[i] = 0;
		delete[]data_;
		while (num > capacity_)
			capacity_ *= 2;
		data_ = new double[capacity_];

		for (int i = 0; i < size_; i++)
			data_[i] = pa.data_[i];
		for (int i = size_; i < num; i++)
			data_[i] = elem;
		size_ = num;
		return 1;
	}
	

	if (num < size_)
	{
		
		size_ = num;
		return 1;
	}





}


double EBasicArray::at(int ind)
{

	if (ind < 0 || ind >= size_)

		return 0;



	return data_[ind];
}


double EBasicArray::operator[](int ind)const
{
	if (ind < 0 || ind >= size_)

		return 0;

	return data_[ind];
}



double& EBasicArray::operator[](int ind)
{


	return data_[ind];
}




int EBasicArray::push_back(double elem)
{

	if (capacity_ >= size_ + 1)
	{
		data_[size_] = elem;
		return size_;
	}


	if (capacity_ == 0)
	{
		delete[]data_;
		data_ = new double[1];
		size_ = 1;
		data_[0] = elem;
		return size_;
	}

	if (capacity_ < size_ + 1)
	{
		EBasicArray pa;
		pa.size_ = size_;
		pa.capacity_ = capacity_;
		pa.data_ = new double[capacity_];
		for (int i = 0; i < capacity_; i++)
			pa.data_[i] = data_[i];
		delete[]data_;
		data_ = new double[capacity_ * 2];
		for (int i = 0; i < size_; i++)
			data_[i] = pa.data_[i];
		data_[size_] = elem;
		size_ = size_ + 1;
		capacity_ = capacity_ * 2;
		return size_;
	}

}



int EBasicArray::insert(int ind, double value)
{
	if (ind < 0 || ind >= size_)

		return 0;
	if (capacity_ == 0)
	{
		delete[]data_;
		data_ = new double[1];
		size_ = 1;
		data_[0] = value;
		return size_;
	}

	if (size_ + 1 > capacity_)

	{
		EBasicArray pa;
		pa.size_ = size_;
		pa.capacity_ = capacity_;
		pa.data_ = new double[capacity_];
		for (int i = 0; i < size_; i++)
			pa.data_[i] = data_[i];
		delete[]data_;
		data_ = new double[capacity_*2];
		for (int i = 0; i < ind; i++)
			data_[i] = pa.data_[i];
		data_[ind] = value;
		for (int i = ind + 1; i < size_ + 1; i++)
			data_[i] = pa.data_[i - 1];

		size_ = size_ + 1;
		capacity_ = capacity_ * 2;

		return size_;
	}

	if (size_ + 1 <= capacity_)
	{
		for (int i = size_; i >= ind; i--)
		
			data_[i] = data_[i - 1];
		
		data_[ind] = value;
		size_ = size_ + 1;
		return size_;

	}


}




void EBasicArray::erase(int ind)
{
	if (ind < size_)
	{
		for (int i = ind + 1; i < size_; i++)
			data_[i - 1] = data_[i];
		size_ = size_ - 1;

	}


}


EBasicArray& EBasicArray::operator=(const EBasicArray& array)
{
	EBasicArray ha;
	ha.size_ = array.size_;
	ha.capacity_ = array.capacity_;
	ha.data_ = new double[ha.capacity_];
	for (int i = 0; i < ha.size_; i++)
		ha.data_[i] = array.data_[i];
	return ha;
}




std::ostream& operator<<(std::ostream& os, const EBasicArray &ba)
{
	os << "size:" << ba.size_ << " ";
	for (int i=0; i<ba.size_; i++)
		os << "data" << i << ba.data_[i] << " ";
	return os;


}






std::ostream& operator<<(std::ostream& os, const EBasicArray &ba);
bool EBasicArray::isValidateIndex(int ind)
{
	return ind > -1 && ind < size_;
}


#endif
