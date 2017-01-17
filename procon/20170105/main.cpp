#include <climits>
#include <iostream>
#include <map>
#include <queue>

using namespace std;

int c, n, m, s, d;

typedef pair<int, int> node; // (コスト, 節点)
multimap<int,pair<int,int>> l; // (始点, (終点、距離))
int v[502]; // 節点のコスト
int prv[502]; // 前方節点

void diijkstra()
{
	// 初期化
	for( int i = 0; i < m; i++ ) {
		v[i] = INT_MAX;
	}
	v[s] = 0;

	priority_queue< node, std::vector<node>, std::greater<node> > q;
	q.push( node(0,s) );
		
	// 本体
	while( !q.empty() ) {

		node n = q.top(); q.pop();
		int p0 = n.second;
		int c0 = n.first;

		if( v[p0] < c0 ) continue;

		auto r = l.equal_range(p0);
		for( auto i = r.first; i != r.second; ++i ) {

			int p1 = i->second.first;
			int c1 = v[p0] + i->second.second;

			if( c1 < v[p1] ) {
				v[p1] = c1;
				prv[p1] = p0;
			}
				
			q.push( node(v[p1], p1) );
		}
	}
}

int main(int argc, char* argv[])
{
	while( cin >> c ) {

		cin >> n >> m >> s >> d;

		int p0, p1, f;

		for( int i = 0; i < m; i++ ) {
			cin >> p0 >> p1 >> f;
			l.insert(make_pair(p0, make_pair(p1, f)));
			l.insert(make_pair(p1, make_pair(p0, f)));
		}

		diijkstra();
	}

    return 0;
}

