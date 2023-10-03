project "glad"
    kind "StaticLib"
    language "C"

    pic "on"
    staticruntime "off"
    
    targetdir ("bin/%{prj.name}")
    objdir ("bin-int/%{prj.name}")
    files
    {
        "include/glad/glad.h",
        "include/KHR/khrplatform.h",
        "src/glad.c",
    }

    includedirs
    {
        "include"
    }
