#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cmath>

using namespace std;

vector<int> price;
list<int> primes;

const int M = 1000000;
const int L = 30;
const int D = 10;
const int S = M/D;
pair<int,int> memo[S][L];

void mk_primes(int x)
{
	for( int i = 3; i <= x; i+=2 ) {
		for( int j = 3; j <= sqrt(i); j++ ) {
			if( i % j == 0 ) {
				goto NEXT;
			}
		}
		primes.push_front(i);
	NEXT:;		
	}
}

int solve(int x, int pos)
{
	pair<int,int>& pa = memo[x%S][pos];
	if( pa.first == x && -1 < pa.second )
		return pa.second;

	int result = 0;

	int p = price[pos++];
	int s = x / p;

	if( price.size() == pos ) {

		if( s*p == x ) {
			result = 1;
			// cout << "(" << p << "*" << s << ")";
		}
		
		
	} else {

		for( int i = 0; i <= s; i++ ) {

			int t = i * p;
			result = solve(x-t, pos);
			if( result ) {
				// cout << "(" << p << "*" << i << ")";
				break;
			}
		}
	}

	pa.first = x;
	pa.second = result;
	return result;
}

int main(int argc, char* argv[])
{
	mk_primes(M);
	
	while(1) {

		int n; cin >> n;
		int x; cin >> x;

		if( n == 0 && x == 0)
			break;
	
		for( int i = 0; i < n; i++ ) {
			int p; cin >> p;
			price.push_back(p);
		}

		for( int i = 0; i < S; i++ ) {
			for( int j = 0; j < L; j++ ) {			
				memo[i][j] = make_pair(-1,-1);
			}
		}

		for( auto p : primes ) {

			if( x < p )
				continue;
			
			if( solve(p, 0) ) {
				cout << p << endl;
				goto LAST;
			}
		}

		cout << "NA" << endl;

	LAST:;

		price.clear();

	}

    return 0;
}
