#ifndef GAME_GAME_H_
#define GAME_GAME_H_

//C system includes

//C++ system includes
#include <cstdint>
#include <vector>

//3rd-party includes

//Own includes
#include "Game/config/GameCfg.h"

//Forward Declaration
struct SDL_Surface;
struct InputEvent;



class Game {
public:

	int32_t init(const GameCfg& cfg);
	void deinit();
	void draw(std::vector<SDL_Surface*>& outImages);
	void handleEvent(const InputEvent& e);

private:


	int32_t loadResources(const std::unordered_map<Images, std::string>& res);

	//game specific logic
	SDL_Surface* _currChosenImage = nullptr;	//the image we are presenting atm
	SDL_Surface* _imageSurfaces[COUNT]{};		//an array of our Surfaces loaded basically in the heap




};

#endif /* GAME_GAME_H_ */
