# mpags-cipher
A simple command line tool for encrypting/decrypting text using classical ciphers

# Building `mpags-cipher`
Compilation of `mpags-cipher` requires a  C++11 compatible compiler
(GCC 4.8 or better, Clang 3.4 or better are recommended) and `make`
on a UNIX operating system.
Windows platforms with Visual Studio 2015 or better are also expected to
work, but not tested.

To build from a clone of this repository, create a build folder and run
```
$ cmake <PATH_TO_SOURCE>
$ make

```

# Usage

The MPAGS cipher uses a classical Caeser cipher to encode or decipher text. An input text file may be supplied by using the flag

```
$ ./mpags-cipher -i [file] -k [key] [-e/-d]
```
where the key is a number provided by the user to encode or decode the message. The default behaviour of mpags-cipher is to encode the message however the flags -e and -d specify whether the message is to be encoded or decoded respectively.

If no input file is supplied, `mpags-cipher` will wait for user input
from the keyboard until RETURN followed by CTRL-D are pressed.

To ensure the input text can be used with the character sets known to
classical ciphers, it is transliterated using the following rules:

- Alphabetical characters are converted to uppercase
- Digits are translated to their English equivalent words (e.g. '0' -> "ZERO")
- All other characters (punctuation) are discarded

The results of this transliteration are output after CTRL-D.

Text output may be saved to file using the flag -o

```
$ ./mpags-cipher -i [file] -o [file2] -k [key]
```

To see an example, try running

```
$ ./mpags-cipher -i long.txt -o result.txt -k 121 -d
```


# Source Code Layout
Under this directory, the code and associated files are organised as
follows:

```
$ tree
.
└── MPAGS-Code
	├── CMakeLists.txt 					Contains build instructions for cmak
	├── LICENSE                         License, currently MIT
	├── long.txt.						A text file containing a message encoded with cipher key 121
	├── MPAGSCipher                     dir containing headers and function declarations
	│   ├── outputStr.cpp
	│   ├── outputStr.hpp
	│   ├── processCommandLine.cpp
	│   ├── processCommandLine.hpp
	│   ├── runCaesarCipher.cpp
	│   ├── runCaesarCipher.hpp
	│   ├── transformChar.cpp
	│   └── transformChar.hpp
	├── mpags-cipher.cpp 				Main CPP code
	└── README.md                       This readme file



2 directories, 12 files
```

# Copying
`mpags-cipher` is licensed under the terms of the MIT License. Please see
the file [`LICENSE`](LICENSE) for full details.
