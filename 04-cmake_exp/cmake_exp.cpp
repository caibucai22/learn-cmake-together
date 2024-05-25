
#include <iostream>
using namespace std;

int main()
{
  cout << "cmake exp" << endl;
#ifdef TEST1
  cout << TEST1 << endl;
#endif
  return 0;
}