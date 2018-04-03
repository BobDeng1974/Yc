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

#include <yc/utils.h>

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

/**
 * @def ypure
 * A macro defining an attribute that can be used if a function only reads its
 * arguments and global variables and does not modify state.
 */

/**
 * @def yconst
 * A macro like @ref ypure except that the function does not even touch globals.
 */

/**
 * @def ynoretalias
 * An attribute that the return value of the function does not alias. Useful for
 * malloc-like functions.
 */

/**
 * @def ynonnull
 * An parameter attribute that says that the arg cannot be NULL.
 */

/**
 * @def yretnonnull
 * An parameter attribute that says that function cannot return NULL.
 */

/**
 * @def ynoreturn
 * An attribute that says that the function does not return.
 */

/**
 * @def ypacked
 * An attribute that tells the compiler to pack the struct, enum, or union.
 */

/**
 * @def ylikely(expr)
 * A macro to tell the compiler that @a expr is likely to be true.
 * @param expr	An expression that is likely to be nonzero (true).
 */

/**
 * @def yunlikely(expr)
 * A macro to tell the compiler that @a expr is likely to be false.
 * @param expr	An expression that is likely to be zero (false).
 */

#ifdef __clang__

#	if __has_attribute(optnone)
#		define yoptnone yattr(optnone)
#	else
#		define yoptnone
#	endif  // __has_attribute(optnone)

#	if defined(LINK_TIME_OPTIMISATION) && !defined(SAVE_ON_FLASH) && defined(NDEBUG) && __has_attribute(always_inline)
#		define yinline yattr(always_inline)
#	else
#		define yinline
#	endif  // defined(LINK_TIME_OPTIMISATION)

#	if __has_attribute(noinline)
#		define ynoinline yattr(noinline)
#	else
#		define ynoinline
#	endif  // __has_attribute(noinline)

#	if __has_attribute(pure)
#		define ypure yattr(pure)
#	else
#		define ypure
#	endif  // __has_attribute(pure)

#	if __has_attribute(const)
#		define yconst yattr(const)
#	else
#		define yconst
#	endif  // __has_attribute(const)

#	if __has_attribute(malloc)
#		define ynoretalias yattr(malloc)
#	else
#		define ynoretalias
#	endif  // __has_attribute(malloc)

#	if __has_attribute(nonnull)
#		define ynonnull yattr(nonnull)
#	else
#		define ynonnull
#	endif  // __has_attribute(nonnull)

#	if __has_attribute(returns_nonnull)
#		define yretnonnull yattr(returns_nonnull)
#	else
#		define yretnonnull
#	endif  // __has_attribute(returns_nonnull)

#	if __has_attribute(noreturn)
#		define ynoreturn yattr(noreturn)
#	else
#		define ynoreturn
#	endif  // __has_attribute(noreturn)

#	if __has_attribute(packed)
#		define ypacked yattr(packed)
#	else
#		define ypacked
#	endif  // __has_attribute(packed)

#	if __has_builtin(__builtin_expect)
#		define ylikely(expr) __builtin_expect(!!(expr), 1)
#		define yunlikely(expr) __builtin_expect(!!(expr), 0)
#	else
#		define ylikely(expr) (expr)
#		define yunlikely(expr) (expr)
#	endif  // __has_builtin(__builtin_expect)

#else  // __clang__

#	define yoptnone
#	define yinline
#	define ynoinline
#	define ypure
#	define yconst
#	define ynoretalias
#	define ynonnull
#	define yretnonnull
#	define ynoreturn
#	define ypacked
#	define ylikely(expr) (expr)
#	define yunlikely(expr) (expr)

#endif  // __clang__

/**
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif  // YC_OPT_H
