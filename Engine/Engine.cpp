//Corresponding header
#include "Engine/Engine.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>

//3rd-party includes
#include<SDL_surface.h>
#include<thread>

//Own includes
#include "Engine/config/EngineConfig.h"
#include "utils/thread/ThreadUtils.h"
#include "utils/Time/Time.h"
#include "Engine/EngineConfigLoader.h"

int32_t Engine::init(const EngineConfig& cfg){
	if (EXIT_SUCCESS != _window.init(cfg.windowCfg)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}


	if (EXIT_SUCCESS != _event.init()){	//load the resources in the window
			std::cerr << "InputEvent failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}


	if (EXIT_SUCCESS != _game.init(cfg.gameCfg)){	//load the resources in the window
			std::cerr << "_game.init() failed." << std::endl;
			return EXIT_FAILURE;
	}


return EXIT_SUCCESS;
}




void Engine::deinit(){
	_game.deinit();
	_window.deinit();
	_event.deinit();
}

void Engine::start(){
	mainLoop();

}

void Engine::mainLoop(){
	Time time;

while(true){
	time.getElapsed().toMicroseconds();

	const bool shouldExit = processFrame();

		if(shouldExit){
			break;
		}

		limitFPS(time.getElapsed().toMicroseconds());
	}
}

void Engine::drawFrame(){

	std::vector<SDL_Surface*> images;

	_game.draw(images);
	_screenSurface = _window.getWindowSurface();


	for(auto& image : images){
		SDL_BlitSurface(image, nullptr, _screenSurface, nullptr);

	}

		_window.updateWindowSurface();


}



bool Engine::processFrame(){
	while(_event.pollEvent()){
		if(_event.checkForExitRequiest()){
			return true;
		}

		handleEvent();
	}

	drawFrame();

	return false;
}


void Engine::limitFPS(int64_t elapsedTimeMicroSeconds){
	constexpr auto maxFrames = 30;
	constexpr auto microSecondsInASecond = 1000000;
	constexpr auto microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

	if(sleepDurationMicroSeconds > 0){
	ThreadUtils::sleepFor(sleepDurationMicroSeconds);
	}
}



void Engine::handleEvent(){
_game.handleEvent(_event);
}

/*
	while(true) {
		if(event.pollEvent()){
			if(event.type == TouchEvent::KEYBOARD_PRESS){
				std::cout << "pressed key: " << (char)event.key << std::endl;
			}
			else if(event.type == TouchEvent::KEYBOARD_RELEASE){
				std::cout << "released key: " << (char)event.key << std::endl;
			}
			else if(event.type == TouchEvent::TOUCH_PRESS){
				std::cout << "mouse button idx pressed: " << event.mouseButton << std::endl;
			}
			else if(event.type == TouchEvent::TOUCH_RELEASE){
				std::cout << "mouse button idx released: " << event.mouseButton << std::endl;
			}
			else {
				std::cout << "event position X(" << event.pos.x << ") Y (" << event.pos.y << ")" << std::endl;
			}
		}
	}*/





