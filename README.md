# PriorityQueue

This repository contains a C implementation of a priority queue data structure based on sorted list implementation provided also in the project. The implementation is organized into include, test, and src folders.

## Overview

This repository provides a C data structure implementation of a priority queue. It includes a set of files that make it easy to build, run, test, and clean the project.

## Getting Started

### Prerequisites

Before you begin, ensure you have the following prerequisites installed on your system:

- **make:** If you don't have make installed, you can download and install it from the official website:
  - [Download make for windows](https://gnuwin32.sourceforge.net/packages/make.htm)
  - [make for Linux and MacOS](https://www.gnu.org/software/make/)

- **Download from the command line:**

Linux:

```shell
$ sudo apt install make -y
```

MacOS:
```shell
$ brew install make
```

- **gcc Compiler:** If you don't have gcc installed, you can download and install it from the official website:
  - [Download gcc](https://gcc.gnu.org/install/)

- **Download from the command line:**

Linux:

```shell
$ sudo apt update
$ sudo apt install build-essential
```

MacOS:
```shell
$ brew install gcc
```

Windows:
```shell
pacman -Syu
pacman -S mingw-w64-x86_64-gcc
gcc --version
```

## Installation

1. **Clone or Download the Repository:**
   You can clone this Git repository or download it as a ZIP file to your local machine.

``` shell
$ git clone https://github.com/YamtalDev/PriorityQueue.git
$ cd PriorityQueue/test/priority_queue
```
2. **Compile and run the Project:**
Use make to compile the project:

``` shell
$ make
$ make run
```

## Project structure:

```shell

├── PriorityQueue/
│   ├── bin/
│   │   ├── executables/
│   │   ├── objects/
│   │   ├── shared_libs/
│   │   └── static_libs/
│   |
|   ├── include/
│   │   └── Header file
|   |
│   ├── src/
│   │   └── src file
|   |
│   ├── test/
│   │   ├── makefile
│   │   └──test file

```

## Usage

To compile, run, debug, or clean the project, you can use the provided Makefile 
with the following commands:

- Simple compilation
```shell
$ make
```
- Running the project
```shell
$ make run
```
- Debugging the project
```shell
$ make debug
```
- Deleting all the .o, executables, shared/static libs files
```shell
$ make clean 
```
- Checking valgrind on the project
```shell
$ make vlg
```

- Release compilation with optimization -O3
```shell
$ make release
```

These simple commands streamline the development process and make it easy to work 
with each project in this repository.

## License:
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## Contact

For questions or issues, feel free to [create an issue](https://github.com/YamtalDev/PriorityQueue/issues) or contact the project maintainer.

<h3 align="left">Connect with me:</h3>
<div align="left">
<a href="https://www.linkedin.com/in/tal-aharon-930451215/" target="blank"> <img src="https://raw.githubusercontent.com/maurodesouza/profile-readme-generator/master/src/assets/icons/social/linkedin/default.svg" width="52" height="40" alt="linkedin logo"  /> </a> <a href="https://discordapp.com/users/996021603253100575" target="blank"> <img src="https://cdn.simpleicons.org/discord/5865F2" width="52" height="40" alt="discord logo"  /> </a> <a href="" target="blank"> <img src="https://cdn.jsdelivr.net/gh/devicons/devicon/icons/slack/slack-original.svg" width="52" height="40" alt="slack logo"/> </a> <a href="https://github.com/YamtalDev" target="blank"> <img src="https://skillicons.dev/icons?i=github" width="52" height="40" alt="github logo"/> </a> <a href="https://www.facebook.com/tal.aharon.395/" target="blank"> <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/facebook.svg" width="52" height="40" alt="facebook logo"  /> </a> <a href="https://medium.com/@anatolik241094" target="blank"> <img src="https://raw.githubusercontent.com/rahuldkjain/github-profile-readme-generator/master/src/images/icons/Social/medium.svg" width="52" height="40" alt="medium logo"  /> </a>
</div>