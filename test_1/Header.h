// 未完工的字处理程序

string text;

static const string default_caps("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
int fix_capital(string &text, string caps = default_caps);



vector<string> query_text;

// UserQuery user_query;
// init_query_statics();

do {
	query_text.clear();

	cout << "Enter a query -- please separate each item "
		<< "by a space.\n"
		<< "Terminate query (or session) with a dot( . ).\n\n"
		<< "==> ";

	while (cin >> text)
	{
		if (text == ".")
			break;
		/*
		// remove all capitalization ...
		string::size_type pos = 0;
		while ((pos = text.find_first_of(caps, pos))
		!= string::npos)
		text[pos] = tolower(text[pos]);
		*/
		fix_capital(text);

		query_text.push_back(text);
	}

	if (!query_text.empty())
	{
		vector<string>::iterator qit = query_text.begin(), qit_end = query_text.end();
		for (; qit != qit_end; ++qit)
			cout << *qit << endl << endl;
	}


} while (!query_text.empty());
cout << "Ok, bye!\n";



int fix_capital(string &text, string caps)
{
	// remove all capitalization ...
	int any_caps = 0; // any_caps used to sign if any caps changed
	string::size_type pos = 0;
	while ((pos = text.find_first_of(caps, pos)) != string::npos)
	{
		text[pos] = tolower(text[pos]);
		++any_caps;
	}

	return any_caps;
}