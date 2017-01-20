
#include <fstream>

int main()
{
  std::ofstream ofs( "test.txt" );

  ofs << "testmessage" << 123 << std::endl;
  ofs << "testmessage" << 123 << std::endl;
  ofs << "testmessage" << 123 << std::endl;
  ofs << "testmessage" << 124 << std::endl;
  ofs << "testmessage" << 125 << std::endl;    

  return 0;
}
