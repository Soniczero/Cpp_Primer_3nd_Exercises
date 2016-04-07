/* Exercise 20.3
Read from standard input an unknown number of strings.Store them in a list.Determine both the shortest
and longest strings.
*/

#include <iostream>
#include <list>
#include <vector>
#include <string>

using namespace std;

class exe_20_3
{
public:
	exe_20_3()
	{
		cout << "\n\nThis is Exercise 20.3----------------------------\n" << endl;
		list<string> lval;
		
		int max_length = 0, // 用于计量长度
			min_length = 100;

		string max_str, min_str; // string values of max, min

		string buffer;
		int buf_len;

		cout << "Please enter test words, exit by enter '.':\n";
		while (cin >> buffer)
		{
			if (buffer == ".")
				break;
			
			filter_str(buffer);
			// filt_cap(buffer);
			buf_len = buffer.length();

			if (buf_len > max_length)
			{
				max_length = buf_len;
				max_str = buffer;
			}
			else
				if (buf_len < min_length)
				{
					min_length = buf_len;
					min_str = buffer;
				}

			lval.push_back(buffer);
		}

		if (cin.eof())
			cout << "Get eof, read complete!" << endl;
		else
			cout << "Oh, get a error, read can't continue..." << endl;

		// print_list(lval);
		list<string>::iterator it(lval.begin()), it_end(lval.end());

		cout << "list printed as follow:\n";
		for (int cnt = 0; it != it_end; ++it)
			cout << *it << ((cnt++ % 8) ? ", " : "\n");
		cout << "\nPrint Complete!\n"
			<< "The longest word\t:" << max_str << " [ " << max_length << " ]\n"
			<< "The shortest word\t:" << min_str << " [ " << min_length << " ]\n"
			<< "Complete !" << endl;
	}

	inline void filter_str(string &);
	// inline void filt_cap(string &);
	// inline void print_list(list<string> &);
};

void exe_20_3::filter_str(string& str)
{
	string::size_type pos = 0;
	string filter_caps = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string filter_sign = "\",.;:!?)(\\/";
	
	while ((pos = str.find_first_of(filter_sign, pos)) != string::npos)
		str.erase(pos, 1); 
	pos = 0;
	while ((pos = str.find_first_of(filter_caps, pos)) != string::npos)
		str[pos] = tolower(str[pos]);
}


/*
void exe_20_3::print_list(list<string> & list_obj)
{
	list<string>::iterator it(list_obj.begin()), it_end(list_obj.end());

	cout << "list printed as follow:";
	for (int cnt = 0; it != it_end; ++it)
		cout << *it << ((cnt++ % 8) ? ", " : "\n");
	cout << "\nPrint Complete!\n"
		<< "The longest word\t:" << max_str
		<<

}*/