//Corresponding header
#include "EngineConfigLoader.h"
//C system includes

//C++ system includes
#include<cstdint>

//3rd-party includes
#include "sdl_utils/config/MonitorWindowCfg.h"

//Own includes

namespace{
constexpr auto WINDOW_WIDTH = 640;
constexpr auto WINDOW_HEIGHT = 480;
constexpr auto WINDOW_NAME = "Hardware_Redering";
}
static void populateMonitorConfig(MonitorWindowCfg& cfg){
	cfg.windowName = WINDOW_NAME;
	cfg.windowWidth = WINDOW_WIDTH;
	cfg.windowHeight = WINDOW_HEIGHT;
	cfg.windowFlags = WINDOW_SHOWN;
}


EngineConfig EngineConfigLoader::loadConfig(){
	EngineConfig cfg;

	populateMonitorConfig(cfg.windowCfg);

	return cfg;
}
