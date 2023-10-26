# CRC
Library for computing CRC codes both in C and C++

## FOLDER STRUCTURE

- ./         Makefile and configure scripts.
- ./build*   Used for storing build results. Must not be checked into source control.
- ./src      Main compilable source location.
- ./include  Directory for public headers.
- ./tests    Directory for tests.
- ./external Directory for packages/projects to be used by the project, but not edited as part of the project.
- ./doc      Directory for documentation files

## BUILD

### Setup

#### Google Test

Google test is added to the git repo as a git submodule, so remember to clone the repository with the `--recurse-submodules` option.

```console
$ git submodule add https://github.com/google/googletest.git ./vendor/gtest
```

Also if we are using C++20 in our project, we have to ensure that C++20 is used adding the following line in the root CMakeList file

```cmake
set(CMAKE_CXX_STANDARD 20)
```

#### Valgrind

Valgrind will be using in the unitary testing to check there are not memory leaks.

```console
sudo apt-get update
sudo apt-get -y install valgrind
```

### Unitary Testing

The unit tests will be launched using **ctest**

To build the unitary tests, first we launch CMake with the UTEST custom option and then make.

```console
cmake . -DUTEST=ON -H. -B buildtest
cd buildtest
make -j3
```

To launch **all** the tests:

```console
ctest -VV;
```

To launch only a testsuite:

```console
ctest -R "testsuite_name" -VV
```

To use **valgrind** for checking memory leaks:

```console
ctest -T memcheck -VV
```

All in one line:

```console
cmake . -DUTEST=ON -H. -B buildtest; cd buildtest; make -j3 && ctest -VV; cd ..
```

### Release

To build the release, first we launch CMake and then make.

```console
cmake . -H. -B build
cd build
make -j3
```

All in one line:

```console
cmake . -H. -B build; cd build; make -j3; cd ..
```

## REFERENCES

- [Online CRC-8 CRC-16 CRC-32 Calculator](https://crccalc.com/)
- [Barr Group. CRC Series, Part 3: CRC Implementation Code in C/C++](https://barrgroup.com/embedded-systems/how-to/crc-calculation-c-code)

## TBD.

- Change Makefile option for unit testing from custom UTEST to using CMAKE_BUILD_TYPE with a custom build type called unitary testing or so. <https://stackoverflow.com/questions/48754619/what-are-cmake-build-type-debug-release-relwithdebinfo-and-minsizerel>
