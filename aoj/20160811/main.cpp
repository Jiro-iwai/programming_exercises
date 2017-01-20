#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
	using sprtr = char_separator<char>;
	using tknzr = tokenizer<sprtr>;
	sprtr sep(" ", "", keep_empty_tokens);


	while(1) {

		int j = 0;
		vector<int> table;

		for( int i = 0; i < 1000; i++ ) {

			auto str = lexical_cast<string>(j);
			while ( str.find("4") != string::npos ||
					str.find("6") != string::npos ) {
				j++;
				str = lexical_cast<string>(j);
			}

			table.push_back(j++);
		}
		
		{
			std::string line;
			getline(cin, line);
			tknzr tkns(line, sep);
			auto it = tkns.begin();
			int old = lexical_cast<int>(*it++);
			if( old == 0 )
				return 0;
			cout << table[old] << endl;
		}
		
	}

    return 0;
}
