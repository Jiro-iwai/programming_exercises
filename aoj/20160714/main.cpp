#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/tokenizer.hpp>
#include <boost/lexical_cast.hpp>

int search(int h, int w, int H, int W, std::vector<std::vector<std::pair<int,bool> > >& matrix )
{
	if( h == -1 || h == H || w == -1 || w == H )
	 	return 0;
	
	if( matrix[h][w].second )
		return 0;

	if( matrix[h][w].first == '#' )
		return 0;

	matrix[h][w].second	= true;	

	std::cout << h << "," << w << std::endl;
	
	int c = 1;

	// if( -1 < h-1 && matrix[h-1][w].first == '.' )
	// 	c += search( h-1, w, H, W, matrix );
	
	// if( h+1 < H && matrix[h+1][w].first == '.' ) 
	// 	c += search( h+1, w, H, W, matrix );

    // if( -1 < w-1 && matrix[h][w-1].first == '.' )
	// 	c += search( h, w-1, H, W, matrix );

	// if( w+1 < W && matrix[h][w+1].first == '.' )
	// 	c += search( h, w+1, H, W, matrix );

	c += search( h-1, w, H, W, matrix );
	c += search( h+1, w, H, W, matrix );
	c += search( h, w-1, H, W, matrix );
	c += search( h, w+1, H, W, matrix );	

	return c;
}

int solve(std::vector<std::string>& lines, int l)
{
	typedef boost::char_separator<char> char_separator;
    typedef boost::tokenizer<char_separator> tokenizer;
    char_separator sep(" ", "", boost::keep_empty_tokens);o
    tokenizer tokens(lines[l], sep);

    tokenizer::iterator tok_iter = tokens.begin();

	// std::cout << *tok_iter	<< std::endl;
	int W = boost::lexical_cast<int>(*tok_iter);

	++tok_iter;

	// std::cout << *tok_iter	<< std::endl;	
	int H = boost::lexical_cast<int>(*tok_iter);

	if( H == 0 && W == 0 ) {
		exit(0);
	}

	std::vector<std::vector<std::pair<int,bool> > > matrix;

	int sh,sw;

	l++;
	for( int h = l; h < H+l; h++ ) {
		std::vector<std::pair<int,bool> > row;
		for( int w = 0; w < W; w++ ) {
			int c = lines[h][w];
			// std::cout << (char)c;
			row.push_back(std::make_pair(c,false));
			if( c == '@' ) {
				sh = h-l;
				sw = w;
			}
			
		}
		// std::cout << std::endl;		
		matrix.push_back(row);
	}

	std::cout << search( sh, sw, H, W, matrix ) << std::endl;

	return H;
}

int main(int argc, char* argv[])
{
	std::ifstream ifs;
	ifs.open(argv[1]);

	std::vector<std::string> lines;

	std::string line;	
	while( std::getline(ifs, line) ) {
		lines.push_back(line);
		line.clear();
	}

	int H = 0;
	while(1) {
		H += solve(lines, H) + 1;
	}

	return 0;
}
