/*
 *	***** BEGIN LICENSE BLOCK *****
 *
 *	Copyright 2017 Yzena Tech
 *
 *	Licensed under the Apache License, Version 2.0 (the "Apache License")
 *	with the following modification; you may not use this file except in
 *	compliance with the Apache License and the following modification to it:
 *	Section 6. Trademarks. is deleted and replaced with:
 *
 *	6. Trademarks. This License does not grant permission to use the trade
 *		names, trademarks, service marks, or product names of the Licensor
 *		and its affiliates, except as required to comply with Section 4(c) of
 *		the License and to reproduce the content of the NOTICE file.
 *
 *	You may obtain a copy of the Apache License at
 *
 *		http://www.apache.org/licenses/LICENSE-2.0
 *
 *	Unless required by applicable law or agreed to in writing, software
 *	distributed under the Apache License with the above modification is
 *	distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 *	KIND, either express or implied. See the Apache License for the specific
 *	language governing permissions and limitations under the Apache License.
 *
 *	****** END LICENSE BLOCK ******
 *
 *	*****************************************************************
 *
 *	******* BEGIN FILE DESCRIPTION *******
 *
 *	String definitions.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_STRING_H
#define YC_STRING_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

#include <string.h>

#ifndef _WIN32

#define ychar_t char
#define YSTR(s) (s)

#else

#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <tchar.h>

/* Windows UNICODE wide character support */
#define ychar_t TCHAR
#define YSTR(s) _TEXT(s)
#define strlen _tcslen
#define strcpy _tcscpy
#define strcat _tcscat
#define strcmp _tcscmp
#define strrchr _tcsrchr
#define strncmp _tcsncmp

#endif

#ifdef __cplusplus
}
#endif

#endif // YC_STRING_H
