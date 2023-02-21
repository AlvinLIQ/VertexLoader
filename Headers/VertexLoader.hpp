#ifndef ANA_VERTICES_LOADER
#define ANA_VERTICES_LOADER

#include <vector>
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
    Index_T indexType;
    std::vector<Index_T> indices;
}IndexedVertex;

void GetVertexCount(const char* str, std::size_t sLen, int *pCount);
void LoadVerticesFromStr(const char *str, std::size_t sLen, Vertex *pVertices, int *pVertexCount);
void LoadIndexFromStr(const char *str, std::size_t sLen, std::vector<Index_T> &indices, char *pIndexType);
void LoadIndexedVerticesFromStr(const char *str, IndexedVertex *pIndexedVertices);
void FreeVerticesMemory(void **pVertices);

#endif