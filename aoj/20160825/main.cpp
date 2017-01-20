#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	vector<vector<char>> table;

	int H, W;
	cin >> H;
	cin >> W;

	for( int i = 0; i < H; i++ ) {
		vector<char> row;
		for( int j = 0; j < W; j++ ) {
			char c;
			cin >> c;
			row.push_back(c);
		}
		table.push_back(row);
	}

	for( int i = 0; i < H; i++ ) {
		for( int j = 0; j < W; j++ ) {

			bool is_come = false;
			int count = 0;
			for( int k = j; -1 < k; k--, count++ ) {
				char c = table[i][k];
				if( c == 'c' ) {
					cout << count;
					if( j != W-1 ) cout << " ";
					is_come = true;
					break;
				}
			}
			if( !is_come ) {
				cout << -1;
				if( j != W-1 ) cout << " ";
			}
		}
		cout << endl;
	}

    return 0;
}
