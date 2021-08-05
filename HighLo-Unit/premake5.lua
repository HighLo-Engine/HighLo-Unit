project "HighLo-Unit"
    kind "SharedLib"
    language "C++"
	cppdialect "C++17"
	staticruntime "on"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-obj/" .. outputdir .. "/%{prj.name}")

    files
    { 
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
		"src"
    }

    links
    {
    }

    defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

    filter "system:windows"
        systemversion "latest"
        staticruntime "off"

        disablewarnings { "5033" }

        defines
        {
            "HL_BUILD",
            "HL_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "HL_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "HL_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "HL_DIST"
        optimize "On"
