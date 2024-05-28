#include <Hudi/Core/EntryPoint.h>
#include <Hudi.h>

#include <Hudi/Debug/debug.h>

#include "GameLayer.h"

class Wars : public Hudi::Application {
public:
	Wars()
		: Application(Hudi::WindowProps(
			"Wars", 
			WINDOWPOS_CENTERED, WINDOWPOS_CENTERED,
			1280, 720, 
			Hudi::WINDOW_OPENGL | Hudi::WINDOW_RESIZABLE | Hudi::WINDOW_ALLOW_HIGHDPI
		)) 
	{
		__db << "Starting Wars";
		PushLayer(new GameLayer());
	}
};


Hudi::Application* Hudi::CreateApplication() {
	return new Wars();
}