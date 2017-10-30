// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

// For filestream

#include <fstream>

void outputStr(std::string inputText, const std::string fname)
{
// Output the transliterated text
// Output to file if file defined, if not output to screen

    if (fname.empty()) {
      std::cout << inputText << std::endl;
    }

    else{
      std::ofstream out_file {fname, std::ios::app};

      if (out_file.good())
      {
	  	out_file << inputText; //<< std::endl;
      }
      std::cout << "Output written to file!" << std::endl;
    }
}