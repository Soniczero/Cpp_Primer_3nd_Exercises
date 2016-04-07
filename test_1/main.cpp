#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <complex>


#include "exe_20_1.h"
#include "exe_20_2.h"
#include "exe_20_3.h"

using namespace std;



int main(int argc, char* argv[])
//int main() 
{
	cout << "Program starts. Begin to handle the command line arguments:\n"
		<< "argc:" << argc << endl;

	cout << "But now, we won't deal with them." << endl;
	
	// 用try block捕捉arguments错误
/*	try
	{
		for (int i = 0; i < argc; ++i)
		{
			cout << "argv[" << i << "]: " << argv[i] << endl;

			char* pchar = argv[i];
			switch (pchar[0])
				case '-':
				default:
		}
	}
	catch
*/

	// 作业申明
	inline void do_20_1();
	inline void do_20_2();

	cout << "Please select the exercise you want to run:\n"
		<< "[1] - exercise 20.1;\n"
		<< "[2] - exercise 20.2;\n"
		<< "[3] - exercise 20.3;\n"
		<< "Type the number in [] above or exit by type '.':";

	char sel_char;
	while (cin >> sel_char)
	{
		switch (sel_char)
		{
		case '1':
			do_20_1();
			break;
		case '2':
			exe_20_2::exe_20_2();
			break;
		case '3':
			exe_20_3::exe_20_3();
			break;
		case '.':
			cout << "Oh, you want to exit. Then bye!" << endl;
			return 0;
		case '\n':
			cout << "Catch \\n";
		default:
			cout << "\nUnfinished." << endl;
		}
		
		cout << "What to do next? Please select:\n"
			<< "[1] - exercise 20.1;\n"
			<< "[2] - exercise 20.2;\n"
			<< "[3] - exercise 20.3;\n"
			<< "Type the number in [] above or exit by type '.':";
	}
	

	return 0;
}




void do_20_1()
{
	cout << "\n\nThis is Exercise 20.1----------------------------\n" << endl;
	exe_20_1 doit;
	doit.print_a();
	doit.print_pc();
	doit.print_min();
}