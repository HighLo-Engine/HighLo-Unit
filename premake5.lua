include "./vendor/bin/premake/solution_items.lua"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}


LibDir = {}


workspace "HighLo-Unit"
    architecture "x64"
    configurations { "Debug", "Release", "Dist" }

	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	include "HighLo-Unit"
