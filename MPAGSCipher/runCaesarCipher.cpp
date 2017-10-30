// Standard Library includes
#include <iostream>
#include <string>
#include <vector>

std::string runCaesarCipher( const std::string inputText, const size_t key, const bool encrypt )
{

// Initialize the output string

std::string cipherText{""};

// Create the alphabet container and output string
std::vector<char> alphabet{'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};

// Loop over the input text

//std::string b{inputText};

for (size_t i = 0; i < inputText.size(); i++)
{
	int shift {static_cast<int>(key)};
	char cipher_in = inputText[i];
	int j{0};

	// Loop through alphabet until character position in alphabet is found

	while (cipher_in!=alphabet[j])
	{
		j++;
	}

	// std::cout << "Character " << cipher_in << " is letter " << j+1 << " of the alphabet" << std::endl;

	int new_index{0};

	if(encrypt) // Encrypt mode
	{
		new_index = (j + shift)%26;
	}
	else // Decrypt mode
	{
		new_index = (j - shift)%26;
	}

	if (new_index<0)
		{new_index = new_index+26;} // Ensures that the index is positive, allows for loop around alphabet

	char cipher_out = alphabet[new_index];

	//std::cout << "Cipher out is " << cipher_out << std::endl;
	
	cipherText += cipher_out;
}

return cipherText;

// For each character find the corresponding position in the alphabet

// Apply the shift (+ve or – ve depending on encrypt/decrypt)

// to the position, handling correctly potential wrap -around

// Determine the new character and add it to the output string

// Finally (after the loop), return the output string
}