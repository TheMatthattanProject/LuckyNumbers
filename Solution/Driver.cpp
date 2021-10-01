#include <cmath>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <fstream>
#include <chrono>
#include <random>


using namespace std;

long long calculateLucky(long long n) 
{
	long long retVal = 0;
	string tn = to_string(n);

	int numLess = 6;
	int numMore = 8;

	bool eight = false;
	bool six = false;

	int tn_len = tn.length();
	
	for (int i = 0; i < tn_len; i++)
	{
		//Previous values
		bool psix = six;
		bool peight = eight;
		
		int curr = (int)tn[i] - 48;
		int digit = tn_len - i - 1;

		//Skip calculations if 0
		if (curr == 0)
		{
			continue;
		}

		//Mark 6 or 8
		if (curr == numLess)
		{
			six = true;
		}

		if (curr == numMore)
		{
			eight = true;
		}

		//pre processing
		if (!(peight || psix) && curr > numMore)
		{
			retVal += (pow(9, digit));
			curr--;
		}

		if (!(peight || psix) && curr > numLess)
		{
			retVal += (pow(9, digit));
			curr--;
		}


		//RUnning code
		if (!psix && !peight)
		{
			retVal += (long long)curr * 2 * (pow(9, digit) - pow(8, digit));
			
		}

		if (psix)
		{
			if (curr > numMore)
			{
				curr--;
			}
			retVal += (long long)curr * (pow(9, digit));
		}

		if (peight)
		{
			if (curr > numLess)
			{
				curr--;
			}
			retVal += (long long)curr * (pow(9, digit));
		}

		if (six && eight)
		{
			break;
		}

	}


	if (six ^ eight)
	{
		retVal++;
	}

	
	return retVal;
}

long long luckyRange(long long a, long long b)
{
	return calculateLucky(b) - calculateLucky(a);
}


int main() 
{
	std::mt19937_64 gen(std::random_device{}());


	long long a = gen();
	long long b = gen();
	bool once = false;
	while (!once){
		cout << "Please enter in two numbers" << endl;
		once = true;
		//cin >> a >> b;
		//while (a < 0 || b < 0)
		//{
		//	cout << "I don't feel like dealing with negative numbers tbh" << endl;
		//	cin >> a >> b;
		//}

		long long temp = 0;
		if (a > b)
		{
			temp = a;
			a = b;
			b = temp;
		}




		auto t_start = chrono::high_resolution_clock::now();
	

		long long res = luckyRange(a, b);
		cout << "A: " << a << ", B: " << b << ", Answer: " << res << endl;

	


		// the work...;
		auto t_end = std::chrono::high_resolution_clock::now();
		double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count();


		cout << elapsed_time_ms << "ms\n\n";
	}


	return 0;
}