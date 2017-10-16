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
 *	Source file for Yc's memory functions.
 *
 *	******** END FILE DESCRIPTION ********
 */

#include <jemalloc/jemalloc.h>

#include <yc/assert.h>
#include <yc/mem.h>
#include <yc/opt.h>

const char* yptrNullMsg = "ptr must not be NULL";
const char* ysizeZeroMsg = "size must not be zero";

void* ymalloc(size_t size) {
	yassert(size != 0, ysizeZeroMsg);
	return mallocx(size, JEMALLOC_FLAGS_NONE);
}

void* ycalloc(size_t num, size_t size) {
	yassert(size != 0, ysizeZeroMsg);
	return mallocx(num * size, JEMALLOC_FLAGS_CALLOC);
}

void* yrealloc(void* ptr, size_t size) {

	yassert(size != 0, ysizeZeroMsg);

	void* result;

	if (ptr != NULL) {

		size_t newlen = xallocx(ptr, size, 0, JEMALLOC_FLAGS_NONE);

		if (newlen == size) {
			result = ptr;
		}
		else {
			result = rallocx(ptr, size, JEMALLOC_FLAGS_NONE);
		}
	}
	else {
		result = mallocx(size, JEMALLOC_FLAGS_NONE);
	}

	return result;
}

void* yrecalloc(void* ptr, size_t size) {

	yassert(size != 0, ysizeZeroMsg);

	void* result;

	if (ptr != NULL) {

		size_t newlen = xallocx(ptr, size, 0, JEMALLOC_FLAGS_CALLOC);

		if (newlen == size) {
			result = ptr;
		}
		else {
			result = rallocx(ptr, size, JEMALLOC_FLAGS_CALLOC);
		}
	}
	else {
		result = mallocx(size, JEMALLOC_FLAGS_CALLOC);
	}

	return result;
}

size_t yxmalloc(void* ptr, size_t size) {
	yassert(size != 0, ysizeZeroMsg);
	yassert(ptr != NULL, yptrNullMsg);
	return xallocx(ptr, size, 0, JEMALLOC_FLAGS_NONE);
}

size_t yxcalloc(void* ptr, size_t size) {
	yassert(size != 0, ysizeZeroMsg);
	yassert(ptr != NULL, yptrNullMsg);
	return xallocx(ptr, size, 0, JEMALLOC_FLAGS_CALLOC);
}

size_t ynalloc(size_t size) {
	yassert(size != 0, ysizeZeroMsg);
	return nallocx(size, JEMALLOC_FLAGS_NONE);
}

size_t ysalloc(void* ptr) {
	yassert(ptr != NULL, yptrNullMsg);
	return sallocx(ptr, JEMALLOC_FLAGS_NONE);
}

void yfree(void* ptr) {

	if (ylikely(ptr != NULL)) {
		dallocx(ptr, JEMALLOC_FLAGS_NONE);
	}
}

void ysfree(void* ptr, size_t size) {

	if (ylikely(ptr != NULL)) {
		yassert(size != 0, ysizeZeroMsg);
		sdallocx(ptr, size, JEMALLOC_FLAGS_NONE);
	}
}
