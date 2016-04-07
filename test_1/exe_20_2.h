/*	C++ Primer 3th 习题20.2，用类封装
	
	Exercise 20.2
	Read from standard input a sequence of types: string, double, string, int, string. Check whether an input
	error occurs.
*/

#include <iostream>

using namespace std;

class exe_20_2
{
public:
	exe_20_2()
	{
		string s1, s2, s3;
		int ival;
		double dval;

		cout << "\n\nThis is Exercise 20.2----------------------------\n"
			<<"test type:\nstring s1, s2, s3\nint ival\ndouble dval\n"
			<<"test string: cin >> s1 >> ival >> s2 >> dval >> s3:"<< endl;

		while (cin >> s1 >> ival >> s2 >> dval >> s3)
			cout << "\nGet inputs like these:\n"
			<< s1 << '\n'
			<< ival << '\n'
			<< s2 << '\n'
			<< dval << '\n'
			<< s3 << endl;
		if (cin.eof())
			cout << "Get eof() error." << endl;
		else
			cout << "Get input error." << endl;
	}
};