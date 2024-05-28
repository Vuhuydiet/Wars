#include "GameLayer.h"

#include <Hudi.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace Hudi;

void GameLayer::OnAttach()
{
}

void GameLayer::OnDetach()
{
}

void GameLayer::OnUpdate(float dt)
{
	// set clear color to gray
	Hudi::RenderCommand::SetClearColor(169, 169, 169, 255);
	Hudi::RenderCommand::Clear();


	glm::mat4 projection = glm::ortho(-10.0f, 10.0f, -5.0f, 5.0f, -1.0f, 1.0f);
	Hudi::Renderer2D::BeginScene(projection);


	Hudi::Ref<Hudi::Texture2D> texture = Hudi::Texture2D::Create("assets/images/eggplant.png");
	static glm::vec3 pos{0.0f, 0.0f, 0.0f};
	static float v = 0.5;
	static glm::vec3 dir{ 0.0f, 0.0f, 0.0f };
	if (Input::IsKeyDown(Key::W))
		dir.y = 1.0f;
	if (Input::IsKeyDown(Key::S))
		dir.y = -1.0f;
	if (Input::IsKeyDown(Key::A))
		dir.x = -1.0f;
	if (Input::IsKeyDown(Key::D))
		dir.x = 1.0f;
	if (Input::IsKeyDown(Key::SPACE))
		v += 0.1 * dt;

	// when not pressing any key, stop moving
	if (!Input::IsKeyDown(Key::W) && !Input::IsKeyDown(Key::S))
		dir.y = 0.0f;
	if (!Input::IsKeyDown(Key::A) && !Input::IsKeyDown(Key::D))
		dir.x = 0.0f;

	HD_INFO("v: {}", v);

	if (glm::length(dir) != 0.0f)
		pos += glm::normalize(dir) * v * dt;
	Hudi::Renderer2D::DrawQuad(pos, { 1.0f, 1.0f }, texture);

	Hudi::Renderer2D::EndScene();


}

void GameLayer::OnGUIRender()
{
}

void GameLayer::OnEvent(Hudi::Event& e)
{
}
