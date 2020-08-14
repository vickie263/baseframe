#ifndef MESH_H
#define MESH_H


#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <opengl/shader.h>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

struct Vertex {
    // position
    glm::vec3 Position;
    // normal
    glm::vec3 Normal;
    // texCoords
    glm::vec2 TexCoords;
    // tangent
    glm::vec3 Tangent;
    // bitangent
    glm::vec3 Bitangent;
};

struct Vertex_s {
    // position
    glm::vec3 Position;
    // texCoords
    glm::vec2 TexCoords;
};

struct Texture {
    unsigned int id;
    string type;
    string path;
};

class Mesh {
public:
    /*  Mesh Data  */
    vector<Vertex> vertices;
    vector<Vertex_s> vertices_s;
    vector<unsigned int> indices;
    vector<Texture> textures;
    unsigned int VAO;

    /*  Functions  */
    // constructor
    Mesh(vector<Vertex> vertices, vector<unsigned int> indices, vector<Texture> textures);
    Mesh(vector<Vertex_s> vertices, vector<unsigned int> indices, vector<Texture> textures);
    // render the mesh
    void Draw(Shader shader);

    // render the mesh
    void Draw();

private:
    /*  Render data  */
    unsigned int VBO, EBO;

    void setupMesh();
    void setupMesh_s();
};
#endif
