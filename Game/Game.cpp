//Corresponding header
#include "Game.h"
//C system includes

//C++ system includes
#include<cstdint>
#include<array>
#include<iostream>
//3rd-party includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Own components includes
#include "sdl_utils/Texture.h"
#include "sdl_utils/InputEvent.h"


int32_t Game::init(){
	if (EXIT_SUCCESS != loadResources()){	//load the resources in the window
			std::cerr << "loadResources() failed. Reason: " << SDL_GetError() << std::endl;
			return EXIT_FAILURE;
	}

	_currChosenImage = _imageSurfaces[ALL_KEYS];


	return EXIT_SUCCESS;
}

void Game::deinite(){

}
void Game::draw(){

}
void Game::handleEvent(const InputEvent& e){

}


int32_t Game::loadResources(){
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
