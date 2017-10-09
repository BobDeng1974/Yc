/**
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
 *	<Put description here>
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_MEM_H
#define YC_MEM_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

#include <jemalloc/jemalloc.h>

#define JEMALLOC_FLAGS_NONE 0
#define JEMALLOC_FLAGS_CALLOC MALLOCX_ZERO

/**
 * Allocates at least size bytes of memory and returns a pointer to it.
 * @param size	The amount of memory in bytes to allocate.
 * @return		A void pointer to the allocated memory.
 * @pre			size must not be zero.
 */
void* ymalloc(size_t size);

/**
 * Allocates at least size bytes of memory, zeros the memory,
 * and returns a pointer to the allocated memory.
 * @param size	The amount of memory in bytes to allocate.
 * @return		A void pointer to the allocated memory.
 * @pre			size must not be zero.
 */
void* ycalloc(size_t size);

/**
 * Reallocates the memory at ptr to be at least size bytes and
 * returns a pointer to the allocated memory. The return value
 * may be different from the provided ptr. If so, the memory is
 * copied into the new allocation.
 * @param ptr	A pointer to the memory to reallocate.
 * @param size	The expected size of the reallocation.
 * @return		A pointer to the allocated memory.
 * @pre			size must not be zero.
 */
void* yrealloc(void* ptr, size_t size);

/**
 * Reallocates the memory at ptr to be at least size bytes, zeroes
 * the new memory (if any) and returns a pointer to the allocated
 * memory. The return value may be different from the provided ptr.
 * If so, the memory is copied into the new allocation.
 * @param ptr	A pointer to the memory to reallocate.
 * @param size	The expected size of the reallocation.
 * @return		A pointer to the allocated memory.
 * @pre			size must not be zero.
 */
void* yrecalloc(void* ptr, size_t size);

/**
 * Attempts to resize the memory pointed to by ptr to be newsize bytes.
 * If it doesn't succeed, it returns the old size in bytes. If it does
 * succeed, it returns the new size in bytes.
 * @param ptr	A pointer to the memory to resize.
 * @param size	The expected new size of the memory in bytes.
 * @return		The new size of the memory.
 * @pre			ptr must not be NULL.
 * @pre			size must not be zero.
 */
size_t yxmalloc(void* ptr, size_t size);


/**
 * Attempts to resize the memory pointed to by ptr to be newsize bytes.
 * It also zeroes any new allocated memory. If it doesn't succeed, it
 * returns the old size in bytes. If it does succeed, it returns the
 * new size in bytes.
 * @param ptr	A pointer to the memory to resize.
 * @param size	The expected new size of the memory in bytes.
 * @return		The new size of the memory.
 * @pre			ptr must not be NULL.
 * @pre			size must not be zero.
 */
size_t yxcalloc(void* ptr, size_t size);

/**
 * Performs the real size calculation that ymalloc and ycalloc would
 * for the provided size, and returns the size that ymalloc and ycalloc
 * would actually allocate.
 * @param size	The size to run the allocation size calculation on.
 * @return		The size that ymalloc and ycalloc would actually allocate.
 * @pre			size must not be zero.
 */
size_t ynalloc(size_t size);

/**
 * Returns the real size of the memory allocation at the provided pointer.
 * @param ptr	The memory whose real allocated size will be returned.
 * @return		The real allocated size of the provided memory.
 * @pre			ptr must not be NULL.
 */
size_t ysalloc(void* ptr);

/**
 * Frees the memory at the pointer.
 * @param ptr	The memory to be freed.
 * @pre			ptr must not be NULL.
 */
void yfree(void* ptr);

/**
 * Frees the memory at the pointer. The provided size is used
 * as an optimization; it should be the size that was asked for
 * at allocation.
 * @param ptr	The memory to be freed.
 * @param size	The allocated size of the memory.
 * @pre			ptr must not be NULL.
 */
void ysfree(void* ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif // YC_MEM_H
