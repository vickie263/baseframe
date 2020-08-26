#pragma once
#include <string>
#include <vector>

using namespace std;

struct Texture2DParameter {
	unsigned int name;
	int iparam = -1;
	float fparam = 0;
	float* pfparam = nullptr;
	int* piparam = nullptr;
};

class Textures
{
public:
	unsigned int ID;
	unsigned int TEXTURE_MAG_FILTER, TEXTURE_MIN_FILTER, TEXTURE_WRAP_S, TEXTURE_WRAP_T;
	unsigned int REPEAT, MIRRORED_REPEAT, CLAMP_TO_EDGE, CLAMP_TO_BORDER;
	unsigned int NEAREST, LINEAR, NEAREST_MIPMAP_NEAREST, LINEAR_MIPMAP_NEAREST, 
						 NEAREST_MIPMAP_LINEAR, LINEAR_MIPMAP_LINEAR;
	vector<Texture2DParameter> texture2Dparameters;
	Textures();
	~Textures();

	unsigned int genTexture(string path);

};

