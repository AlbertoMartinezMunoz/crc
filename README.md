# CRC
Library for computing CRC codes both in C and C++

# SETUP #

## Google Test

Google test can be added to your git repo as a git submodule.

```console
$ git submodule add https://github.com/google/googletest.git ./vendor/gtest
```

Also if we are using C++20 in our project, we have to ensure that C++20 is used adding the following line in the root CMakeList file

```cmake
set(CMAKE_CXX_STANDARD 20)
```

## Valgrind

#### Installation

```console
sudo apt-get update sudo apt-get -y install valgrind
```

#### Docker

```console
RUN apt-get update && apt-get install -y valgrind
```

## CppCheck

Cppcheck is a command-line tool that tries to detect bugs that your C/C++ compiler doesn’t see. It is versatile, and can check non-standard code including various compiler extensions, inline assembly code, etc. Its internal preprocessor can handle includes, macros, and several preprocessor commands. While Cppcheck is highly configurable, you can start using it just by giving it a path to the source code.

#### Installation

```console
sudo apt-get update
sudo apt-get -y install cppcheck
```

#### Docker

```console
RUN apt-get update && apt-get install -y cppcheck
```

#### Launch

```console
mkdir buildcppcheck
rm ./buildcppcheck/*.a1
rm ./buildcppcheck/*.s1
cppcheck --cppcheck-build-dir=buildcppcheck --std=c++20 --language=c++ --xml --error-exitcode=2 --enable=style --output-file=./buildcppcheck/basic_report.xml --file-list=cppcheck-input.txt
rm ./buildcppcheck/*.a1
rm ./buildcppcheck/*.s1
cppcheck --cppcheck-build-dir=buildcppcheck --std=c++20 --language=c++ --xml --error-exitcode=2 --enable=style --output-file=./buildcppcheck/bug_h_report.xml --file-list=cppcheck-input.txt --bug-hunting
cppcheck-htmlreport --source-dir=. --report-dir=./buildcppcheck/basic --file=./buildcppcheck/basic_report.xml --title=BASIC
cppcheck-htmlreport --source-dir=. --report-dir=./buildcppcheck/bug --file=./buildcppcheck/bug_h_report.xml --title=BUG_HUNTING
```

With the following options for cppcheck:

- '--bug-hunting' Enable noisy and soundy analysis. The normal Cppcheck analysis is turned off.
- '--cppcheck-build-dir=<dir>' Cppcheck work folder.
- '--language=<language>' Forces cppcheck to check all files as the given languaje. Valid values are: c, c++
- '--std=<id>' Set standard.
- '--error-exitcode=<n>' If errors are found, integer [n] is returned instead of the default '0'. '1' is returned if arguments are not valid or if no input files are provided. Note that your operating system can modify this value, e.g. '256' can become '0'.
- '--xml' Write results in xml format to error stream (stderr).
- '--enable=<id>' Enable additional checks. The available ids are:
    * all Enable all checks. It is recommended to only use --enable=all when the whole program is scanned, because this enables unusedFunction.
    * warning Enable warning messages
    * style Enable all coding style checks. All messages with the severities 'style', 'warning', 'performance' and 'portability' are enabled.
    * performance Enable performance messages
    * portability Enable portability messages
    * information Enable information messages
    * unusedFunction Check for unused functions. It is recommended to only enable this when the whole program is scanned.
    * missingInclude Warn if there are missing includes. For detailed information, use '--check-config'.
    Several ids can be given if you separate them with commas. See also --std
- '--output-file=<file>' Write results to file, rather than standard error.
- '--file-list=<file>' Specify the files to check in a text file. Add one filename per line. When file is '-,' the file list will be read from standard input.

# DOCKER DEVELOP IMAGE

Create a docker image with gcc, cmake and valgrind for use in the bitbucket pipeline.

## Docker Hub

