#include <iostream>
#include "application.h"
#include "board.h"
#include <string>

using namespace std;

int main() {
  application *myapp=new application;
  char op='a';
  //myapp -> test();
  while( op!='Q'){
  myapp -> run();
  cout <<"Play again.\n";
  cin>>op;
}
  delete myapp;

  return 0;
}