#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

int main() {
  // Load the dictionary of words.
  vector<string> dictionary;
  ifstream dict_file("dictionary.txt");
  for (string word; getline(dict_file, word);) {
    dictionary.push_back(word);
  }

  // Generate a random word from the dictionary.
  string word = dictionary[rand() % dictionary.size()];

  // Start the game loop.
  int guesses = 0;
  while (guesses < 6) {
    // Get the player's guess.
    string guess;
    cin >> guess;

    // Check the guess.
    vector<char> correct_letters;
    vector<char> misplaced_letters;
    for (int i = 0; i < 5; i++) {
      if (guess[i] == word[i]) {
        correct_letters.push_back(guess[i]);
      } else if (word.find(guess[i]) != string::npos) {
        misplaced_letters.push_back(guess[i]);
      }
    }

    // Print the clues.
    cout << "Correct letters: ";
    for (char letter : correct_letters) {
      cout << letter;
    }
    cout << endl;
    cout << "Misplaced letters: ";
    for (char letter : misplaced_letters) {
      cout << letter;
    }
    cout << endl;

    // Increment the number of guesses.
    guesses++;

    // If the player has guessed the correct word, break out of the loop.
    if (correct_letters.size() == 5) {
      break;
    }
  }

  // If the player has run out of guesses, print a message and end the game.
  if (guesses == 6) {
    cout << "You lose!" << endl;
  } else {
    cout << "You win!" << endl;
  }

  return 0;
}