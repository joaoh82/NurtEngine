workspace "NurtEngine"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "NurtEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "NurtEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "NurtEngine/vendor/imgui"

group "Dependencies"
	include "NurtEngine/vendor/GLFW"
	include "NurtEngine/vendor/Glad"
	include "NurtEngine/vendor/imgui"

project "NurtEngine"
	location "NurtEngine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "nepch.h"
	pchsource "NurtEngine/src/nepch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
	}

	links 
	{ 
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib",
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "off"
		systemversion "latest"

		defines
		{
			"NE_PLATFORM_WINDOWS",
			"NE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox\"")
		}

	filter "configurations:Debug"
		defines "NE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		runtime "Release"
		symbols "On"

	filter "configurations:Debug"
		defines "NE_DIST"
		runtime "Release"
		symbols "On"
		
project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}

	includedirs
	{
		"NurtEngine/vendor/spdlog/include",
		"NurtEngine/src"
	}

	links 
	{
		"NurtEngine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"NE_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "NE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "NE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "NE_DIST"
		runtime "Release"
		optimize "On"