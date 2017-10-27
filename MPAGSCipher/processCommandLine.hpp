#ifndef MPAGSCIPHER_PROCESSCMDLINE_HPP
#define MPAGSCIPHER_PROCESSCMDLINE_HPP

#include <string>
#include <vector>

// Define transliteration function

bool processCommandLine(
  const std::vector<std::string>& args,
  bool& helpRequested,
  bool& versionRequested, 
  std::string& inputFile,
  std::string& outputFile );

#endif //