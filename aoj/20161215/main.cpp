#include <iostream>

using namespace std;

int n;
int d[30];
int v[30];

int gcm(int a, int b) {
	int result = a;
	int k = 0;
	int n = b;
	do {
		k = result % n;
		result = n;
		n = k;
	} while(k != 0);
	return result;
}

int lcm(int a, int b) {
	int g;
	g = gcm(a, b);
	return a*b/g;
}

int lcm_n(int* num) {
	int l;
	l = num[0];
	for ( int i = 1; i < n; i++ ) {
		l = lcm(l, num[i]);
	}
	return l;
}

int main(int argc, char* argv[])
{
	while( cin >> n ) {

		for( int i = 0; i < n; i++ ) {
			cin >> d[i] >> v[i];
		}

		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < n; j++ ) {
				if( i != j ) {
					d[i] *= v[j];
				}
			}			
		}

		int lcm = lcm_n(d);
		
		for( int i = 0; i < n; i++ ) {
			cout << lcm / d[i] << endl;
		}

	}

    return 0;
}

