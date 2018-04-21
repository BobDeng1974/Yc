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
 *	Main source file for Yc.
 *
 *	******** END FILE DESCRIPTION ********
 */

#include <yc/assert.h>
#include <yc/opt.h>

#include <stdio.h>
#include <stdlib.h>

void _yassert_fail(const char* expr_str, const char* file, int line, const char* func, const char* msg)
{
	fprintf(stderr, "\nAssert failed: %s\n\n", msg);
	fprintf(stderr, "    Expected:  %s\n\n", expr_str);
	fprintf(stderr, "    Source:    %s:%d\n\n", file, line);
	fprintf(stderr, "    Function:  %s()\n\n", func);

	abort();
}
