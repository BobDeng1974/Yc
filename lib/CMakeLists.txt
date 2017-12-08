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

set(JEMALLOC_AUTOGEN "jemalloc_autogen")
set(JEMALLOC_CONFIGURE "jemalloc_configure")

set(JEMALLOC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/jemalloc")

set(JEMALLOC "jemalloc")
set(JEMALLOC_PIC "jemalloc_pic")
set(JEMALLOC_LIB_NAME "lib${JEMALLOC_PIC}.a")
set(JEMALLOC_INC_DIR "${JEMALLOC_DIR}/include")
set(JEMALLOC_BUILD_DIR "${CMAKE_CURRENT_BINARY_DIR}/jemalloc")
set(JEMALLOC_LIB "lib/${JEMALLOC_LIB_NAME}")
set(JEMALLOC_OUT "${JEMALLOC_BUILD_DIR}/${JEMALLOC_LIB_NAME}")

# Got to make the directory.
execute_process(
	COMMAND ${CMAKE_COMMAND} -E make_directory ${JEMALLOC_BUILD_DIR}
)

# Run the autogen.
add_custom_target(
	"${JEMALLOC_AUTOGEN}"
	COMMAND ./autogen.sh --prefix=${CMAKE_INSTALL_PREFIX} --with-jemalloc-prefix=je_
	        --disable-cxx CC=${CMAKE_C_COMPILER} CFLAGS=${CMAKE_C_FLAGS_${CONFIG_TYPE}}
	WORKING_DIRECTORY "${JEMALLOC_DIR}"
)

# Run the configure.
add_custom_target(
	"${JEMALLOC_CONFIGURE}"
	COMMAND ${JEMALLOC_DIR}/configure --prefix=${CMAKE_INSTALL_PREFIX} --with-jemalloc-prefix=je_
	        --disable-cxx CC=${CMAKE_C_COMPILER} CFLAGS=${CMAKE_C_FLAGS_${CONFIG_TYPE}}
	WORKING_DIRECTORY "${JEMALLOC_BUILD_DIR}"
	BYPRODUCTS "${JEMALLOC_BUILD_DIR}/Makefile"
)
add_dependencies("${JEMALLOC_CONFIGURE}" "${JEMALLOC_AUTOGEN}")

# Add the jemalloc lib and copy it..
add_custom_command(
	OUTPUT "${JEMALLOC_LIB}"
	COMMAND make -j4
	DEPENDS "${JEMALLOC_CONFIGURE}"
	WORKING_DIRECTORY "${JEMALLOC_BUILD_DIR}"
)
add_custom_command(
	OUTPUT "${JEMALLOC_OUT}"
	COMMAND ${CMAKE_COMMAND} -E copy ${JEMALLOC_LIB} ${CMAKE_CURRENT_BINARY_DIR}
	COMMAND ${CMAKE_COMMAND} -E copy src/*.o ${CMAKE_CURRENT_BINARY_DIR}
	DEPENDS "${JEMALLOC_LIB}"
	WORKING_DIRECTORY "${JEMALLOC_BUILD_DIR}"
)

# Add a custom target and library.
add_custom_target("${JEMALLOC_PIC}" DEPENDS "${JEMALLOC_OUT}")
add_library("${JEMALLOC}" STATIC IMPORTED GLOBAL)

# Make sure to set important properties.
set_target_properties("${JEMALLOC}"
	PROPERTIES
	DEPENDS "${JEMALLOC_PIC}"
	IMPORTED_LOCATION "${JEMALLOC_OUT}"
	INTERFACE_INCLUDE_DIRECTORIES "${JEMALLOC_INC_DIR}"
)

merge_lib("${JEMALLOC}" "${JEMALLOC_PIC}")
