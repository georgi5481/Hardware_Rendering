#ifndef GAME_GAME_H_
#define GAME_GAME_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes


//Forward Declaration
struct SDL_Surface;
struct InputEvent;



class Game {
public:

	int32_t init();
	void deinite();
	void draw();
	void handleEvent(const InputEvent& e);

private:
	enum Images{
		UP, DOWN, LEFT, RIGHT, ALL_KEYS, COUNT
	};

	int32_t loadResources();

	//game specific logic
	SDL_Surface* _currChosenImage = nullptr;	//the image we are presenting atm
	SDL_Surface* _imageSurfaces[COUNT]{};		//an array of our Surfaces loaded basically in the heap




};

#endif /* GAME_GAME_H_ */
