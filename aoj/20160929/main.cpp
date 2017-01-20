#include <iostream>
#include <vector>
#include <map>

using namespace std;

map<string, int> value;
map<string, vector<string> > recip;


int rennkinn(string& obj)
{
	int sum = value[obj];
	auto it = recip.find(obj);
	
	if( it != recip.end() ) {

		vector<string>& parts = it->second;

		int tmp = 0;
		for( auto& p : parts ) {
			tmp += rennkinn(p);
		}

		if( tmp < sum )
			sum = tmp;		
	}

	return sum;
}

int main(int argc, char* argv[])
{
	while(1) {

		int np; cin >> np;
		if( np == 0 )
			break;
	
		for( int i = 0; i < np; i++ ) {
			string p; cin >> p;
			int v; cin >> v;
			value[move(p)] = move(v);
		}

		int nr;
		cin >> nr;
		for( int i = 0; i < nr; i++ ) {
			string p; cin >> p;
			int np; cin >> np;
			vector<string> ps;
			for( int j = 0; j < np; j++ ) {
				string p; cin >> p;
				ps.push_back(move(p));
			}
			recip[move(p)] = move(ps);
		}

		string obj; cin >> obj;
		cout << rennkinn(obj) << endl;
		
		value.clear();
		recip.clear();
	}

    return 0;
}
