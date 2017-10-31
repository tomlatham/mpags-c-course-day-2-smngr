// Standard Library includes
#include <iostream>
#include <string>

// For filestream
#include <fstream>

void outputStr(const std::string& inputText, const std::string& fname)
{
// Output the transliterated text
// Output to file if file defined, if not output to screen

    if (fname.empty()) {
      std::cout << inputText << std::endl;
    }

    else{
      std::ofstream out_file {fname, std::ios::app};
      // TEL - A matter of taste whether this should overwrite or append.
      //       Probably should mention in the help message and README that it
      //       will append rather than overwrite since this might not be the
      //       expected behaviour.
      //       Of course one could have separate command-line options for
      //       overwriting or appending to file. We've not implemented this in
      //       our solution but it's a nice idea.

      if (out_file.good())
      {
	  	out_file << inputText << std::endl;
		std::cout << "Output written to file: " << fname << std::endl;
      } else {
		std::cerr << "[error] problem writing output to file: " << fname << std::endl;
      }
    }
}
