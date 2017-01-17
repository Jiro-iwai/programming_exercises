#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	int N;

	while(1) {
		cin >> N;
		if( N == 0 )
			break;
		
		int sum0 = 0;
		int sum1 = 0;	
		for( int i = 0; i < N; i++ ) {
			int d;
			cin >> d;

			if ( d == 1 ) {
				sum0++;
			}

			if( 2 <= d ) {
				sum1++;			
			}
		}
		if( sum1 == 0 ) {
			cout << "NA" << endl;			
		} else {
			cout << sum0 + sum1 + 1 << endl;
		}
	}

    return 0;
}
