//Coresponding header
#include "Texture.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_surface.h>
#include <SDL_image.h>
#include <SDL_render.h>
//Own includes

//Forward Declaration


struct SDL_Surface;


int32_t Texture::createSurfaceFromFile(const std::string& filePath,
		 	 	 	 	 	 	 	 SDL_Surface*& outSurface){

	outSurface = IMG_Load(filePath.c_str()); //load the file with the path

	if(outSurface == nullptr){	//check if loading the file went well
		std::cerr << "SDL_LoadBMP failed. Reason: " << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}
	return EXIT_SUCCESS;
}

void Texture::freeSurface(SDL_Surface*& outSurface){
	if(outSurface != nullptr){
		SDL_FreeSurface(outSurface);
		outSurface = nullptr;
	}
}

static void Texture::freeTexture(SDL_Texture*& outTexture){
	if(outTexture != nullptr){
		SDL_DestroyTexture(outTexture);
		outTexture = nullptr;
	}
}


int32_t Texture::createTextureFromSurface(SDL_Surface*& InOutSurface, SDL_Texture*& outTexture){

}

static void Texture::freeTexture(SDL_Texture*& outTexture){

}

