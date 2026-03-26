#include <stdint.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "structd.h"


int main(int argc, char const *argv[])
{
	//src$ ./cleaner bad.txt good.txt
	if (argc == 3)
	{
		Cleaner(argv[1], argv[2]);
	}
	else
	{
		return 1;
	}
	return 0;
}