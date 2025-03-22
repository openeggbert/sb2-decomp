# sb2-decomp
 ![Decompilation gameplay screenshot from October 29, 2024](screenshot.png)

## Introduction

This is decompiled source code of Speedy Eggbert 2.

Currently, no source code has been publicly released for Speedy Blupi.  We are using the disassemblers Ghidra and IDA to inspect the game binaries, and comparing with the official Planet Blupi source code.

## Used technologies
 
 - C++
 - DirectX 3
 
## Future Suggestions

 - Migrate from DirectX 3 to SDL 3
 - Make the game multiplatform, targeting Android and web browsers as well

## Development
 Some demangled symbol names are taken from the 2013 Windows Phone version of Speedy Blupi, which we inspected using ILSpy.  Big thanks to Ч.У.Ш on the 4PDA forum for archiving this obscure version of the game!!!
 
 Gameplay is functional, but defective and missing many features.

 For personal convenience, this code uses the BASS and BASSMIDI audio library. The original behavior using Windows MCI can be restored in `def.h` by changing `#define _BASS` to `false`.
 
 These files currently need the **most attention**, in order of priority:
 - event.cpp
 - decblupi.cpp
 - decio.cpp
 - decdesign.cpp
 - decblock.cpp
 - decmove.cpp
 - decnet.cpp
 - decor.cpp
 - misc.cpp

 These files are tentatively **complete**, but require further testing:
 - blupi.cpp
 - button.cpp
 - jauge.cpp
 - menu.cpp
 - movie.cpp
 - network.cpp
 - pixmap.cpp
 - sound.cpp
 - wave.cpp

## How to setup locally

### Clone with git

#init and update submodules
git submodule init
git submodule update

### How to setup the development environment locally

#### Install "Microsoft Visual Studio Community 2022
 
#### Install v143 toolset for desktop

#### Open the Project

Click on "Speedy Eggbert 2 Source.sln" and select Open with "Microsoft Visual Studio 2022"

Set the Platform to x86 and Debugging to Win32.

#### Set "Additional Options"

Properties / Configuration Properties / C/C++ / Command Line / Additional Options

Add : /wd4700 /wd4703

#### Platform Toolset - v143

Project Properties > General > Set Platform Toolset to v143

#### Build

Click with the right mouse button on "Speedy Eggbert 2 Source.sln"
 - launch Build/Build Speedy Eggbert 2 Source.sln

## Notes

This: is workaround: typedef struct IUnknown IUnknown;

For error: >c:\program files (x86)\windows kits\8.1\include\um\combaseapi.h(229): error C2760: syntax error: unexpected token 'identifier', expected 'type specifier'