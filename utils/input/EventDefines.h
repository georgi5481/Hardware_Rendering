#ifndef UTILS_INPUT_EVENTDEFINES_H_
#define UTILS_INPUT_EVENTDEFINES_H_

//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes

//Own includes

//Forward Declaration


/* The enum EventDataType is included in orer not to include the whole SDL_Event.h
 * Not all events are listed here. You can extend it at any point of time.
 */
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

	/*Gesture events*/
	DOLLAR_GESTURE = 2048,		//SDL_DOLARGESTURE
	DOLLAR_RECORD = 2049,		//SDL_DOLLARRECORD
	MULTI_GESTURE = 2050,		//SDL_MULTIGESTURE

	QUIT = 256,					//SDL_QUIT 			/*User requests quit*/
	WINDOW = 512,				//SDL_WINDOWEVENT	/*Window state change (move the window positon)*/
	TEXT_INPUT = 771,			//SDL_TEXTINPUT		/*Keyboard text input */
	OS_LANGUAGE_CHANGED = 772,	//SDL_KEYMAPCHANGED

	AUDIO_DEVICE_ADDED = 4352	//SDL_AUDIODEVICEADDED

};
}/*namespace EventType*/


namespace Keyboard{
enum Key {
	KEY_UNKNOWN =0	//SDL_UNKNOWN

	KEY_BACKSPACE =8,	//SDLK_BACKSPACE
	KEY_ENTER = 13, 	//SDLK_RETURN
	KEY_ESCAPE = 27, 	//SDL_ESCAPE
	KEY_SPACE = 32,		//SDL_SPACE
	KEY_PERIOD = 46, 	//SDL_PERIOD
	KEY_SLASH = 47,		//SDL_SLASH
	KEY_0 = 48,		//SDLK_0
	KEY_1 = 49,		//SDLK_1
	KEY_2 = 50,		//SDLK_2
	KEY_3 = 51,		//SDLK_3
	KEY_4 = 52,		//SDLK_4
	KEY_5 = 53,		//SDLK_5


};
}

#endif /* UTILS_INPUT_EVENTDEFINES_H_ */
