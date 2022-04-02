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
			std::cerr << "loadResources() failed. Reason: " << std::endl;
			return EXIT_FAILURE;
	}

	_currChosenImage = _imageSurfaces[PRESS_KEYS];


	return EXIT_SUCCESS;
}

void Game::deinit(){
	for(int32_t i = 0; i < COUNT; ++i){
		Texture::freeSurface(_imageSurfaces[i]);	//have to free the surface otherwise we have a memory leak
	}
}

void Game::draw(std::vector<SDL_Surface*>& outImages){
	outImages.push_back(_currChosenImage);
}

void Game::handleEvent(const InputEvent& e){
	if(TouchEvent::KEYBOARD_RELEASE == e.type){	//sets to zero if we stoped pressing the key
		_currChosenImage = _imageSurfaces[PRESS_KEYS];
	}

	if(TouchEvent::KEYBOARD_PRESS != e.type){	//check if our event is a keyboard event in the first place
		return;
	}

		switch(e.key){
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


int32_t Game::loadResources(){
	const std::array<std::string, COUNT> filePaths ={
			"../resources/up.png",
			"../resources/down.png",
			"../resources/left.png",
			"../resources/right.png",
			"../resources/press_keys.png",
			"../resources/layer_2.png"
	};

	for(int32_t i = 0; i < COUNT; ++i){
		if(EXIT_SUCCESS != Texture::createSurfaceFromFile(filePaths[i], _imageSurfaces[i])){
			std::cerr << "createSurfaceFromFile failed for file : " << filePaths[i] << std::endl;
		return EXIT_FAILURE;
		}

	}

	return EXIT_SUCCESS;
}
