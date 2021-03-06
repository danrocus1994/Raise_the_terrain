#include "libs_eng.h"
/**
 *init_camara - init camara object
 *Return: camara pointer
 */
camara *init_camara()
{
	camara *cam = malloc(sizeof(camara));
	transform *ctr = malloc(sizeof(transform));
	vert_t *c_target = malloc(sizeof(vert_t)), *c_up = malloc(sizeof(vert_t));
	vert_t *c_center = malloc(sizeof(vert_t));
	vert_t *c_rotation = malloc(sizeof(vert_t));
	vert_t *c_translation = malloc(sizeof(vert_t));

	c_center->x = 0;
	c_center->y = 0;
	c_center->z = 0;
	c_up->x = 0;
	c_up->y = 2;
	c_up->z = 0;
	c_target->x = 0;
	c_target->y = 0;
	c_target->z = 0;
	c_rotation->x = 0;
	c_rotation->y = 0;
	c_rotation->z = 0;
	c_translation->x = 0;
	c_translation->y = -100;
	c_translation->z = 0;
	cam->target = c_target;
	cam->up = c_up;
	cam->center = c_center;
	cam->zoom =  1.4;
	ctr->rotation = c_rotation;
	ctr->translation = c_translation;
	cam->transform = ctr;
	return (cam);
}
/**
 *init_viewport - init camara object
 *@cam: the camera
 *Return: camara pointer
 */
viewport *init_viewport(camara *cam)
{
	viewport *viewp = malloc(sizeof(viewport));

	viewp->width = width;
	viewp->height = height;
	viewp->pos = malloc(sizeof(vert_t));
	viewp->pos->x = 0;
	viewp->pos->y = 0;
	viewp->pos->z = cam->center->z + 40;
	viewp->up = malloc(sizeof(vert_t));
	viewp->up->x = 0;
	viewp->up->y = -150;
	viewp->up->z = cam->center->z + 40;
	return (viewp);
}
/**
 *init_engine - init camara object
 *Return: scene
 */
scene *init_engine()
{
	camara *cam = init_camara();
	viewport *viewp = init_viewport(cam);
	mesh *obj;
	char *file = malloc(100);
	vert_t *obj_trans = malloc(sizeof(vert_t));
	vert_t *obj_rotat = malloc(sizeof(vert_t));
	scene *scen = malloc(sizeof(scene));
	transform *tr = malloc(sizeof(transform));

	strcpy(file, "objects/");
	strcat(file, filename);
	obj = readfile(file);
	obj_trans->x = 0;
	obj_trans->y = 0;
	obj_trans->z = 0;
	obj_rotat->x = 0;
	obj_rotat->y = 0;
	obj_rotat->z = (M_PI * 180) / 180;
	tr->translation = obj_trans;
	tr->rotation = obj_rotat;
	obj->transform = tr;
	obj->scala = 0.48;
	obj->origin = set_center_origin(&(obj->vertx));
	scen->obj = obj;
	scen->camara = cam;
	scen->viewp = viewp;
	return (scen);
}
