#ifndef UTILS_INPUT_EVENTDEFINES_H_
#define UTILS_INPUT_EVENTDEFINES_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration

namespace EventType {
enum EventDataType{
	UNKNOWN = 0, //SDL_FIRSTEVENT,

	/*Keyboard events*/
	KEYBOARD_PRESS = 768,	//SDL_KEYDOWN		/*Key pressed*/
	KEYBOARD_RELEASE = 769,	//SDL_KEYUP			/*Key released*/
	OS_TEXTEDITING = 770,	//SDL_TESTEDITING	/*Keyboard text editing*/

		/*Mouse events*/
	MOUSE_MOTION = 1024,		//SDL_MOUSEMOTION 		/*Mouse moved*/
	MOUSE_PRESS = 1025,			//SDL_MOUSEBUTTONUP 	/*Mouse button pressed*/
	MOUSE_RELEASE = 1026,		//SDL_MOUSEBUTTONUP 	/*Mouse button released*/
	MOUSE_WHEEL_MOTION = 1027,	//SDL_MOUSEWHEEL 		/*Mouse wheel motion*/

	/*Touch events */
	FINGER_PRESS = 1792, 		//SDL_FINGERDOWN 	/* Finger pressed */
	FINGER_RELEASE = 1793,		//SDL_FINGERUP 		/* Finger released */
	FINGER_MOTION = 1794,		//SDL_FINGERMOTION 	/* Finger moved */
};
}


#endif /* UTILS_INPUT_EVENTDEFINES_H_ */
