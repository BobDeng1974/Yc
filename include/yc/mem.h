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

void* ymalloc(size_t size);
void* ycalloc(size_t size);
void* yrealloc(void* ptr, size_t size);
void* yrecalloc(void* ptr, size_t size);

size_t ynalloc(size_t size);
size_t ysalloc(void* ptr);

void yfree(void* ptr);
void ysfree(void* ptr, size_t size);

#ifdef __cplusplus
}
#endif

#endif // YC_MEM_H
