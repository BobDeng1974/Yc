/*
 *	***** BEGIN LICENSE BLOCK *****
 *
 *	Copyright 2017 Project LFyre
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
 *	Main public header file for Yc.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_H
#define YC_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdio.h>

/**
 * @file assert.h
 */

// The macro yassert (and accompanying function _yassert) were adapted from
// the Stack Overflow answer at https://stackoverflow.com/a/37264642/3281147.

/**
 * @defgroup assert assert
 * @brief Assert utilities.
 * @{
 */

/**	@brief Function that handles the assert.
 *	@param expr_str	The expression turned into a string.
 *	@param expr		The expression.
 *	@param file		The file name where the assert is.
 *	@param line		The line number where the asert is.
 *	@param msg		The message to display on assert failure.
 */
void _yassert(const char* expr_str, bool expr, const char* file, int line, const char* msg);

/**
 * @def __YASSERT__
 *  A macro that is defined when yassert is functional.
 */

/**
  @def yassert(Expr, Msg)
 * An assert macro to make the printing prettier than the default assert macro.
 * It evaluates @a Expr and it is false, it prints @a Msg along with other info.
 */

#if !defined(NDEBUG) || defined(__YASSERT__)

#	ifndef __YASSERT__
#		define __YASSERT__
#	endif

#	define yassert(Expr, Msg) _yassert(#Expr, Expr, __FILE__, __LINE__, Msg)

#else
#	define yassert(Expr, Msg) ;
#endif

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif // YC_H
