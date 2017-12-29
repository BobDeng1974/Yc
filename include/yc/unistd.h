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
 *	*****************************************************************
 *
 *	Original code under CC-BY-SA. If users of this file would like to use that
 *	license instead, they may.
 *
 *	****** END LICENSE BLOCK ******
 *
 *	*****************************************************************
 *
 *	******* BEGIN FILE DESCRIPTION *******
 *
 *	A replacement for unistd.h if necessary.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_UNISTD_H
#define YC_UNISTD_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WIN32

#include <unistd.h>

#else
/* This is intended as a drop-in replacement for unistd.h on Windows.
 * Please add functionality as neeeded.
 * https://stackoverflow.com/a/826027/1202830
 */

#include <stdlib.h>
#include <io.h>

// getopt at: https://gist.github.com/ashelly/7776712
//#include <getopt.h>

// For getpid() and the exec..() family.
#include <process.h>

// For _getcwd() and _chdir().
#include <direct.h>

#define getcwd _tgetcwd
#define chdir _tchdir

#define srandom srand
#define random rand

/* Values for the second argument to access.
   These may be OR'd together.  */

// Test for read permission.
#define R_OK    (4)

// Test for write permission.
#define W_OK    (2)

// Execute permission - unsupported in Windows.
//#define   X_OK    1

// Test for existence.
#define F_OK    0

#define access _access
#define dup2 _dup2
#define execve _execve
#define ftruncate _chsize
#define unlink _unlink
#define fileno _fileno
#define getcwd _getcwd
#define chdir _chdir
#define isatty _isatty
#define lseek _lseek

// The functions read(), write(), and close() are NOT being #defined
// here, because while there are file handle specific versions for
// Windows, they probably don't work for sockets. You need to look
// at your app and consider whether to call e.g. closesocket().

#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif

#define STDIN_FILENO 0
#define STDOUT_FILENO 1
#define STDERR_FILENO 2

// Should be in some equivalent to <sys/types.h>.
typedef __int8            int8_t;
typedef __int16           int16_t;
typedef __int32           int32_t;
typedef __int64           int64_t;
typedef unsigned __int8   uint8_t;
typedef unsigned __int16  uint16_t;
typedef unsigned __int32  uint32_t;
typedef unsigned __int64  uint64_t;

#endif // _WIN32

#ifdef __cplusplus
}
#endif

#endif // YC_UNISTD_H
