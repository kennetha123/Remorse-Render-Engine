workspace "RRE"
	location ".."
	architecture "x64"
	startproject "RRE"
	
	configurations
	{
		"Debug",
		"Develop",
		"Release"
	}

trunk = "../"

-- struct to easier include dir rather than using path
IncludeDir = {}
IncludeDir["GLFW"] 		= 	(trunk .. "Externals/glfw/include")
IncludeDir["Glad"] 		= 	(trunk .. "Externals/glad/include")
IncludeDir["ImGui"] 	= 	(trunk .. "Externals/imgui")
IncludeDir["glm"] 		= 	(trunk .. "Externals/glm")
IncludeDir["stb_image"] = 	(trunk .. "Externals/stb_image")
IncludeDir["spdlog"] 	= 	(trunk .. "Externals/spdlog/include")


-- output name for bin / obj
outputName = "%{cfg.system}/%{cfg.buildcfg}/%{cfg.architecture}"

-- take another premake to build the project
include (trunk .. "Externals/imgui/project")
include (trunk .. "Externals/glad/project")
include (trunk .. "Externals/glfw/project")

-------------------------------------------------------------------------------------
------------------------ Engine project ---------------------------------------------	
-------------------------------------------------------------------------------------

project "RRE"
	location (trunk .. "Engine")
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"
	
	targetdir ("%{prj.name}/bin/" .. outputName)
	objdir ("%{prj.name}/obj/" .. outputName)

	-- use precompile header
	pchheader "rrepch.h"
	pchsource (trunk .. "Engine/Source/rrepch.cpp")
	
	files
	{
		(trunk .. "Engine/Source/**.h"),
		(trunk .. "Engine/Source/**.cpp"),
	}
	
	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	
	includedirs
	{
		(trunk .. "Engine/Source"),
	}
	
	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	
	filter "system:windows"
		systemversion "latest"
		
		-- preprocessor definition
	defines
	{
		--"_CRT_SECURE_NO_WARNINGS"
	}
	
	filter "configurations:Debug"
		defines "RRE_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Develop"
		defines "RRE_DEV"
		runtime "Release"
		optimize "on"	

	filter "configurations:Release"
		defines "RRE_RELEASE"
		runtime "Release"
		optimize "on"