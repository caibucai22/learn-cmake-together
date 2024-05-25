#include <iostream>
void A();
void B(){
  A();
#ifdef A_VAR
  std::cout<<"In B "<<A_VAR<<std::endl;  
#endif
}

