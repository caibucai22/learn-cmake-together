
#include <iostream>
using namespace std;

int main(int argc,char* argv[])
{
  if(argc <=1 ) // 没有传递参数
    return -1;
  cout<<argv[1]<<endl;
  return 0;
}
