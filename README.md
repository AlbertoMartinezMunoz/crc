# CRC
Library for computing CRC codes both in C and C++

## FOLDER STRUCTURE

./         Makefile and configure scripts.
./build*   Used for storing build results. Must not be checked into source control.
./src      Main compilable source location.
./include  Directory for public headers.
./tests    Directory for tests.
./external Directory for packages/projects to be used by the project, but not edited as part of the project.

## BUILD

### Release

To build the release, first we launch CMake and then make.

```console
cmake . -H. -Bbuild
cd build
make -j3
```

All in one line:

```console
cmake . -H. -Bbuild; cd build; make -j3; cd ..
```

### Unitary Testing

The unit tests will be launched using **ctest**

To build the unitary tests, first we launch CMake with the UTEST custom option and then make.

```console
cmake . -DUTEST=ON -H. -Bbuildtest
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
cmake . -DUTEST=ON -H. -Bbuildtest; cd buildtest; make -j3 && ctest -VV; cd ..
```

## REFERENCES

- Online CRC-8 CRC-16 CRC-32 Calculator https://crccalc.com/
https://barrgroup.com/embedded-systems/how-to/crc-calculation-c-code
