#include"TemplateArray.h"
#include<iostream>

int main()
{

	TemplateArray<int>a(3, 1);
	std::cout << "a=";
	for (int i = 0; i < 3; i++)
		std::cout << a[i] << " ";
	a.push_back(2);
	std::cout << "\n" << "push_back(2):";

	for (int i = 0; i < 4; i++)
		std::cout << a[i] << " ";


	std::cout << "\n";
	TemplateArray<char>b(3, 'a');
	std::cout << "b=";
	for (int i = 0; i < 3; i++)
		std::cout << b[i] << " ";
	b.insert(1, 'b');
	std::cout << "\n" << "insert(1,'b'):";

	for (int i = 0; i < 4; i++)
		std::cout << b[i] << " ";

	std::cout << "\n";
	TemplateArray<float>c(3, 3.14);
	std::cout << "c=";
	for (int i = 0; i < 3; i++)
		std::cout << c[i] << " ";
	TemplateArray<float>d(c);

	std::cout << "\n" << "TemplateArray<float>d(c),d=";

	for (int i = 0; i < 3; i++)
		std::cout << d[i] << " ";

	std::cout << "\n";
	TemplateArray<float>e(3, 3.14);
	std::cout << "e=";
	for (int i = 0; i < 3; i++)
		std::cout << e[i] << " ";
	e.reserve(2, 0);
	std::cout << "\n" << "reserve(2, 0):";
	for (int i = 0; i < e.size(); i++)
		std::cout << d[i] << " ";



	std::cout << "\n";
	TemplateArray<float>f(3, 3.14);
	std::cout << "f=";
	for (int i = 0; i < 3; i++)
		std::cout << f[i] << " ";
	f.reserve(5, 0);
	std::cout << "\n" << "reserve(5, 0):";
	for (int i = 0; i < f.size(); i++)
		std::cout << f[i] << " ";

	return 0;
}
