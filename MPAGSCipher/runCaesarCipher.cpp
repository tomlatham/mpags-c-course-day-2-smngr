// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher( const std::string& inputText, const size_t key, const bool encrypt )
{

// Initialize the output string

std::string cipherText{""};

// Create the alphabet container and output string
const std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
const size_t alphabetSize = alphabet.size();

// Loop over the input text

//std::string b{inputText};

// Truncate the key to lie within 0 - 25
const size_t shift {key % alphabetSize};

for ( const char& cipher_in : inputText )
{
	// Loop through alphabet until character position in alphabet is found
	size_t j{0};
	while (cipher_in!=alphabet[j])
	{
		j++;
	}

	// std::cout << "Character " << cipher_in << " is letter " << j+1 << " of the alphabet" << std::endl;

	// Apply the shift (+ve or – ve depending on encrypt/decrypt)
	// to the position, handling correctly potential wrap -around
	size_t new_index{0};

	if(encrypt) // Encrypt mode
	{
		new_index = (j + shift)%alphabetSize;
	}
	else // Decrypt mode
	{
		new_index = (j + alphabetSize - shift)%alphabetSize;
	}

	// Determine the new character and add it to the output string
	char cipher_out = alphabet[new_index];

	//std::cout << "Cipher out is " << cipher_out << std::endl;
	
	cipherText += cipher_out;
}

// Finally (after the loop), return the output string
return cipherText;

}
