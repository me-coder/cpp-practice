/**
 *	Author YHP
 *	Created: 16-March-2008
 *	Updated: 04-March-2025
 */

#ifndef _STRINGHANDLER
#define _STRINGHANDLER

#ifndef NULL
#define NULL 0
#endif

#include <cstring>
#include <cstdlib>
#include <cctype>
#include <iostream>

#ifdef _WIN32
#ifdef STRING_HANDLER_EXPORTS // Defined when building the DLL
#define STRING_HANDLER_API __declspec(dllexport)
#else // Defined when using the DLL
#define STRING_HANDLER_API __declspec(dllimport)
#endif
#else // not Windows
#define STRING_HANDLER_API
#endif

#endif
