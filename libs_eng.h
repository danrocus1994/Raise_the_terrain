#ifndef LIBS_ENG
#define LIBS_ENG

#include <X11/Xlib.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_timer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int width;
int height;
char *filename;
/**
 *struct x_renderer - the x rennder object
 *@dis: the display
 *@window: the window
 *@screen: the screen
 */
typedef struct x_renderer
{
	Display *dis;
	Window window;
	int screen;
} xrend_t;
/**
 *struct Vertx - the x rennder object
 *@x: the display
 *@y: the window
 *@z: the screen
 *@next: the pointer ot next
 */
typedef struct Vertx
{
	float x;
	float y;
	float z;
	struct Vertx *next;
} vert_t;

/**
 *struct Transformation - the x rennder object
 *@translation: the display
 *@rotation: the window
 */
typedef struct Transformation
{
	vert_t *translation;
	vert_t *rotation;
} transform;
/**
 *struct Camara - the x rennder object
 *@target: the display
 *@up: the window
 *@center: the screen
 *@zoom:  the zoom
 *@transform: the pointer ot next
 */
typedef struct Camara
{
	vert_t *target;
	vert_t *up;
	vert_t *center;
	float zoom;
	struct Transformation *transform;
} camara;
/**
 *struct Viewport - the x rennder object
 *@width: the display
 *@height: the window
 *@pos: the screen
 *@up:  the zoom
 *@transform: the pointer ot next
 */
typedef struct Viewport
{
	int width;
	int height;
	vert_t *pos;
	vert_t *up;
	struct Transformation *transform;
} viewport;
/**
 *struct Face - the x rennder object
 *@a: the display
 *@b: the window
 *@next: the pointer ot next
 */
typedef struct Face
{
	int a;
	int b;
	struct Face *next;
} face;
/**
 *struct Polygon - the x rennder object
 *@faces: the display
 *@next: the pointer ot next
 */
typedef struct Polygon
{
	struct Face *faces;
	struct Polygon *next;
} polygon;

/**
 *struct Mesh - the x rennder object
 *@vertx: the display
 *@polys: the display
 *@origin: the display
 *@scala: the window
 *@transform: the pointer ot next
 */
typedef struct Mesh
{
	vert_t *vertx;
	polygon *polys;
	vert_t *origin;
	float scala;
	struct Transformation *transform;
} mesh;
/**
 *struct Scene - the x rennder object
 *@obj: the display
 *@camara: the display
 *@viewp: the display
 */
typedef struct Scene
{
	struct Mesh *obj;
	struct Camara *camara;
	struct Viewport *viewp;
} scene;

scene *scn;
mesh *readfile(char *name);
void print_vertex(const vert_t *vertices);
void print_polygons(polygon **polygons);
void print_faces(face **faces);
vert_t *project(vert_t *vertice, camara *cam, viewport *viewp);
vert_t *draw_vertex(mesh **obj, camara *cam, viewport *view);
vert_t *transf_vertex(mesh **obj, vert_t **new_vertlist);
vert_t sum_vec(vert_t vec1, vert_t vec2);
vert_t sus_vec(vert_t vec1, vert_t vec2);
vert_t mul_vec(vert_t vec1, vert_t vec2);
vert_t div_vec(vert_t vec1, vert_t vec2);
vert_t get_target_origin(mesh *obj);
vert_t *set_center_origin(vert_t **vertx);
void rend(SDL_Renderer *renderer, scene *scn);
void scanline(polygon **polys, vert_t **list, SDL_Renderer *renderer);
void print_v(vert_t *ver, int line);
int key_pressed(int code, scene *scn);
scene *init_engine();
char *_tostring(int n);
vert_t rotate(vert_t vertex, mesh *obj);
vert_t scalar(vert_t vert, float scale);
vert_t translate(vert_t vert, vert_t trans);
vert_t *add_vertex_node(vert_t **newlist, vert_t vertex);
int list_size(vert_t **vertx);
#endif /* LIBS_ENG */
