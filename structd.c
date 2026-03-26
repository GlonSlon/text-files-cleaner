#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "structd.h"

ItGood Check(char symb)
{
	ItGood good;
	good.symbol = symb;
	good.letter = ((symb >= 'a' && symb <= 'z') || (symb >= 'A' && symb <= 'Z'));
	good.digit = (symb >= '0' && symb <= '9');
	good.space = (symb == ' ' || symb == '\t' || symb == '\n' || symb == '\r');

	const char * vpunct = "|,.-+=/*:%;!?{}[]()@<>&#`~\"'";
	good.punct = false;

	for (int i = 0; vpunct[i] != '\0'; i++)
	{
		if (symb == vpunct[i])
		{
			good.punct = true;
			break;
		}
	}
	return good;
}

bool ValidSymbol(char symb)
{
	ItGood good = Check(symb);
	return (good.letter || good.digit || good.punct || good.space);
}

bool Cleaner(const char * file_name, const char	* output)
{
	FILE* input = fopen(file_name, "r");
	if (input == NULL)
		return false;

	FILE * out = fopen(output, "w");
	if (out == NULL)
	{
		fclose(input);
		return false;
	}

	int ch;
	int next = EOF;

	while((ch = fgetc(input)) != EOF)
	{
		bool is_letter = ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
		if (ValidSymbol((char)ch))
		{
			if (is_letter)
			{
				fputc((char)ch, out);
			}
			else
			{
				if (next != EOF && (char)ch == (char)next)
				{
					continue;
				}
				fputc((char)ch, out);
				next = ch;
			}

		}
	}

	fclose(input);
	fclose(out);

	return true;
}