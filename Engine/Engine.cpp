//Corresponding header
#include "Engine/Engine.h"

//C system includes

//C++ system includes
#include<cstdint>
#include<iostream>
#include<array>

//3rd-party includes
#include<SDL_surface.h>
#include<thread>

//Own includes
#include "utils/thread/ThreadUtils.h"
#include "sdl_utils/Texture.h"
#include "utils/Time/Time.h"


int32_t Engine::init(){

	MonitorWindowCfg cfg;

	//using SDL_WINDOW_SHOWN as flag
	cfg.windowName = "SDL_Runtime";
	cfg.windowWidth = 640;
	cfg.windowHeight = 480;
	cfg.windowFlags = WINDOW_SHOWN;


	if (EXIT_SUCCESS != _window.init(cfg)){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	if (EXIT_SUCCESS != loadResources()){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	_currChosenImage = _imageSurfaces[ALL_KEYS];

	if (EXIT_SUCCESS != _event.init()){	//load the resources in the window
			std::cerr << "InputEvent failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

return EXIT_SUCCESS;
}


int32_t Engine::loadResources(){
	const std::array<std::string, COUNT> filePaths ={
			"../resources/up.png",
			"../resources/down.png",
			"../resources/left.png",
			"../resources/right.png",
			"../resources/press_keys.png"
	};

	for(int32_t i = 0; i < COUNT; ++i){
		if(EXIT_SUCCESS != Texture::createSurfaceFromFile(filePaths[i], _imageSurfaces[i])){
			std::cerr << "createSurfaceFromFile failed for file : " << filePaths[i] << std::endl;
		return EXIT_FAILURE;
		}

	}

	return EXIT_SUCCESS;
}


void Engine::deinit(){
	for(int32_t i = 0; i < COUNT; ++i){
		Texture::freeSurface(_imageSurfaces[i]);	//have to free the surface otherwise we have a memory leak
	}
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
	_screenSurface = _window.getWindowSurface();
	SDL_BlitSurface(_currChosenImage, nullptr, _screenSurface, nullptr);
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
	const int64_t maxFrames = 30;
	const int64_t microSecondsInASecond = 1000000;
	const int64_t microSecondsPerFrame = microSecondsInASecond / maxFrames;
	const int64_t sleepDurationMicroSeconds = microSecondsPerFrame - elapsedTimeMicroSeconds;

	if(sleepDurationMicroSeconds > 0){
	ThreadUtils::sleepFor(sleepDurationMicroSeconds);
	}
}



void Engine::handleEvent(){
	if(TouchEvent::KEYBOARD_RELEASE == _event.type){	//sets to zero if we stoped pressing the key
		_currChosenImage = _imageSurfaces[ALL_KEYS];
	}

	if(TouchEvent::KEYBOARD_PRESS != _event.type){	//check if our event is a keyboard event in the first place
		return;
	}

		switch(_event.key){
		case Keyboard::KEY_UP:
		_currChosenImage = _imageSurfaces[UP];
		break;

		case Keyboard::KEY_DOWN:
		_currChosenImage = _imageSurfaces[DOWN];
		break;

		case Keyboard::KEY_LEFT:
		_currChosenImage = _imageSurfaces[LEFT];
		break;

		case Keyboard::KEY_RIGHT:
		_currChosenImage = _imageSurfaces[RIGHT];
		break;

		default:
			break;
		}
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





