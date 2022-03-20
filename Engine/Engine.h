#ifndef ENGINE_ENGINE_H_
#define ENGINE_ENGINE_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

#include "sdl_utils/MonitorWindow.h"
#include "sdl_utils/InputEvent.h"

//Forward Declaration


enum Images{
	UP, DOWN, LEFT, RIGHT, ALL_KEYS, COUNT
};


class Engine {
public:
	int32_t init();
	void deinit();
	void start();

private:
	void mainLoop();
	void drawFrame();
	bool processFrame();
	void handleEvent();

	void limitFPS(int64_t elapsedTimeMicroSeconds);

	int32_t loadResources();

	MonitorWindow _window;
	InputEvent _event;
	SDL_Surface* _screenSurface = nullptr;

	//game specific logic
	SDL_Surface* _currChosenImage = nullptr;
	SDL_Surface* _imageSurface[COUNT]{};
};

#endif /* ENGINE_ENGINE_H_ */
