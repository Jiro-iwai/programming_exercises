#include <iostream>
#include <set>
#include <vector>

using namespace std;

set<int> con;
vector<int> lcon;

int main(int argc, char* argv[])
{
	int c0, c1, c2, c3, c4;
	
	while(1) {

		cin >> c0;
		if( c0 == 0 )
			break;
		
		cin >> c1 >> c2 >> c3 >> c4;

		con.insert(c0);	lcon.push_back(c0);
		con.insert(c1);	lcon.push_back(c1);
		con.insert(c2);	lcon.push_back(c2);
		con.insert(c3);	lcon.push_back(c3);
		con.insert(c4);	lcon.push_back(c4);

		for( auto c : lcon ) {

			int o0 = c%3 + 1;
			int o1 = (c+1)%3 + 1;

			bool f0 = ( con.find(o0) != con.end() );
			bool f1 = ( con.find(o1) != con.end() );

			if( c0 == c1 && c1 == c2 && c2 == c3 && c3 == c4 ){
				cout << 3 << endl;				
			}
			
			else if( f0 && !f1 ) cout << 1 << endl;			
			else if( !f0 && f1 ) cout << 2 << endl;
			else if( f0 && f1 ) cout << 3 << endl;
		}

		con.clear();
		lcon.clear();
	}

    return 0;
}
