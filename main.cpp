#include <iostream>
#include <fstream>
#include "print.h"
#include <string>

using namespace std;

string grab_rand_string ();
string populate_array (string array[]);
char hide_all_chars(char array[], int length);
// void letter_check (int length, char array[], char letter);

int main () {

    string rand_words[5];
    // populates rand_words with new words on every call
    populate_array(rand_words);

    // assigns first index of rand_words to variable
    string starting_word = rand_words[0];

    // gets length of word
    int starting_word_length = starting_word.length();
    // initializes an array of characters as long as the starting word
    char string_to_char_array[starting_word_length];
    // converts string to an array of chars
    strcpy(string_to_char_array, starting_word.c_str());
    // prints word
    cout << "Round 1 word is " << string_to_char_array << endl << endl;
    // transform array of chars into blank array w/ spaces
    hide_all_chars(string_to_char_array, starting_word_length);
    // prints word with letters hidden
    for (int i = 0; i < starting_word_length; i++){
      cout << string_to_char_array[i] << " ";
    }
    cout << endl << endl << "Try to fill in the blanks by guessing a letter" << endl;

    // user inputs letter to guess
    char letter_guess;
    cin >> letter_guess;
    // letter_check(starting_word_length, string_to_char_array, letter_guess);
    
    // for (int i = 0; i < starting_word_length; i++){
    //   if (string_to_char_array[i] == letter_guess){
    //       string_to_char_array[i] = letter_guess;
    //   }
    // }
    cout << endl << "after guessing a letter" << endl;





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
string populate_array (string array[]) {
  // runs grab_rand_string to populate the array with random words from dictionary
  string end = "end";
  for (int i = 0; i < 5; i++){
    array[i] = grab_rand_string();
  }
  return end;
}

char hide_all_chars(char array[], int length) {
  for (int i = 0; i < length; i++){
    array[i] = '-';
  }
  return 0;
}

// void letter_check (int length, char array[], char letter) {
//   // check if letter is in array
// switch (/* expression */) {
//   case /* value */:
// }
//   for (int i = 0; i < length; i++)
//
//         array[i] = letter;
//     }
// }


// // prints array values
// for (int i = 0; i < starting_word_length; i++){
//   cout << "array[" << i << "] = " << string_to_char_array[i] << endl;
// }

// int game_status;
// cout << "input 1 to start" << endl;
// cin >> game_status;
//
// if (game_status == 1) {
//   play_word();
// }
