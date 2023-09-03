#pragma once
#include<iostream>
using namespace std;
int g_arraysize(0);
double *p_arraydata(0);




int SetArraySize(int size)
{
	int i;
	g_arraysize = size;
	p_arraydata = new double[size];
	for (i = 0; i < size; i++)
		p_arraydata[i] = 0;
	if (NULL == p_arraydata)
	{
		cout << "no enough memory" << endl;
		return 0;
	}
	return 1;
	
}



int SetValue(int k, double value)
{
	if (NULL == p_arraydata)
		return 0;

	if (k < 0 || k >= g_arraysize)
		return 0;

	p_arraydata[k] = value;
	return k;
}


void PrintArray()
{
	int i;
	for (i = 0; i < g_arraysize; i++)
		cout << p_arraydata[i] << " ";

}

void FreeArray()
{
	delete[]p_arraydata;
	p_arraydata = 0;
	g_arraysize = 0;

}





