#include <iostream>
#include <fstream>
#include <ctime>
#include "MyAlgorithm.h"

int main()
{
	using std::cout;
	using std::endl;
	using std::ofstream;
	
	//Problem 2
	cout << "Test\n";
	cout << "----------------------\n";
	cout << "Sum Algorithm A : " << sumAlgorithmA(10) << endl;
	cout << "Sum Algorithm B : " << sumAlgorithmB(10) << endl;
	cout << "Sum Algorithm C : " << sumAlgorithmC(10) << endl;

	//Problem 3
	//Algorithm A
	ofstream fout("Algorithm A Result.txt");
	if (fout.bad())
	{
		std::cerr << "Unknown Error\n";
		return 1;
	}
	fout << std::fixed;
	fout.precision(6);
	clock_t start, end;
	double duration = 0.0;
	for (int n = 0, trial = 0; trial != 100; n += 30000, ++trial)
	{
		fout << "n(" << n << ") : ";
		start = clock();
		sumAlgorithmA(n);
		end = clock();
		duration = (double(end) - start) / CLOCKS_PER_SEC;
		fout << duration << endl;
	}
	fout.close();
	duration = 0.0;

	//Algorithm B
	fout.open("Algorithm B Result.txt");
	if (fout.bad())
	{
		std::cerr << "Unknown Error\n";
		return 1;
	}
	for (int n = 0, trial = 0; trial != 100; n += 30000, ++trial)
	{
		fout << "n(" << n << ") : ";
		start = clock();
		sumAlgorithmB(n);
		end = clock();
		duration = (double(end) - start) / CLOCKS_PER_SEC;
		fout << duration << endl;
	}
	fout.close();
	duration = 0.0;

	//Algorithm C
	fout.open("Algorithm C Result.txt");
	if (fout.bad())
	{
		std::cerr << "Unknown Error\n";
		return 1;
	}
	for (int n = 0, trial = 0; trial != 5; n += 5000, ++trial)
	{
		fout << "n(" << n << ") : ";
		start = clock();
		sumAlgorithmC(n);
		end = clock();
		duration = (double(end) - start) / CLOCKS_PER_SEC;
		fout << duration << endl;
	}
	fout.close();

	return 0;
}