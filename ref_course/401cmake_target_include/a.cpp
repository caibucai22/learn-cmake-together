#include <iostream>
void A()
{
#ifdef A_VAR
std::cout<<"In A "<<A_VAR<<std::endl;  
#endif
}
