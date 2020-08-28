#include "Textures.h"
#include <glad/glad.h>
#include <opengl/filesystem.h>
#include <stb_image.h>
#include <iostream>


Textures::Textures()
{
    TEXTURE_MAG_FILTER = GL_TEXTURE_MAG_FILTER ;
    TEXTURE_MIN_FILTER = GL_TEXTURE_MIN_FILTER; 
    TEXTURE_WRAP_S = GL_TEXTURE_WRAP_S;  
    TEXTURE_WRAP_T = GL_TEXTURE_WRAP_T;

    REPEAT = GL_REPEAT;
    MIRRORED_REPEAT = GL_MIRRORED_REPEAT;
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE;
    CLAMP_TO_BORDER = GL_CLAMP_TO_BORDER;

    NEAREST = GL_NEAREST;
    LINEAR = GL_LINEAR;
    NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST;
    LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST;
    NEAREST_MIPMAP_LINEAR = GL_NEAREST_MIPMAP_LINEAR;
    LINEAR_MIPMAP_LINEAR = GL_LINEAR_MIPMAP_LINEAR;
}

Textures::~Textures()
{
}

unsigned int Textures::genTexture(string path)
{
    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);
    if (texture2Dparameters.size() > 0)
    {
        for (unsigned int i = 0; i < texture2Dparameters.size(); i++)
        {
            if(texture2Dparameters[i].iparam != -1)
                glTexParameteri(GL_TEXTURE_2D, texture2Dparameters[i].name, texture2Dparameters[i].iparam);
            else if(texture2Dparameters[i].pfparam)
                glTexParameterfv(GL_TEXTURE_2D, texture2Dparameters[i].name, texture2Dparameters[i].pfparam);
            else if (texture2Dparameters[i].fparam != 0)
                glTexParameterf(GL_TEXTURE_2D, texture2Dparameters[i].name, texture2Dparameters[i].fparam);
            else if (texture2Dparameters[i].piparam)
                glTexParameteriv(GL_TEXTURE_2D, texture2Dparameters[i].name, texture2Dparameters[i].piparam);
        }
    }
    // load image, create texture and generate mipmaps
    int width, height, nrChannels;
    stbi_set_flip_vertically_on_load(true); // tell stb_image.h to flip loaded texture's on the y-axis.
    // The FileSystem::getPath(...) is part of the GitHub repository so we can find files on any IDE/platform; replace it with your own image path.
    unsigned char* data = stbi_load(FileSystem::getPath(path).c_str(), &width, &height, &nrChannels, 0);
    string::size_type position1, position2, position3, position4;
    position1 = path.find(".png");
    position2 = path.find(".PNG");
    if (data)
    {   
        if (position1 != path.npos || position2 != path.npos)
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        else
            glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    stbi_image_free(data);
    return 0;
}


