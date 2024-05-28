workspace "Wars"
	architecture "x64"
	startproject "Application"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Hudi/vendor/Glad"
	include "Hudi/vendor/yaml-cpp"
group ""

group "Core"
	include "Hudi"
	include "Application"
group ""