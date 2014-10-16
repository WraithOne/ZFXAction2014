////////////////////////////////////////////
///
/// WraithOne
/// www.Dark-Abyss.net
///
/// ZFX Action 2014
///
/// Theme:
///
////////////////////////////////////////////
#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef _WIN32
	#define SYS_WINDOWS
	#ifndef NOMINMAX
	#define NOMINMAX
	#endif

#elif defined (__linux__)
	#define SYS_LINUX

#elif defined (__APPLE__)
	#define SYS_MACOS

#endif

#endif