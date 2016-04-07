/*	C++ Primer ϰ��20.1
	�����װΪ class exe_20_1
	
	
	��֪���ж�����
	string sa[4] = { "pooh", "tigger", "piglet", "eeyore" };
	vector< string > svec( sa, sa+4 );
	string robin( "christopher robin" );
	const char *pc = robin.c_str();

	int ival = 1024;
	char blank = ' ';

	double dval = 3.14159;
	complex<double> purei( 0, 7 );


	ʵ�������������ܣ�
	(a)  �ڱ�׼����ϴ�ӡ��ÿ�������ֵ
	(b)  ��� pc �ĵ�ֵַ
	(c)  �������������������Ľ�� ��� ival �� dval ����Сֵ
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
		// �Ƿ�ᵼ�� svec �ĳ�ʼ�������⣿
		sa[0] = "pooh";
		sa[1] = "tiger";
		sa[2] = "piglet";
		sa[3] = "eeyore";

		svec.insert(svec.begin(), sa, sa+4);

		// C�����ַ�����ô��ʼ���������ֵ�᲻�ᱻ���ٵ���ָ��ָ�ߴ���ĵ�ַ
		pc = const_cast<char*>(robin.c_str());  //ȥ������
	}

	void print_a();	// (a)  �ڱ�׼����ϴ�ӡ��ÿ�������ֵ
	void print_pc();	// (b)  ��� pc �ĵ�ֵַ
	void print_min();	// (c)�������������������Ľ�� ��� ival �� dval ����Сֵ
						// ival < dval ? ival : dval

private:
	string sa[4];	// �ڶ����г�ʼ�������а�
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