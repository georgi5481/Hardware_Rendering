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
	KEY_UNKNOWN =0,	//SDL_UNKNOWN

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
	KEY_6 = 54,		//SDLK_6
	KEY_7 = 55,		//SDLK_7
	KEY_8 = 56,		//SDLK_8
	KEY_9 = 57,		//SDLK_9
	KEY_COLON = 58,			//SDLK_COLON
	KEY_SEMICOLON = 59,		//SDLK_SEMICOLON
	KEY_LEFT_BRACKET = 91,	//SDLK_LEFTBRACKET
	KEY_RIGHT_BRACKED = 93,	//SDLK_RIGHTBRACKET
	KEY_TILDA = 96,			//SDLK_BACKQUOTE

	KEY_A = 'a',		//SDLK_a
	KEY_B = 'b',		//SDLK_b
	KEY_C = 'c',		//SDLK_c
	KEY_D = 'd',		//SDLK_d
	KEY_E = 'e',		//SDLK_e
	KEY_F = 'f',		//SDLK_e
	KEY_G = 'g',		//SDLK_e
	KEY_H = 'h',		//SDLK_h
	KEY_I = 'i',		//SDLK_i
	KEY_G = 'g',		//SDLK_g
	KEY_K = 'k',		//SDLK_k
	KEY_L = 'l',		//SDLK_l
	KEY_M = 'm',		//SDLK_m
	KEY_N = 'n',		//SDLK_n
	KEY_O = 'o',		//SDLK_o
	KEY_P = 'p',		//SDLK_p
	KEY_Q = 'q',		//SDLK_q
	KEY_R = 'r',		//SDLK_r
	KEY_S = 's',		//SDLK_s
	KEY_T = 't',		//SDLK_t
	KEY_U = 'u',		//SDLK_u
	KEY_V = 'v',		//SDLK_v
	KEY_W = 'w',		//SDLK_w
	KEY_X = 'x',		//SDLK_x
	KEY_Y = 'y',		//SDLK_y
	KEY_Z = 'z',		//SDLK_z

	KEY_DELETE = 127,		//SDLK_DELETE

	KEY_F1 = 1073741882,	//SDLK_F1
	KEY_F2 = 1073741883,	//SDLK_F2
	KEY_F3 = 1073741884,	//SDLK_F3
	KEY_F4 = 1073741885,	//SDLK_F4
	KEY_F5 = 1073741886,	//SDLK_F5
	KEY_F6 = 1073741887,	//SDLK_F6
	KEY_F7 = 1073741888,	//SDLK_F7
	KEY_F8 = 1073741889,	//SDLK_F8
	KEY_F9 = 1073741890,	//SDLK_F9
	KEY_F10 = 1073741891,	//SDLK_F10
	KEY_F11 = 1073741892,	//SDLK_F11
	KEY_F12 = 1073741893,	//SDLK_F12
	KEY_PRINTSCREEN = 1073741894,	//SDLK_PRINTSCREEN
	KEY_SCROLLLOCK = 1073741895,	//SDLK_SCROLLLOCK
	KEY_PAUSE = 1073741896,			//SDLK_PAUSE
	KEY_INSERT = 1073741897,		//SDLK_INSERT

	KEY_HOME = 		1073741898,		//SDLK_PRINTSCREEN
	KEY_PAGEUP = 	1073741899,	//SDLK_SCROLLLOCK
	KEY_END= 		1073741901,		//SDLK_PAUSE
	KEY_PAGEDOWN = 	1073741902,	//SDLK_INSERT
	KEY_RIGHT= 		1073741903,		//SDLK_PRINTSCREEN
	KEY_LEFT= 		1073741904,		//SDLK_SCROLLLOCK
	KEY_DOWN= 		1073741905,		//SDLK_PAUSE
	KEY_UP= 		1073741906,			//SDLK_INSERT

};
}

#endif /* UTILS_INPUT_EVENTDEFINES_H_ */
