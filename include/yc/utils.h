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
 *	Utilities.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_UTILS_H
#define YC_UTILS_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @def yattr(s)
 * A macro to handle attributes.
 */

/**
 * @def yunused
 * A macro to label anything as unused
 * (to silence warnings).
 */

#ifdef __linux__

#	if defined(__clang__) || defined(__GNUC__)
#		define yattr(s) __attribute__((s))
#		define yunused yattr(unused)
#		define yctor yattr(constructor)
#	else
#		error "Clang and GCC are the only supported compilers"
#	endif

#else

#	define yctor

#endif

#ifdef __cplusplus
}
#endif

#endif // YC_UTILS_H
