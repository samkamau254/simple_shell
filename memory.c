#include "shell.h"

/**
 * free_p - frees a pointer
 * @ptr: pointer to be freed
 */
void free_p(void **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

/**
 * re_alloc - returns pointer to a new allocated block
 * @ptr: Pointer to be reallocated
 * @prev: Old size
 * @n_size: New size
 *
 * Return: Pointer to void
 */
void *re_alloc(void *ptr, unsigned int prev, unsigned int n_size)
{
	void *new_ptr;
	unsigned int copy_size;

	if (prev == n_size)
		return (ptr);
	if (n_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(n_size);
	if (new_ptr == NULL)
		return (NULL);
	if (ptr == NULL)
		return (new_ptr);
	copy_size = prev < n_size ? prev : n_size;
	mem_cpy(new_ptr, ptr, copy_size);
	free(ptr);
	return (new_ptr);
}
