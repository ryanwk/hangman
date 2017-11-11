#include <iostream>
#include <fstream>
#include "print.h"
#include <string>

using namespace std;

string grab_rand_string ();
string populate_array (string array[], int number);

int main () {

    string word_array[5];
    // populates word_array with new words on every call
    populate_array(word_array, 5);
    // prints array values
    for (int i = 0; i < 5; i++){
      cout << "array[" << i << "] = " << word_array[i] << endl;
    }

  // prints body part according to value passed to function
  // print_body_parts(2);
}

string grab_rand_string () {
  // creates stream and connects to dictionary
  ifstream infile;
  // opens dictionary
  infile.open("dictionary.txt");
  // check for error
  if (infile.fail()) {
    cerr << "error opening file" << endl;
    exit(1);
  };
  // limit to the range of words in dict.
  int limit = 10000;
  // initialize line var for return
  string line;
  int numOfLines = 0;
  int a = rand() % limit;
  // grabs a random line from the dictionary and save to variable line
  while(getline(infile, line))
  {
      ++numOfLines;

      if(numOfLines == a)
      {
          return line;
      }
  }
  return line;
}
string populate_array (string array[], int number) {
  // runs grab_rand_string to populate the array with random words from dictionary
  string end = "end";
  for (int i = 0; i < number; i++){
    array[i] = grab_rand_string();
  }
  return end;
}
