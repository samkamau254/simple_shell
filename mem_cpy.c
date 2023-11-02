#include "shell.h"

/**
 * _memcpy - copies n bytes from src to dest
 * @dest: bytes copied from src
 * @place: string to be copied
 * @k: no of bytes to be copied
 *
 * Return:string
 */

char *mem_cpy(char *dest, char *place, unsigned int k)
{
	unsigned int i;

	for (i = 0; i < k; i++)
	{
		dest[i] = place[i];
	}
	return (dest);
}

