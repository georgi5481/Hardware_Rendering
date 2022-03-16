#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

#include "sdl_utils/SDLLoader.h"
#include "sdl_utils/InputEvent.h"

//Forward Declaration

class Engine {
public:
	int32_t init();
	void deinit;
	void start();


private:
	MonitorWindow _window;
	InputEvent _event;
	SDL_Surface* screenSurface = nullptr;
};

#endif /* ENGINE_ENGINE_H_ */
