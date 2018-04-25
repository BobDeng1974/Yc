# Yc

Yc is a library of utilities for C.

Yc is developed by [Yzena](http://yzena.com/).

Yc is Free and Open Source Software (FOSS). It is licensed under a modified
[Apache License 2.0](https://www.apache.org/licenses/LICENSE-2.0.html). The
[modification](http://graphics.pixar.com/opensubdiv/docs/license.html) was first
used by [Pixar Animation Studios](https://www.pixar.com/) for use on the
[OpenSubdiv](http://graphics.pixar.com/opensubdiv/docs/intro.html) project.

## Getting Started

To get started, clone the repo, and then run the following commands in the root
directory:

```
git config --local include.path ../.gitconfig
git submodule update --init --recursive
```

## Dependencies

Yc depends on CMake. On Ubuntu, it can be installed with the following command:

```
sudo apt install cmake cmake-curses-gui
```

## Status

Yc is not even in Alpha stage yet. This software is not ready for use.

## Language

Yc is written in pure ISO C11.

## Git Workflow

Yc uses the git workflow described
[here](http://endoflineblog.com/oneflow-a-git-branching-model-and-workflow).
Developers who want to contribute to Yc are encouraged to read that post
carefully.

For feature branches, it uses `rebase + merge --no-ff` (option 3). It also uses
a `develop`/`master` split. (Main development is on `develop`, and `master` just
points to the latest tagged release to make it easy for users to get the latest
release.)

## Commit Messages

Projects under Yzena, including Yc, use the commit message guidelines laid out
in [this blog post](http://tbaggery.com/2008/04/19/a-note-about-git-commit-messages.html).

## Semantic Versioning

Yc uses [semantic versioning](http://semver.org/).

## Contents Listing

Every folder contains a README file which lists the purposes for the files and
folders in that directory.

## Contents

Files:

	CMakeLists.txt  CMake is the build system used for Yc. This is the root
	                config file.
	LICENSE.md      A Markdown version of Pixar's modified Apache 2.0 license.
	NOTICE.md       The NOTICE file required by the Apache License.

Folders:

	docs        Contains all of the documentation for Yc (currently empty).
	include     Contains all of the public header files for Yc.
	src         All of Yc's source code.
	tests       Tests for Yc.
