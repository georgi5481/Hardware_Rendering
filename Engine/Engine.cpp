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
	if (EXIT_SUCCESS != _event.init()){	//load the resources in the window
			std::cerr << "InputEvent failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

return EXIT_SUCCESS;
}


int32_t Engine::loadResources(){
const std::array<std::string> filePaths[COUNT];

	const std::string filePath = "../resources/hello.png";	//get the path to the file we need

	if(EXIT_SUCCESS != Texture::createSurfaceFromFile(filePath, _image)){
		std::cerr << "createSurfaceFromFile failed for file : " << filePath << std::endl;
	return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}


void Engine::deinit(){
	Texture::freeSurface(_image);

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
	SDL_BlitSurface(_image, nullptr, _screenSurface, nullptr);
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
}
*/
