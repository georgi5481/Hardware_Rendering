//Corresponding header
#include "Renderer.h"

//C system includes

//C++ system includes
#include<iostream>

//3rd-party includes
#include <SDL_render.h>

//Own includes
#include"sdl_utils/Texture.h"



int32_t Renderer::init(SDL_Window * window){
	/*giving the SDL_CreateRenderer function:
	 * 1 the window(pointer) where rendering is displayed,
	 * 2 setting -1 for using default driver(DiretX in this case)
	 * 3 A flag for using the hardware acceleration instead of CPU.*/

	constexpr auto unspecifiedDriverId = -1;
	_sdlRenderer = SDL_CreateRenderer(window, unspecifiedDriverId, SDL_RENDERER_ACCELERATED);
	if(_sdlRenderer == nullptr)
	{
		std::cerr << "SDL_CreateRenderer failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;
	}

	//SDL_SetRenderDrawColor will place a color on every pixel on the buffer we are clearing
	if(EXIT_SUCCESS != SDL_SetRenderDrawColor(_sdlRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE)){
		std::cerr << "SDL_SetRenderDrawColor failed. Reason:" << SDL_GetError() << std::endl;
		return EXIT_FAILURE;

	}


	Texture::setRenderer(_sdlRenderer);//will basically set another pointer for the renderer outside the class

	return EXIT_SUCCESS;
}

void Renderer::deinit(){
	if(_sdlRenderer){
	SDL_DestroyRenderer(_sdlRenderer);
	_sdlRenderer = nullptr;
	}
}


void Renderer::clearScreen(){
	if(EXIT_SUCCESS != SDL_RenderClear(_sdlRenderer)){
		std::cerr << "SDL_RenderClear() failed. Reason:" << SDL_GetError() << std::endl;
	}

}

void Renderer::finishFrame(){
	SDL_RenderPresent(_sdlRenderer);	//will swap the pointers
}

void Renderer::renderTexture(SDL_Texture* texture){//SDL_Texture is a primitive we are drawing
	/*first argument - The renderer which should copy parts of a texture
	 * second - The source texture
	 * third - NULL for the entire texture to be displayed
	 * fourth - NULL for the entire rendering target*/
	SDL_RenderCopy(_sdlRenderer, texture, nullptr, nullptr);
}




