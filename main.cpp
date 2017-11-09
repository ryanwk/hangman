#include <iostream>
#include <fstream>
#include "print.h"
using namespace std;

void grabStrings (int x);

int main () {
  print_body_parts(2);
  // grabStrings(5);

}

void grabStrings (int x) {
  ifstream infile;
  infile.open("dictionary.txt")
  
}
