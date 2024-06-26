
project "Application"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	defines
	{
		"HD_APP",
		"_CRT_SECURE_NO_WARNINGS"
	}

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/Hudi/vendor/spdlog/include",
		"%{wks.location}/Hudi/vendor/glm",

		"src",
		"%{wks.location}/Hudi/src"
	}

	links
	{
		"Hudi"
	}

	filter "system:windows"
		systemversion "latest"

		defines
		{
			"HD_PLATFORM_WINDOWS"
		}
		
		prebuildcommands
		{
			"{COPY} ../Dlls/ ../bin/" .. outputdir .. "/%{prj.name}"
		}
		
	filter "configurations:Debug"
		defines "HD_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "HD_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "HD_DIST"
		runtime "Release"
		optimize "on"