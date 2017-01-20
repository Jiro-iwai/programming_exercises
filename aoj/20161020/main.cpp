#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <cmath>

using namespace std;


const int MAX = 15;
int c[MAX+1][MAX+1];
int memo[3][MAX+1][MAX+1];
int X, Y;

int solve(int x0, int x, int y)
{
	if( -1 < x && x < X && Y-1 <= y )
		return 1;
	
	int& n = memo[x-x0+1][x][y];
	if( n != -1 )
		return n;
	
	int r = 0;
	int p = c[x][y];

	if( p != 2 ) {

		if( -1 < x-1 && c[x-1][y+1] != 1 )
			r += solve(x,x-1,y+1);

		if( c[x][y+1] != 1 )	
			r += solve(x,x,y+1);

		if( x+1 < X && c[x+1][y+1] != 1 )
			r += solve(x,x+1,y+1);

	} if( p == 2 && x == x0 ) {

		if( c[x][y+2] != 1 )
			r += solve(x,x,y+2);
	}

	n = r;
	return n;
}

int main(int argc, char* argv[])
{
	while(1) {

		cin >> X;
		cin >> Y;

		if( X == 0 && Y == 0)
			break;

		for( int j = 0; j < Y; j++ ) {		
			for( int i = 0; i < X; i++ ) {
				int p; cin >> p;
				c[i][j] = p;
				memo[0][i][j] = -1;
				memo[1][i][j] = -1;
				memo[2][i][j] = -1;
			}
		}

		int r = 0;
		for( int i = 0; i < X; i++ ) {
			if( c[i][0] != 1 )
				r += solve(i,i,0);
		}

		cout << r << endl;
	}

    return 0;
}
