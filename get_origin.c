#include "libs_eng.h"

/**
 *get_target_origin- get obj origin
 *@obj: a mesh
 *Return: a vert
 */

vert_t get_target_origin(mesh *obj)
{
	(void) obj;
	return ((vert_t) {0, 0, 0, NULL});
}
