#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

vector<unsigned int> table { 63, 6, 91, 79, 102, 109, 125, 39, 127, 111 };

void solve(int from, int to)
{
	unsigned int b0	= 0;
	if( from != -1 ) {
		b0 = table[from];
	} 
	unsigned int b1 = table[to];
	cout << static_cast<bitset<7>>( b0 ^ b1 ) << endl;
}

int main(int argc, char* argv[])
{
	int num, d;
	vector<int> ds;

	while(1) {
		cin >> num;
		if( num == -1 )
			break;

		for( int i = 0; i < num; i++ ) {
			cin >> d;
			ds.push_back(d);
		}
		int v0 = -1;
		for( auto  v1 : ds ) {
			solve(v0, v1);
			v0 = v1;
		}
		ds.clear();		
	}

    return 0;
}
