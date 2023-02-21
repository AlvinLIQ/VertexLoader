#ifndef ANA_VERTICES_LOADER
#define ANA_VERTICES_LOADER

#include <vector>
#include <sys/types.h>
#include <cstdint>

#ifdef _WIN32
#define SSCANF sscanf_s
#else
#define SSCANF sscanf
#endif
typedef struct
{
    float position[3];
    float color[3];
} Vertex_T;
typedef Vertex_T* Vertex;
typedef uint32_t Index_T;
typedef struct
{
    Vertex vertices;
    int vertexCount;

    std::vector<Index_T> indices;
}IndexedVertex;

void GetVertexCount(const char* str, size_t sLen, int *pCount);
void LoadVerticesFromStr(const char *str, size_t sLen, Vertex *pVertices, int *pVertexCount);
void LoadIndexFromStr(const char *str, size_t sLen, std::vector<Index_T> &indices);
void LoadIndexedVerticesFromStr(const char *str, IndexedVertex *pIndexedVertices);
template<typename T>
size_t StrToNum(T *num, const char *str, size_t sLen = -1);
void FreeVerticesMemory(void **pVertices);

#endif