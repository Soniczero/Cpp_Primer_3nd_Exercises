/*	C++ Primer 习题20.1
	用类封装为 class exe_20_1
	
	
	已知下列对象定义
	string sa[4] = { "pooh", "tigger", "piglet", "eeyore" };
	vector< string > svec( sa, sa+4 );
	string robin( "christopher robin" );
	const char *pc = robin.c_str();

	int ival = 1024;
	char blank = ' ';

	double dval = 3.14159;
	complex<double> purei( 0, 7 );


	实现下面三个功能：
	(a)  在标准输出上打印出每个对象的值
	(b)  输出 pc 的地址值
	(c)  利用以下条件操作符的结果 输出 ival 和 dval 的最小值
	ival < dval ? ival : dval
*/
#ifndef _EXE_20_1
#define _EXE_20_1

#include <vector>
#include <iostream>
#include <complex>

using namespace std;


class exe_20_1
{
public:
	exe_20_1()
		: robin("christopher robin"),
		ival(1024), blank(' '), 
		dval(3.14159), purei(0, 7)
	{
		// 是否会导致 svec 的初始化出问题？
		sa[0] = "pooh";
		sa[1] = "tiger";
		sa[2] = "piglet";
		sa[3] = "eeyore";

		svec.insert(svec.begin(), sa, sa+4);

		// C风格的字符串怎么初始化？这个右值会不会被销毁导致指针指高错误的地址
		pc = const_cast<char*>(robin.c_str());  //去掉常量
	}

	void print_a();	// (a)  在标准输出上打印出每个对象的值
	void print_pc();	// (b)  输出 pc 的地址值
	void print_min();	// (c)利用以下条件操作符的结果 输出 ival 和 dval 的最小值
						// ival < dval ? ival : dval

private:
	string sa[4];	// 在定义中初始化不得行吧
	vector<string> svec;
	string robin;
	const char *pc;

	int ival;
	char blank;	// space ' ' char

	double dval;
	complex<double> purei;

};



inline void exe_20_1::print_a()
{
	// print sa[4]
	int sa_size = (int) (sizeof(sa)/sizeof(sa[0]));
	
	cout << "sa \t= { ";
	for (int i = 0; i < sa_size; ++i)
		cout << sa[i] << " ";
	cout << "};" << endl;

	// print svec
	cout << "svec \t= { ";
	for (int i = 0, size_N = svec.size(); i < size_N; ++i)
	{
		cout << svec[i];
		if (i != size_N - 1)
			cout << ", ";
	}
	cout << " }" << endl;

	// print robin
	cout << "robin \t= " << robin << endl;

	// print the value of *pc 
	cout << "*pc \t= " << pc << endl;

	// print ival
	cout << "ival \t= " << ival << endl;

	// print char blank
	cout << "blank \t= \'" << blank << '\'' << endl;

	// print dval
	cout << "dval \t= " << dval << endl;

	// print purei
	cout << "purei \t= (" << purei.real() << ", " << purei.imag() << ")" << endl
		<< "Every value printed successfully, congratulation!" << endl << endl;
}


inline void exe_20_1::print_pc()
{
	// print pc's address
	cout << "pc address: " << static_cast<void*>(const_cast<char*>(pc)) << endl << endl;
}


inline void exe_20_1::print_min()
{
	// print minimum of {ival, dval};
	cout << "min of {ival, dval}: " << ((ival < dval) ? ival : dval) << endl << endl;
}

#endif