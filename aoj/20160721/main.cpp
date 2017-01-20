#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

int solve( int k, list<int>& dv )
{
	int count = 1;
	int len = accumulate(dv.begin(),dv.end(),0);

	while ( count++ < k ) {
		if( len == 0 ) break;
		len -= (*dv.begin());
		dv.pop_front();
	}

	return len;
}

int main(int argc, char* argv[])
{
	typedef char_separator<char> separator;	
    typedef tokenizer<separator> tokenizer;
    separator sep(" ", "", keep_empty_tokens);	

	string line;	

	int N;
	{
		getline(cin, line);		
		tokenizer tokens(line, sep);
		N = lexical_cast<int>(*tokens.begin());
	}

	for( int i = 0; i < N; i++ ) {

		int n, k;
		{
			getline(cin, line);			
			tokenizer tokens(line, sep);			
			tokenizer::iterator tok = tokens.begin();
			n = lexical_cast<int>(*tok++);
			k = lexical_cast<int>(*tok);
		}

		vector<int> pv;
		{
			getline(cin, line);			
			tokenizer tokens(line, sep);
			for( auto sp : tokens ) {
				pv.push_back(lexical_cast<int>(sp));
			}
		}

		list<int> dv;
		int pp = -1;
		for( auto p : pv ) {
			int d = p - pp;
			if( pp != -1 ) {
				dv.push_back(d);
			}
			pp = p;
		}

		dv.sort(greater<int>());
		cout << solve(k, dv) << endl;
	}
	
	return 0;
}
