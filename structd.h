#ifndef STRUCTD_H
#define STRUCTD_H

#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>



typedef struct
{
	char symbol;
	bool letter;
	bool digit;
	bool punct;
	bool space;
} ItGood;

ItGood Check(char symb);
bool ValidSymbol(char symb);
bool Cleaner(const char * file_name, const char	* output);

#endif