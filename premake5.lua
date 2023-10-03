workspace "Testing"
    
    configurations { "Debug", "Release" }


    include "vendor/glad"
    include "vendor/glfw"

    project "eng"
        location "eng"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir "bin/%{prj.name}"
	objdir "bin-int/%{prj.name}"

	files
	{
	    "%{prj.name}/src/**.hpp",
	    "%{prj.name}/src/**.cpp",
	}

	includedirs
	{
	    "%{prj.name}/src",
	    "%{wks.location}/vendor/glfw/include",
	    "%{wks.location}/vendor/glad/include",
	    "%{wks.location}/vendor/glm",
	}

	 links 
	 {
            'dl',
            'X11',
            'm',
            'pthread',
            'glfw',
            'glad',
        }

	defines
	{
	    "GLFW_INCLUDE_NONE"
	}




    project "app"
        location "app"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir "bin/%{prj.name}"
	objdir "bin-int/%{prj.name}"

	files
	{
	    "%{prj.name}/src/**.hpp",
	    "%{prj.name}/src/**.cpp",
	}

	includedirs
	{
	    "eng/src",
	    "vendor/glfw/include",
	    "vendor/glad/include"
	}

	links
	{
	    "eng",
	    "glfw",
	    "glad"
	}

