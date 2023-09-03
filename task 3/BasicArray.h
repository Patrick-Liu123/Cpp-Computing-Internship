#pragma once
#ifndef _BASICARRAY_H_
#define _BASICARRAY_H_

#include<iostream>

class BasicArray
{
private:
	double* data_;
	int size_;
public:
	BasicArray() :data_(0), size_(0) {}
	BasicArray(int size, double value = 0);
	BasicArray(const BasicArray& ba);
	BasicArray& operator=(const BasicArray& array);
	~BasicArray() { delete[]data_; }
	int size()const { return size_; }
	int resize(int num, double elem = 0.0);
	double at(int ind);
	double operator[](int ind)const;
	double& operator[](int ind);
	int push_back(double elem);
	int intsert(int ind, double value);
	void erase(int ind);
	friend std::ostream& operator<<(std::ostream& os, const BasicArray &ba);
private:
	inline bool isValidateIndex(int ind);
};

BasicArray::BasicArray(int size, double value)
{

	size_ = size;
	data_ = new double[size];
	if (NULL == data_)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < size; i++)
		data_[i] = value;

}

BasicArray::BasicArray(const BasicArray& ba)
{



	size_ = ba.size_;
	data_ = new double[size_];
	if (NULL == data_)
	{
		std::cout << "no enough memory" << std::endl;

	}
	for (int i = 0; i < size_; i++)
		data_[i] = ba.data_[i];

}



int BasicArray::resize(int num, double elem)
{

	if (num == size_)
		return 1;

	BasicArray pa;
	pa.size_ = size_;
	pa.data_ = new double[size_];
	for (int i = 0; i < size_; i++)
		pa.data_[i] = data_[i];

	delete[]data_;
	data_ = new double[num];
	if (num < size_)
	{
		for (int i = 0; i < num; i++)
			data_[i] = pa.data_[i];
		size_ = num;
		return 1;
	}

	for (int i = 0; i < size_; i++)
		data_[i] = pa.data_[i];
	for (int i = size_; i < num; i++)
		data_[i] = elem;
	size_ = num;
	return 1;

}


double BasicArray::at(int ind)
{

	if (ind < 0 || ind >= size_)

		return 0;



	return data_[ind];
}


double BasicArray::operator[](int ind)const
{
	if (ind < 0 || ind >= size_)

		return 0;

	return data_[ind];
}



double& BasicArray::operator[](int ind)
{


	return data_[ind];
}




int BasicArray::push_back(double elem)
{

	BasicArray pa;
	pa.size_ = size_;
	pa.data_ = new double[size_];
	for (int i = 0; i < size_; i++)
		pa.data_[i] = data_[i];
	delete[]data_;
	data_ = new double[size_ + 1];
	for (int i = 0; i < size_; i++)
		data_[i] = pa.data_[i];
	data_[size_] = elem;
	size_ = size_ + 1;
	return size_;

}



int BasicArray::intsert(int ind, double value)
{
	if (ind < 0 || ind >= size_)

		return 0;




	BasicArray pa;
	pa.size_ = size_;
	pa.data_ = new double[size_];
	for (int i = 0; i < size_; i++)
		pa.data_[i] = data_[i];
	delete[]data_;
	data_ = new double[size_ + 1];
	for (int i = 0; i < ind; i++)
		data_[i] = pa.data_[i];
	data_[ind] = value;
	for (int i = ind + 1; i < size_ + 1; i++)
		data_[i] = pa.data_[i - 1];
	size_ = size_ + 1;

	return size_;
}




void BasicArray::erase(int ind)
{

	BasicArray pa;
	pa.size_ = size_;
	pa.data_ = new double[size_];
	for (int i = 0; i < size_; i++)
		pa.data_[i] = data_[i];
	delete[]data_;
	data_ = new double[size_ - 1];
	for (int i = 0; i < ind; i++)
		data_[i] = pa.data_[i];

	for (int i = ind + 1; i < size_; i++)
		data_[i - 1] = pa.data_[i];
	size_ = size_ - 1;





}


BasicArray& BasicArray::operator=(const BasicArray& array)
{
	BasicArray ha;
	ha.size_ = array.size_;
	ha.data_ = new double[ha.size_];
	for (int i = 0; i < ha.size_; i++)
		ha.data_[i] = array.data_[i];
	return ha;
}




std::ostream& operator<<(std::ostream& os, const BasicArray &ba)
{
	os << "size:" << ba.size_ << " ";
	for (int i=0; i<ba.size_; i++)
		os << "data" << i << ba.data_[i] << " ";
	return os;


}






std::ostream& operator<<(std::ostream& os, const BasicArray &ba);
bool BasicArray::isValidateIndex(int ind)
{
	return ind > -1 && ind < size_;
}


#endif