#include "main.h"

/**
* get_handler - Get the appropriate handler for the conversion specifier
* @sp: Format specifier character
* @idx: Integer index
* Return: Function pointer to the appropriate handler
*/
int (*get_handler(const char *sp, int idx))(va_list, char *, unsigned int)
{
	opt con[] = {
		{"c", char_handler},
		{"s", string_handler},
		{"d", integer_handler},
		{"i", integer_handler},
		{"b", binary_handler},
		{"%", per_handler},
		{NULL, NULL}
	};
	int i = 0, j = 0, f_idx;

	f_idx = idx;
	while (con[i].flag && sp)
	{
		if (sp[idx] == con[i].flag[j])
		{
			if (con[i].flag[j + 1] != 0)
			{
				idx++;
				j++;
			}
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			idx = f_idx;
		}
	}
	return (con[i].p);
}
