#include "render_api.hpp"
#include <glad/glad.h>

namespace eng
{
    RenderAPI::RenderAPI(void* proc)
    {
	gladLoadGLLoader((GLADloadproc)proc);
    }

    void RenderAPI::Update(const glm::vec3& color)
    {
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(color.x, color.y, color.z, 1.0f);
    }
}
