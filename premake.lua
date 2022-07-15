
include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"

workspace "3D Renderer"

	architecture "x86_64"
	startproject "OpenGL Renderer"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "3D-OGLVK"

	location "3D-OGLVK"
	kind "SharedLib"
	Language "C++"

	targetdir = ("bin/" ..outputdir.. "/%{prj.name}")
	objdir = ("obj/" ..outputdir.. "/%{prj.name}")

	files 
	{
		"%/{prj.name}/Source/**.h"
		"%/{prj.name}/Source/**.cpp"
		"%/{prj.name}/Source/Shaders/**.glsl"
	}
	include
	{
		"%/{prj.name}/Thirdparty/spdlog/include"
		"%/{prj.name}/Thirdparty/include/GLFW"
		"%/{prj.name}/Thirdparty/include/glad"
		"%/{prj.name}/Thirdparty/include/imgui"
		"%/{prj.name}/Thirdparty/include/vulkan"
	}

	postbuildcommand
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir.. "../Sandbox/")
	}





group "Dependencies"
	include "3D-Renderer/Thirdparty/include/GLFW"
	include "3D-Renderer/Thirdparty/include/glad"
	include "3D-Renderer/Thirdparty/include/imgui"
	include "3D-Renderer/Thirdparty/include/vulkan"
group ""

include "OpenGL Renderer"