#include "Headers/VertexLoader.h"
#include <cstdlib>
#include <cstring>
#include <cstdio>

#ifdef _WIN32
#define SSCANF sscanf_s
#else
#define SSCANF sscanf
#endif

void GetVertexCount(const char* str, size_t sLen, int *pCount)
{
    if (sLen == -1)
        sLen = strlen(str);
    
    *pCount = 0;

    for (size_t i = 0; i < sLen; i++)
    {
        if (str[i] == '\n')
            ++*pCount;
    }
}

void LoadVerticesFromStr(const char *str, Vertex *pVertices, int *pVertexCount)
{
    size_t sLen = strlen(str);
    GetVertexCount(str, sLen, pVertexCount);
    if (*pVertexCount <= 0)
        return;

    *pVertices = (Vertex)malloc(*pVertexCount * sizeof(Vertex_T));
    for (int i = 0, j = 0; i < *pVertexCount; i++)
    {
        SSCANF(str + j, "(%f,%f,%f), (%f,%f,%f)\n", 
            &(*pVertices)[i].position[0],&(*pVertices)[i].position[1],&(*pVertices)[i].position[2], 
            &(*pVertices)[i].color[0],&(*pVertices)[i].color[1],&(*pVertices)[i].color[2]);
        while(str[j++] != '\n');
    }
}

void FreeVerticesMemory(Vertex *pVertices)
{
    if (pVertices && *pVertices)
    {
        free(*pVertices);
        *pVertices = NULL;
    }
}
#ifdef TEST_VERTICES
int main()
{
    const char vertices[] = "(1.0, 1.0, 1.0), (2.1, 2.2, 2.3)\n(1.0, 1.1, 1.2), (2.1, 2.2, 2.3f)\n";
    Vertex v;
    int vertexCount;
    LoadVerticesFromStr(vertices, &v, &vertexCount);
    for (int i = 0; i < vertexCount; i++)
    {
        printf("%f,%f,%f,%f,%f,%f\n", v[i].position[0], v[i].position[1], v[i].position[2], v[i].color[0], v[i].color[1], v[i].color[2]);
    }
    FreeVerticesMemory(&v);
    return 0;
}
#endif
