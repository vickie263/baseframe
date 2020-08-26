#pragma once

#include <Baseframe.h>
#include <Textures.h>

class triangle : Baseframe
{
public:
	triangle();
	~triangle();
	Mesh *pmesh;
	Shader *ptriangleshader;
	void draw();
	virtual void update();


private:
	
};

