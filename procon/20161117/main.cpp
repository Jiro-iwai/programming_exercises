#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	while(1) {

		bool isfirst = true;
		int M, N, L, S = 0;

		cin >> L;
		if( L == 0 )
			break;
		
		for( int i = 0; i < 12; i++ ) {

			cin >> M >> N;

			S += M - N;

			if( L <= S && isfirst ) {
				cout << i+1 << endl;
				isfirst = false;
			}
		}

		if( isfirst ) {
			cout << "NA" << endl;
		}
	}

    return 0;
}
