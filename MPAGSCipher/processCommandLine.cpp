// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// For std::isalpha and std::isupper
#include <cctype>

bool processCommandLine(
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested,
  bool& keyDefined, 
  std::string& inputFile,
  std::string& outputFile,
  bool& encrypt,
  size_t& key,
  bool& verbose)
{
  /* processCommandLine reads command line arguments and returns
  Boolean and Version flags, and input/output filename strings

  bool helpRequested: returns 'true' if --help or -h is parsed
  bool versionRequested: returns true if -v is parsed
  string inputFile: returns input filename if -i is parsed
  string outputFile: returns output filename if -o is parsed

  */

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {args.size()};

  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  
  for (size_type i {1}; i < nCmdLineArgs; ++i) {

    if (args[i] == "-h" || args[i] == "--help") {
      helpRequested = true;
    }
    else if (args[i] == "--version") {
      versionRequested = true;
    }
    else if (args[i] == "-i") {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return 1;
        }
      else {
        // Got filename, so assign value and advance past it
        inputFile = args[i+1];
        ++i;
        }
    }
    else if (args[i] == "-o") {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return 1;
      }
      else {
        // Got filename, so assign value and advance past it
        outputFile = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-encrypt" || args[i] == "-e") {
      // Default of cipher is to encrypt
      encrypt = true;
    }
    else if (args[i] == "-decrypt" || args[i] == "-d") {
      // If decrypt flag is found then switch default state
      encrypt = false;
    }
    else if (args[i] == "-k" || args[i] == "key"){
      // Handle key file option
      // Next element is key unless -k or key is last argument
        if (i == nCmdLineArgs-1) {
        std::cerr << "[error] -k requires a key argument" << std::endl;
        // exit main with non-zero return to indicate failure
        return 1;
        }

      // Need to implement error check to confirm that key is an integer
      
        bool key_is_valid{true};
        std::string key_arg = args[i+1];

        for (size_t n = 0; n < key_arg.length();n++)
        {
          if(!isdigit( key_arg[n] )) // If a character in the key is non-numeric, then raise a flag and produce an error
          {
             key_is_valid = false;
          }
        }
        
        if (key_is_valid)
        {
        // Got key, so assign value
        std::string key_str{args[i+1]};
        std::stringstream sstream(key_str);
        sstream >> key;
        keyDefined = true;
        ++i;
        }
        else
        {
        std::cout << "[error] key is not a number" << std::endl;
        return 1;
        }
      }

    else if (args[i] == "-v" || args[i] == "-verbose")
    {
      verbose = true;
      ++i;
    }
           
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return 1;
    }
  }
  return 0;
}