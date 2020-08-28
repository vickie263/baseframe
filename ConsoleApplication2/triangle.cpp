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
	Vertex_s ver1, ver2, ver3,ver4;
	Texture tex1;
	ver1.Position = glm::vec3(0.5,0.5,0.0);
	ver1.TexCoords = glm::vec2(1.0,1.0);
	vertices.push_back(ver1);
	ver2.Position = glm::vec3(0.5,-0.5, 0.0);
	ver2.TexCoords = glm::vec2(1.0, 0.0);
	vertices.push_back(ver2);
	ver3.Position = glm::vec3(-0.5, -0.5, 0.0);
	ver3.TexCoords = glm::vec2(0.0, 0.0);
	vertices.push_back(ver3);
	ver4.Position = glm::vec3(-0.5, 0.5, 0.0);
	ver4.TexCoords = glm::vec2(0.0,1.0);
	vertices.push_back(ver4);
	indices.push_back(0);
	indices.push_back(1);
	indices.push_back(2);
	indices.push_back(2);
	indices.push_back(3);
	indices.push_back(0);
	Textures *ptex = new Textures();
	Texture2DParameter params1;
	params1.name = ptex->TEXTURE_WRAP_S;
	params1.iparam = ptex->REPEAT;
	ptex->texture2Dparameters.push_back(params1);
	Texture2DParameter params2;
	params2.name = ptex->TEXTURE_WRAP_T;
	params2.iparam = ptex->REPEAT;
	ptex->texture2Dparameters.push_back(params2);
	Texture2DParameter params3;
	params3.name = ptex->TEXTURE_MIN_FILTER;
	params3.iparam = ptex->LINEAR;
	ptex->texture2Dparameters.push_back(params3);
	Texture2DParameter params4;
	params4.name = ptex->TEXTURE_MAG_FILTER;
	params4.iparam = ptex->LINEAR;
	ptex->texture2Dparameters.push_back(params4);

	ptex->genTexture("F:/OL/baseframe/ConsoleApplication2/textures/1075.jpg");
	tex1.id = ptex->ID;
	tex1.type = "texture_normal";
	textures.push_back(tex1);
	pmesh = new Mesh(vertices, indices, textures);
	ptriangleshader = new Shader("triangle.vs", "triangle.fs");
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

