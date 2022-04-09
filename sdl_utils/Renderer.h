#ifndef SDL_UTILS_RENDERER_H_
#define SDL_UTILS_RENDERER_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration
struct SDL_Renderer;	//structure pointer comming from SDL
struct SDL_Texture;		//primitive that uploads the data from the CPU to the GPU
struct SDL_Window;


class Renderer {
	//forbid the copy/move constructors and assignment operators

	int32_t init(SDL_Window * window);
	void deinit();
	void clearScreen();
	void finishFrame();
	void renderTexture(SDL_Texture* texture);
private:
	SDL_Renderer *_sdlRenderer = nullptr;
};

#endif /* SDL_UTILS_RENDERER_H_ */
