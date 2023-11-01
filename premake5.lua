workspace "Gripper2D"
    architecture "x64"
    configurations {
        "Debug",
        "Release",
        "Dist"
    }
    startproject "Sandbox"

project "Gripper2D"
    location "Gripper2D"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/%{prj.name}/%{cfg.buildcfg}")
    objdir ("obj/%{prj.name}/%{cfg.buildcfg}")

    files {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs {
        "%{prj.location}/vendor/spdlog/include",
        "%{prj.location}/src"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        defines { 
            "GR_WINDOWS",
            "GR_BUILD_DLL"
        }
        postbuildcommands {
            "{COPY} %{cfg.buildtarget.relpath} ../bin/Sandbox/%{cfg.buildcfg}"
        }

    filter "configurations:Debug"
        defines "GR_DEBUG"
        symbols "On"
    
    filter "configurations:Release"
        defines "GR_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "GR_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir "bin/%{prj.name}/%{cfg.buildcfg}"
    objdir "obj/%{prj.name}/%{cfg.buildcfg}"

    files {
        "%{prj.location}/src/**.h",
        "%{prj.location}/src/**.cpp"
    }

    includedirs {
        "Gripper2D/src",
        "Gripper2D/vendor/spdlog/include"
    }

    links "Gripper2D"

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"
        defines "GR_WINDOWS"
    
    filter "configurations:Debug"
        defines "GR_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "GR_RELEASE"
        optimize "On"
    
    filter "configurations:Dist"
        defines "GR_DIST"
        optimize "On"