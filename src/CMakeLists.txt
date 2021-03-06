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

set("YC_SRC"

	# Put all source files here.
	"assert.c"
)

# Make sure we find dl and pthread.
find_library(DL dl "/usr/lib" "/usr/local/lib")
find_library(PTHREAD pthread PATHS "/usr/lib" "/usr/local/lib")

# Set the name of the master library.
set(YC "${PROJECT_NAME}")

# Create the library.
create_pic_library(
	"${YC}" "${YC}" "${YC_SRC}" YES

	# Add required libraries here.
	"${PTHREAD}"
	"${DL}"
)
