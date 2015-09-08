#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#ifdef _WIN32
#include <GL/glew.h>
#elif __APPLE__
#include <OpenGL/gl3.h>
#endif

// Texture Loading class that uses the SDL_Image 2.0 plugin to load in textures and pass them to the 
// GPU, Should support BMP, GIF, JPEG, LBM, PCX, PNG, PNM, TGA, TIFF, WEBP, XCF, XPM, XV. Have tested
// PNG, BMP and JPEG
class TextureLoader
{

public:
	GLuint loadTexture(const char *fname); // pass in the file path of the texture and it'll return the texture ID

private:

};

#endif