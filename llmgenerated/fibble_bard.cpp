#include <iostream>
#include <string>

using namespace std;

int main() {
  // Generate a random five-letter word.
  string word = generate_random_word();

  // Create a clue for the word.
  string clue = generate_clue(word);

  // Start the game loop.
  int guesses = 0;
  while (guesses < 8) {
    // Get the player's guess.
    string guess;
    cin >> guess;

    // Check the guess.
    bool correct = check_guess(guess, word);

    // Update the clue.
    clue = update_clue(clue, guess, correct);

    // Print the clue.
    cout << clue << endl;

    // Increment the number of guesses.
    guesses++;

    // If the player has guessed the correct word, break out of the loop.
    if (correct) {
      break;
    }
  }

  // If the player has run out of guesses, print a message and end the game.
  if (guesses == 8) {
    cout << "You lose!" << endl;
  } else {
    cout << "You win!" << endl;
  }

  return 0;
}

// Generate a random five-letter word.
string generate_random_word() {
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  string word;
  for (int i = 0; i < 5; i++) {
    word += alphabet[rand() % 26];
  }
  return word;
}

// Generate a clue for the word.
string generate_clue(string word) {
  // One of the letters in the word is a lie.
  int lie_index = rand() % 5;

  // Create a clue with the lie.
  string clue = word;
  clue[lie_index] = '_';

  return clue;
}

// Check the player's guess.
bool check_guess(string guess, string word) {
  // Check if the guess is the correct word.
  if (guess == word) {
    return true;
  }

  // Check if the guess has any of the correct letters in the correct position.
  for (int i = 0; i < 5; i++) {
    if (guess[i] == word[i]) {
      return true;
    }
  }

  return false;
}

// Update the clue based on the player's guess.
string update_clue(string clue, string guess, bool correct) {
  // If the guess is correct, remove the lie from the clue.
  if (correct) {
    clue[lie_index] = guess[lie_index];
  }

  // Otherwise, add the guess to the clue.
  else {
    clue += guess;
  }

  return clue;
}
