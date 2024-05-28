#pragma once

#include <Hudi/Core/Layer.h>

class GameLayer : public Hudi::Layer {
public:
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	virtual void OnUpdate(float dt) override;
	virtual void OnGUIRender() override;
	virtual void OnEvent(Hudi::Event& e) override;

private:

};

