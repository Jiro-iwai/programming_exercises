#include <climits>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

vector<int> mc;

int cost(int w)
{
	int c = 0;
	
	if( w <= 10 ) {
		c = 1150;
	} else if( 10 < w && w <= 20 ) {
		c = 1150 + (w - 10)*125;
	} else if( 20 < w && w <= 30 ) {
		c = 1150 + 125*10 + (w - 20)*140;
	} else if( 30 < w ) {
		c = 1150 + 125*10 + 10*140 + (w - 30)*160;
	}

	return c;
}

int main(int argc, char* argv[])
{
	int w;
	
	while(1) {

		cin >> w;

		if( w == -1 ) break;

		mc.push_back(cost(w));

	}

	for( int i = 0; i < mc.size(); i++ ) {

		int c0 = mc[i];

		cout << 4280 - c0 << endl;
		
	}

    return 0;
}

