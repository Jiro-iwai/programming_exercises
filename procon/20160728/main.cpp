#include <iostream>
#include <string>
#include <algorithm>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>
#include <vector>

using namespace std;
using namespace boost;

pair<int, int> solve(int sh, int sw, int H, int W, vector<vector<pair<int,bool>>>& mat, int f, int m, int o, char d)
{
	cout << "(" << sh << "," << sw << ") ";
	
	if( sw < 0 || sw == W || o <= 0 ) {
		cout << "NA" << endl;
		return std::move(make_pair(-1, o));
	}

	if( sh == H ) {
		cout << "OK" << endl;		
		return std::move(make_pair(f, o));
	}

	// if( mat[sh][sw].second ) {
	// 	return std::move(make_pair(-1, o));		
	// }

	mat[sh][sw].second = true;
	int v = mat[sh][sw].first;

	if( v < 0 ) {

		f += v;
		if( f < 0 ) {
			cout << "NA" << endl;			
			return std::move(make_pair(-1, o));
		}

	} else {

		o = min(m, o + v);
	}

	int mf = 0;
	int mo = 0;
	pair<int,int> p;

	if( d != 'W' ) {
		p = solve(sh, sw-1, H, W, mat, f, m, o-1, 'E');
	}
	if( mf < p.first ){
		mf = p.first;
		mo = p.second;
	}

	if( d != 'E' ) {
		p = solve(sh, sw+1, H, W, mat, f, m, o-1, 'W');
	}
	if( mf < p.first ){
		mf = p.first;
		mo = p.second;		
	}		

	p = solve(sh+1, sw, H, W, mat, f, m, o-1, 'N');
	if( mf < p.first ){
		mf = p.first;
		mo = p.second;
	}			

	return std::move(make_pair(mf, mo));
}

int main(int argc, char* argv[])
{
	using sprtr = char_separator<char>;
	using tknzr = tokenizer<sprtr>;
	sprtr sep(" ", "", keep_empty_tokens);

	int f, mf, mo;

	string line;
	while( getline(cin, line) ) {

		tknzr tkns(line, sep);
		auto it = tkns.begin();
		auto W = lexical_cast<int>(*it++);
		auto H = lexical_cast<int>(*it);

		if( H == 0 && W == 0 ) {
			break;
		}

		int m, o;
		{
			getline(cin, line);
			tknzr tkns(line, sep);
			auto it = tkns.begin();
			f = lexical_cast<int>(*it++);
			m = lexical_cast<int>(*it++);
			o = lexical_cast<int>(*it);
		}
		
		vector<vector<pair<int,bool>>> mat;		
		{
			for( int i = 0; i < H; i++ ) {
				vector<pair<int,bool>> row;
				getline(cin, line);
				tknzr tkns(line, sep);
				for( auto xs : tkns ) {
					cout << xs << " ";
					row.push_back(make_pair(lexical_cast<int>(xs),false));
				}
				cout << endl;
				mat.push_back(row);
			}
		}

		mf = 0;
		mo = 0;			
		pair<int,int> p = make_pair(INT_MAX, -1);
		for( int sw = 0; sw < W; sw++ ) {
			p = solve(0, sw, H, W, mat, f, m, o, 'N');
			if( mf < p.first ){
				mf = p.first;
				mo = p.second; 					
			}
		}

		if( 0 < f - mf && 0 < mo ) {
			cout << f - mf << endl;
		} else {
			cout << "NA" << endl;		
		}
	}

    return 0;
}
