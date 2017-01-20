#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	int n;
	
	while( cin >> n ) {

		if( n == 0 ) break;

		int p, d1, d2;
		int maxd = 0;
		int maxp = 0;
		
		for( int i = 0; i < n; i++ ) {
			cin >> p >> d1 >> d2;
			int d = d1+d2;
			if( maxd <= d ) {
				maxd = d;
				maxp = p;
			}
		}

		cout << maxp << " " << maxd << endl;
	}

    return 0;
}

