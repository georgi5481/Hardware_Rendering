//Corresponding header
#include "InputEvent.h"

//C system includes

//C++ system includes
#include<iostream>
#include<cstring>

//3rd-party includes
#include<SDL_events.h>

//Own includes

//Forward Declaration


int32_t InputEvent::init(){
	_sdlEvent = new SDL_Event();
	memset(_sdlEvent, 0, sizeof(SDL_Event));
	if(_sdlEvent == nullptr){

		std::cerr << "Bad aloc for SDL_Event()" << std::endl;
	}

	return EXIT_SUCCESS;
}

void InputEvent::deiit(){

	if(_sdlEvent != nullptr){
		delete _sdlEvent;
		_sdlEvent = nullptr;
	}
}

bool InputEvent::pollEvent(){
return true;

}

bool InputEvent::checkForExitRequiest()const{

return true;
}
