#include "Message.hpp"

#include<iostream>
#include<string>

std::ostream &Message::printObject(std::ostream &os){
  os <<"this is my very nice message: "<<std::endl;
  os<<message_;
  return os;
}