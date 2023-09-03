#include"BasicArray.h"
#include<iostream>



int main()
{
	BasicArray a(3,1);
	for (int i = 0; i < 3; i++)
		std::cout << a[i] << " ";
	a.push_back(3);
	for (int i = 0; i < 4; i++)
		std::cout << a[i]<< " ";
	return 0;
}