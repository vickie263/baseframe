#pragma once

#include <Baseframe.h>

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

