#ifndef ANA_VERTICES_LOADER
#define ANA_VERTICES_LOADER

#include <sys/types.h>
typedef struct
{
    float position[3];
    float color[3];
} Vertex_T;
typedef Vertex_T* Vertex;
typedef u_int16_t Index_T;
typedef Index_T* Index;
typedef struct
{
    Vertex vertices;
    Index indices;
}AnA_Vertex;


void LoadVerticesFromStr(const char *str, Vertex *pVertices, int *pVertexCount);
void LoadIndexedVerticesFromStr(const char *str, AnA_Vertex *pVertices, int *pVertexCount);
void FreeVerticesMemory(void **pVertices);

#endif