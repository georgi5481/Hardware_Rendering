//Corresponding header
#include "Renderer.h"

//C system includes

//C++ system includes

//3rd-party includes
#include <SDL_render.h>

//Own includes


/*SDL_CreateRenderer()  //pass SDL_RENDERER_ACCELERATED as flags
SDL_SetRenderDrawColor()
SDL_DestroyRenderer()
SDL_RendererClear()
SDL_RenderCopy()
SDL_RenderPresent()*/




int32_t Renderer::init(SDL_Window * window){
	/*giving the SDL_CreateRenderer function:
	 * 1 the window(pointer) where rendering is displayed,
	 * 2 setting -1 for using default driver( DiretX in this case)
	 * 3 A flag for using the hardware acceleration instead of CPU.*/
	SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

	return EXIT_SUCCESS;
}

void Renderer::deinit(){

}

void Renderer::clearScreen(){

}

void Renderer::finishFrame(){

}

void Renderer::renderTexture(SDL_Texture* texture){

}




