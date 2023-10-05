#pragma once
#include <glm/vec3.hpp>

namespace eng
{
    class RenderAPI
    {
	public:
	    RenderAPI(void* proc);
	    void Update(const glm::vec3& color = glm::vec3(0.3f, 0.4f, 0.6f));
    };
}
