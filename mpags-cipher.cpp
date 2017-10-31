// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// For filestream

#include <fstream>

// Project headers

#include "transformChar.hpp"
#include "processCommandLine.hpp"
#include "outputStr.hpp"
#include "runCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  bool keyDefined {false};
  std::string inputFile {""};
  std::string outputFile {""};
  size_t key {0};
  bool encrypt {true};
  bool verbose {false};

  // Process the command line

  bool cmdlineValid { processCommandLine(cmdLineArgs, helpRequested, versionRequested, keyDefined, inputFile, outputFile, encrypt, key, verbose) };
  if ( ! cmdlineValid ) {
    std::cerr << "Problem parsing command line arguments, exiting" << std::endl;
    return 1;
  }

  //std::cout << "Key is: " << key;

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n"
      << "  -k KEY           Caesar cipher will use this numeric key\n"
      << "  -e|-encrypt      Default cipher behaviour; will encrypt the input\n"
      << "  -d|-decrypt      Used to decrypt a ciphered message with the key specified\n"
      << "  -v|-verbose      Adds verbosity for debugging [not fully implemented]\n\n";

    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 0;
  }

  if (!keyDefined) {
    std::cout << "[error] key is invalid" << std::endl;
    return 1;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};
  std::string outputText {""};

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (inputFile.empty())
  {
    // Loop over each character from user input
    // (until Return then CTRL-D (EOF) pressed)
    while(std::cin >> inputChar)
    {
      inputText += transformChar( inputChar );
      //std::cout << "test is " << inputText << std::endl;
      // outputStr(inputText, outputFile);
    }
  }

  else
  {
    std::ifstream in_file {inputFile};    
    if ( ! in_file.good() ) {
      std::cerr << "[error] problem reading from input file: " << inputFile << std::endl;
      return 1;
    }
    while (in_file >> inputChar)
    {
    inputText += transformChar ( inputChar );
    //std::cout << "text is " << inputText << std::endl;
    // outputStr(inputText, outputFile);
    }
    //std::string eof_str{"\nEnd of File\n"}; // A string to print in the output to indicate that the input file is finished
    // outputStr(eof_str, outputFile);
  }

  std::string cipher_output{""};

  if (verbose)
  {  std::cout << "String input to cipher: " << inputText << std::endl;
  }

  cipher_output = runCaesarCipher(inputText,key,encrypt);

  std::cout << "Cipher output: " << std::endl;
  
  outputStr(cipher_output, outputFile); // If defined, function saves the cipher output to file. 

  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}
