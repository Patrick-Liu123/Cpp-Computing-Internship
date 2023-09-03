#include"BasicDynamicArray_function.h"
#include<iostream>
#include<assert.h>
using namespace std;



int main()
{
	SetArraySize(2);
	assert(2 == g_arraysize);
	assert(0 == p_arraydata[1]);

	SetValue(0, 1.0);
	SetValue(1, 2.0);
	assert(2.0 == p_arraydata[1]);

	PrintArray();

	FreeArray();
	assert(0 == g_arraysize);
	assert(0 == p_arraydata);

	return 0;
}