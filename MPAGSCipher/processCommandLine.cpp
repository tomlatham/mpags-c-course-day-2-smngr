// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

bool processCommandLine(
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested, 
  std::string& inputFile,
  std::string& outputFile )
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
    else {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return 1;
    }
  }
  return 0;
}