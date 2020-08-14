#include "triangle.h"
#include <iostream>
// settings
const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;


triangle::triangle()
{
	createWindow(SCR_WIDTH, SCR_HEIGHT,"testbed_triangle");
	vector<Vertex_s> vertices;
	vector<unsigned int> indices;
	vector<Texture> textures;
	Vertex_s ver1, ver2, ver3;
	ver1.Position = glm::vec3(0.5,0.5,0.0);
	ver1.TexCoords = glm::vec2(1.0,1.0);
	vertices.push_back(ver1);
	ver2.Position = glm::vec3(0.5,-0.5, 0.0);
	ver2.TexCoords = glm::vec2(1.0, 0.0);
	vertices.push_back(ver2);
	ver3.Position = glm::vec3(-0.5, -0.5, 0.0);
	ver3.TexCoords = glm::vec2(0.0, 0.0);
	vertices.push_back(ver3);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	pmesh = &(Mesh(vertices, indices, textures));
	ptriangleshader = &Shader("triangle.vs", "triangle.fs");
}

triangle::~triangle()
{
}

void triangle::draw()
{
	run();
}

void triangle::update()
{
	drawMesh(pmesh, *ptriangleshader);
}

