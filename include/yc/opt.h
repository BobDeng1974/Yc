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
 *	Public header for optimization capabilities.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_OPT_H
#define YC_OPT_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @file opt.h
 */

/**
 * @defgroup opt opt
 * @brief Optimizations utilities.
 * @{
 */

/**
 * @def yoptnone
 * A macro for having no optimizations on certain functions. This is useful
 * either for debugging or for making sure that critical security code is not
 * optimized, which could undo the secure coding.
 */

/**
 * @def yinline
 * A macro that mandates to the compiler that a function should be inlined. It
 * is only defined when it is useful, so in other cases, it does nothing.
 */

/**
  @def ynoinline
 * A macro that mandates to the compiler that a function should *never* be
 * inlined. This is useful for making sure that alloca calls are not inlined,
 * or for security reasons.
 */

#ifdef __clang__

#	if __has_attribute(optnone)
#		define yoptnone __attribute__((optnone))
#	else
#		define yoptnone
#	endif // __has_attribute(optnone)

#	if defined(LINK_TIME_OPTIMISATION) && !defined(SAVE_ON_FLASH) && defined(NDEBUG) && __has_attribute(always_inline)
#		define yinline __attribute__((always_inline))
#	else
#		define yinline
#	endif // defined(LINK_TIME_OPTIMISATION)

#	if __has_attribute(noinline)
#		define ynoinline __attribute__((noinline))
#	else
#		define ynoinline
#	endif // __has_attribute(noinline)

#else // __clang__

#	define yoptnone
#	define yinline
#	define ynoinline

#endif // __clang__

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif // YC_OPT_H
