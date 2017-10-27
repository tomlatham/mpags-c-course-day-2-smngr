// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// Declare function

std::string transformChar(const char inputChar)
{

  /*
  
  Function transformChar takes a input characters and returns
  all alphanumeric characters as a string, with letters transliterated
  to uppercase and numbers as text. 

  */

  std::string inputText{""};

  // Uppercase alphabetic characters
  if (std::isalpha(inputChar)) {
    inputText += std::toupper(inputChar);
  }

  // Transliterate digits to English words
  switch (inputChar) {
    case '0':
      inputText += "ZERO";
      break;
    case '1':
      inputText += "ONE";
      break;
    case '2':
      inputText += "TWO";
      break;
    case '3':
      inputText += "THREE";
      break;
    case '4':
      inputText += "FOUR";
      break;
    case '5':
      inputText += "FIVE";
      break;
    case '6':
      inputText += "SIX";
      break;
    case '7':
      inputText += "SEVEN";
      break;
    case '8':
      inputText += "EIGHT";
      break;
    case '9':
      inputText += "NINE";
      break;
    }

  // If the character isn't alphabetic or numeric, DONT add it.
  // Our ciphers can only operate on alphabetic characters.

  return inputText;
}