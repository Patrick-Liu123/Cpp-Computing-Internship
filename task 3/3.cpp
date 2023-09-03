#include"EBasicArray.h"
#include"BasicArray.h"
#include <iostream>
#include <time.h>
	using namespace std;
	int main()
	{

		EBasicArray e(2,0);
		BasicArray b(2,0);
		std::cout << "EBasicArray-push_back for 59999 times:" << std::endl;
		
		double start1 = clock() / CLOCKS_PER_SEC;

		int asize(59999);
		for (int i = 0; i < asize; ++i)
			e.push_back(1);

		double end1 = clock() / CLOCKS_PER_SEC;
		cout << "\n\truntime " << end1 - start1 << "\n";

		std::cout << "BasicArray-push_back for 59999 times:" << std::endl;

		double start2 = clock() / CLOCKS_PER_SEC;


		for (int i = 0; i < asize; ++i)
			b.push_back(1);

		double end2 = clock() / CLOCKS_PER_SEC;
		cout << "\n\truntime " << end2 - start2<<"\n";

		std::cout << "EBasicArray-insert for 59999 times:" << std::endl;

		double start3 = clock() / CLOCKS_PER_SEC;

		
		for (int i = 0; i < asize; ++i)
			e.insert(1,1);

		double end3 = clock() / CLOCKS_PER_SEC;
		cout << "\n\truntime " << end3 - start3<<"\n";

		std::cout << "BasicArray-insert for 59999 times:" << std::endl;

		double start4 = clock() / CLOCKS_PER_SEC;

		
		for (int i = 0; i < asize; ++i)
			b.intsert(1,1);

		double end4 = clock() / CLOCKS_PER_SEC;
		cout << "\n\truntime " << end4 - start4 << "\n";





		return 0;
	}

