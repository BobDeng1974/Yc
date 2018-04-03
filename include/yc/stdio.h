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
 *	A replacement for unistd.h if necessary.
 *
 *	******** END FILE DESCRIPTION ********
 */

#ifndef YC_STDIO_H
#define YC_STDIO_H

/* For C++ compatibility. */
#ifdef __cplusplus
extern "C" {
#endif

#ifndef _WIN32

#	include <stdio.h>

#else

#	include <stdio.h>

#	ifdef _UNICODE

// File operations.
#		define remove _wremove
#		define rename _wrename
#		define tmpfile _wtmpfile
#		define tmpnam _wtmpnam

// File access.
#		define fclose _wfclose
#		define fflush _wfflush
#		define fopen _wfopen
#		define freopen _wfreopen
#		define setbuf _wsetbuf
#		define setvbuf _wsetvbuf

// Formatted I/O.
#		define fprintf _wfprintf
#		define fscanf _wfscanf
#		define printf _wprintf
#		define scanf _wscanf
#		define snprintf _wsnprintf
#		define sprintf _wsprintf
#		define sscanf _wsscanf
#		define vfprintf _wvfprintf
#		define vfscanf _wvfscanf
#		define vprintf _wvprintf
#		define vscanf _wvscanf
#		define vsnprintf _wvsnprintf
#		define vsprintf _wvsprintf
#		define vsscanf _wvsscanf

// Character I/O.
#		define fgetc _wfgetc
#		define fgets _wfgets
#		define fputf _wfputf
#		define fputs _wfputs
#		define getc _wgetc
#		define getchar _wgetchar
#		define gets _wgets
#		define putc _wputc
#		define putchar _wputchar
#		define puts _wputs
#		define ungetc _wungetc

// Direct I/O.
#		define fread _wfread
#		define fwrite _wfwrite

// File positioning.
#		define fgetpos _wfgetpos
#		define fseek _wfseek
#		define fsetpos _wfsetpos
#		define ftell _wftell
#		define rewind _wrewind

// Error handling.
#		define clearerr _wclearerr
#		define feof _wfeof
#		define ferror _wferror
#		define perror _wperror

#	endif

#endif  // _WIN32

#ifdef __cplusplus
}
#endif

#endif  // YC_STDIO_H
