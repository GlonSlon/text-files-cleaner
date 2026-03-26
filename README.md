```markdown
# Text Cleaner

A simple C program that cleans text files by removing invalid characters and duplicates.

## Description

This program reads a text file and removes all characters that are not in the allowed set:
- Latin letters: `a-z`, `A-Z`
- Digits: `0-9`
- Punctuation marks: `.-+=/*:%;!?{}[]()"'`
- Whitespace characters: space, tab, newline, carriage return

Additionally, the program removes duplicate consecutive characters to prevent repetitions.

## Features

- Removes invalid characters (Russian letters, special symbols, etc.)
- Removes duplicate consecutive characters
- Preserves valid characters and whitespace
- Provides statistics about removed characters
- Simple command-line interface

## Requirements

- C compiler (gcc recommended)
- Standard C libraries

## Compilation

```bash
gcc -o text_cleaner main.c structd.c
```

## Usage

```bash
./text_cleaner <input_file> <output_file>
```

### Example

```bash
# Clean a dirty text file
./text_cleaner dirty.txt clean.txt

# Output will show statistics:
# Total characters: 150
# Removed characters: 45
# Saved characters: 105
```

## How It Works

1. Opens the input file for reading
2. Opens the output file for writing
3. Reads each character from the input file
4. Checks if the character is valid (letter, digit, punctuation, or whitespace)
5. Removes duplicate consecutive characters
6. Writes only valid, non-duplicate characters to the output file
7. Displays statistics about the cleaning process

## File Structure

```
├── structd.h      # Header file with function declarations
├── structd.c      # Implementation of cleaning functions
├── main.c         # Main program with command-line interface
└── README.md      # This file
```

## Functions

- `Check(char symb)` - Determines the type of a character
- `ValidSymbol(char symb)` - Checks if a character is valid
- `Cleaner(const char* input, const char* output)` - Main cleaning function

## Example Input and Output

### Input (dirty.txt):
```
Hello World! 123
Invalid: @#$%^&* русский текст
Email: test@example.com
Duplicate: aaabbbccc
```

### Output (clean.txt):
```
Hello World! 123
Invalid 
Email testexample.com
Duplicate abc
```

## What Gets Removed

The program removes:
- Russian letters and characters from other alphabets
- Special symbols: `@#$%^&*<>|~\``
- Duplicate consecutive characters (e.g., `aa` → `a`)
- Other characters not in the allowed set

## What Gets Preserved

The program preserves:
- Latin letters (A-Z, a-z)
- Digits (0-9)
- Allowed punctuation marks
- Spaces, tabs, newlines

