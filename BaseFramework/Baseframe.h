#pragma once
#include <opengl/shader.h>
#include <opengl/mesh.h>

class Baseframe
{
public:
	Baseframe();
	~Baseframe();

	

protected:
	int createWindow(int screen_w, int screen_h, const char* title);
	void drawMesh(Mesh *pmesh, Shader shader);
	void drawMesh2(Mesh *pmesh);

	void run();
	void destory();
	void processInput();

	virtual void update();
	virtual bool inputKey();

private:
	
};

