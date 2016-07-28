#include <iostream>
#include <string>
#include <algorithm>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
//#include <vector>
//#include <list>
//#include <numeric>

using namespace std;
using namespace boost;

int main(int argc, char* argv[])
{
	using sprtr = char_separator<char>;
    using tknzr = tokenizer<sprtr>;
    sprtr sep(" ", "", keep_empty_tokens);

    string line;
    while( getline(cin, line) ) {
        tknzr tkns(line, sep);
        for( auto& tk : tkns ) {
			cout << tk << " ";
        }
		cout << endl;
    }
    
    return 0;
}