Create an account on [docker hub](https://hub.docker.com/)

## Docker Engine

Install docker engine for create an maintain the development image.

#### Set up the repository

Configure the linux environment:

```console
sudo apt-get update
sudo apt-get install \
    ca-certificates \
    curl \
    gnupg \
    lsb-release
```

Add docker's GPG key:

```console
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/ubuntu/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```

Setup the repo

```console
echo \
  "deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/ubuntu \
  $(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

#### Install Docker Engine

Update the apt package index:

```console
sudo apt-get update
```
To install the latest version, run:

```console
sudo apt-get install docker-ce docker-ce-cli containerd.io docker-compose-plugin
```

Verify that the Docker Engine installation is successful by running the hello-world image:

```console
sudo docker run hello-world
```

## Docker Image

We could create our own Docker image using Dockerfile to Create an Image.

A Dockerfile is a simple text document that contains a series of commands that Docker uses to build an image. Several commands supported in Dockerfile are FROM, CMD, ENTRYPOINT, VOLUME, ENV, and more. A simple Dockerfile looks as follows:

```dockerfile
FROM busybox:latest
CMD ["date"]
```

**Note:** An important point to remember is that this file should be named as Dockerfile.

The docker build command builds an image from a Dockerfile. To build the image from our above Dockerfile, use this command:

```console
$ sudo docker build -t cpp_develop_image .

Sending build context to Docker daemon  2.048kB
Step 1/2 : FROM gcc:10.2
 ---> 987c8580a041
Step 2/2 : CMD ["date"]
 ---> Running in 4a4e49080fa8
Removing intermediate container 4a4e49080fa8
 ---> 391dd7de6bde
Successfully built 391dd7de6bde
Successfully tagged cpp_development_image:latest
```

Now, let’s run a container based on our image. You will find that it will print out the date as shown below:

```console
$ sudo docker run -it --name cpp_develop_app cpp_develop_image

Thu Dec 29 17:02:40 UTC 2022
```

#### Publish an Image to Docker Hub

To be able to publish our Docker images to Docker Hub, there are some steps that we need to follow.

Before we can push our image to Docker Hub, we will first need to have an account on Docker Hub. Create an account by visiting this link. The signup process is relatively simple.

For uploading our image to Docker Hub, we first need to create a repository. To create a repo:

- Sign in to Docker Hub
- Click on ‘Create Repository’ on the Docker Hub welcome page:
- Fill in the repository name as example-image, the Docker image that we created earlier using Dockerfile. Also, describe your repo like "My First Repository". Finally, click on the create button. Refer to the below screenshot:

Now we will push our built image to the Docker Hub registry.

Log into the Docker public registry from your local machine terminal using Docker CLI:

```console
$ sudo docker login

Login with your Docker ID to push and pull images from Docker Hub. If you don't have a Docker ID, head over to https://hub.docker.com to create one.
Username: traquinedes        
Password: 
WARNING! Your password will be stored unencrypted in /root/.docker/config.json.
Configure a credential helper to remove this warning. See
https://docs.docker.com/engine/reference/commandline/login/#credentials-store

Login Succeeded
```

After that, we have to tag the image. This is a crucial step that is required before we can upload our image to the repository. As we discussed earlier, Docker follows the naming convention to identify unofficial images. What we are creating is an unofficial image. Hence, it should follow that syntax. According to that naming convention, the unofficial image name should be named as follows: <username>/<image_name>:<tag_name>. In my case, I need to rename it as gauravvv/example_image:latest

```console
$ sudo docker tag cpp_develop_image:latest traquinedes/cpp_develop:latest
```

Publish the image

```console
$ sudo docker push traquinedes/cpp_develop:latest
```

Upload your tagged image to the repository using the docker push command. Once complete, you can see the image there on Docker Hub. That's it; you have successfully published your Docker image. If you want to test out your image, use the below command and launch a container from it:

```console
$ docker pull traquinedes/cpp_develop:latest
$ docker run -it traquinedes/cpp_develop:latest
```

# BUILD #

## Release

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

## Unitary Testing

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

# REFERENCES

https://crccalc.com/
