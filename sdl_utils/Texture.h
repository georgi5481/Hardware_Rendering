#ifndef SDL_UTILS_TEXTURE_H_
#define SDL_UTILS_TEXTURE_H_

//C system includes

//C++ system includes
#include<cstdint>
#include<string>

//3rd-party includes

//Own includes

//Forward Declaration
struct SDL_Surface;
struct SDL_Texture;
struct SDL_Renderer;

class Texture {
public:
	Texture() = delete;
	 ~Texture();

	 static int32_t createSurfaceFromFile(const std::string& filePath, SDL_Surface*& outSurface);	//returning int32_t as an error message.
	 static int32_t createTextureFromFile(const std::string& filePath, SDL_Texture*& outTexture);

	 static int32_t createTextureFromSurface(SDL_Surface*& InOutSurface, SDL_Texture*& outTexture);


	 static void freeSurface(SDL_Surface*& outSurface);
	 static void freeTexture(SDL_Texture*& outTexture);

	 static void setRenderer(SDL_Renderer* renderer);
};

#endif /* SDL_UTILS_TEXTURE_H_ */
