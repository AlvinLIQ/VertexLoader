#ifndef ANA_VERTICES_LOADER
#define ANA_VERTICES_LOADER

typedef struct
{
    float position[3];
    float color[3];
} Vertex_T;
typedef Vertex_T* Vertex;

void LoadVerticesFromStr(const char *str, Vertex *pVertices, int *pVertexCount);
void FreeVerticesMemory(Vertex *pVertices);

#endif