#include <iostream>
#include <exception>
#include <vector>
#include <algorithm>


using namespace std;

int n, m;
int A[100][100];
int B[100][100];
int C[100][100];

pair<int,int> search()
{
	bool flg = true;

	vector<pair<int,int>> v0;;
	
	for( int i = 0; i <= n-m; i++ ) {
		for( int j = 0; j <= n-m; j++ ) {

			vector<pair<int,int>> v1;			

			for( int p = 0; p < m; p++ ) {
				for( int q = 0; q < m; q++ ) {
					if( C[p][q] != A[i+p][j+q] && C[p][q] != -1 ) {
						flg = false;
						goto NEXT;
					} else if( C[p][q] == A[i+p][j+q] && C[p][q] != -1 ) {
						v1.push_back(make_pair(i+p+1,j+q+1));
					}
				}
			}

			v0.push_back(v1.front());

		NEXT:;

			flg = true;			
		}
	}

	if( v0.empty() ) {
		return make_pair(100,100);
	} else {
		sort(v0.begin(), v0.end());
		return v0.front();
	}
}

void rot90()
{
	for( int i = 0; i < m; i++ ) {
		for( int j = 0; j < m; j++ ) {
			C[m-j-1][i] = B[i][j];
		}		
	}

	for( int i = 0; i < m; i++ ) {
		for( int j = 0; j < m; j++ ) {
			B[i][j] = C[i][j];
		}		
	}	
}

int main(int argc, char* argv[])
{
	while(1) {

		cin >> n >> m;

		if( n == 0 && m == 0 )
			break;
			
		for( int i = 0; i < n; i++ ) {
			for( int j = 0; j < n; j++ ) {
				cin >> A[i][j];
			}
		}

		for( int i = 0; i < m; i++ ) {
			for( int j = 0; j < m; j++ ) {
				cin >> B[i][j];
			}
		}

		vector<pair<int,int>> v;

		auto p1 = search();
		if( p1.first != 100 && p1.second != 100 ) {		
			v.push_back(p1);
		}

		rot90();
		auto p2 = search();
		if( p2.first != 100 && p2.second != 100 ) {				
			v.push_back(p2);
		}

		rot90();
		auto p3 = search();
		if( p3.first != 100 && p3.second != 100 ) {						
			v.push_back(p3);
		}

		rot90();
		auto p0 = search();
		if( p0.first != 100 && p0.second != 100 ) {								
			v.push_back(p0);
		}

		if( v.empty() ) {
			cout << "NA" << endl;			
		} else {
			sort(v.begin(), v.begin());			
			cout << v[0].first << " " << v[0].second << endl;
		}
	}

    return 0;
}
