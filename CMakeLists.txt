#	***** BEGIN LICENSE BLOCK *****
#
#	Copyright 2017 Yzena Tech
#
#	Licensed under the Apache License, Version 2.0 (the "Apache License")
#	with the following modification; you may not use this file except in
#	compliance with the Apache License and the following modification to it:
#	Section 6. Trademarks. is deleted and replaced with:
#
#	6. Trademarks. This License does not grant permission to use the trade
#		names, trademarks, service marks, or product names of the Licensor
#		and its affiliates, except as required to comply with Section 4(c) of
#		the License and to reproduce the content of the NOTICE file.
#
#	You may obtain a copy of the Apache License at
#
#		http://www.apache.org/licenses/LICENSE-2.0
#
#	Unless required by applicable law or agreed to in writing, software
#	distributed under the Apache License with the above modification is
#	distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
#	KIND, either express or implied. See the Apache License for the specific
#	language governing permissions and limitations under the Apache License.
#
#	****** END LICENSE BLOCK ******

cmake_minimum_required(VERSION 3.0)

project(yc C)

# Necessary to suppress a useless warning with QtCreator.
set(ignoreMe "${QT_QMAKE_EXECUTABLE}")
set(ignoreMe "${CMAKE_CXX_COMPILER}")

if(NOT CMAKE_BUILD_TYPE)
	set(CMAKE_BUILD_TYPE Release)
endif()

if(NOT "${CMAKE_BUILD_TYPE}" MATCHES "Debug")
	set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -flto")
endif()

set("YC_DOCS_DIR" "docs")
set("YC_INCLUDE_DIR" "include")
set("YC_SRC_DIR" "src")

add_subdirectory("cmake")

add_subdirectory("${YC_DOCS_DIR}")

include_directories("${YC_INCLUDE_DIR}")
add_subdirectory("${YC_INCLUDE_DIR}")

add_subdirectory("${YC_SRC_DIR}")
