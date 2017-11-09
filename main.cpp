#include <iostream>
#include <fstream>
#include "print.h"
#include <string>

using namespace std;

string grab_rand_string ();
// string change (char& old_array[]);

int main () {

    string old_array[5];
    cout << "Displaying each index of array once changed: " << endl;
    for (int i = 0; i <= 5; i++){
      string line;
      line = grab_rand_string();
      old_array[i] = line;
      cout << "&old_array[" << i << "] = " << old_array[i] << endl;
    }
    // cout << old_array <<endl;

  // initialize random seed
 //  srand (time(NULL));
 //
 // // initialize and generate random number between 1 and 5
 //  int play_random_word = rand() % 5 + 1;
  // print the location of an array based on value passed to the function;

  // grab_rand_strings(play_random_word);

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

// char change (char & old_array) {
//
//
// }
