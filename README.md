# Grocery Frequency Report

CS-210 Project Three — Grocery Frequency Report

This C++17 console application reads grocery item records, counts item
occurrences, writes a frequency report, and provides an interactive menu for
searching and displaying the collected data.

## Features

- Reads grocery records from `CS210_Project_Three_Input_File.txt`
- Counts occurrences of each grocery item
- Writes serialized results to `frequency.dat`
- Searches for an individual item's quantity
- Lists all items and their quantities
- Displays an asterisk-based frequency histogram
- Generates API documentation with Doxygen
- Publishes generated documentation to GitHub Pages through GitHub Actions
- Builds and publishes release binaries for Linux, macOS, and Windows

## Requirements

- A C++17-compatible compiler
- GNU Make
- Doxygen for local documentation generation
- GitHub Actions and GitHub Pages for automatic online documentation publishing

The project has been tested with the compiler and tools available on macOS.

## Binary releases

Create and push a version tag to build and publish compressed binaries:

```bash
git tag v1.0.0
git push origin v1.0.0
```

The `Build and publish binaries` workflow also supports manual runs from the
repository's **Actions** tab. Every push to `main` creates downloadable
workflow artifacts. Tagged runs publish one asset for each supported
operating-system and architecture combination:

```text
grocery-linux-x64.tar.gz
grocery-linux-x86.tar.gz
grocery-linux-arm64.tar.gz
grocery-macos-x64.tar.gz
grocery-macos-arm64.tar.gz
grocery-windows-x64.tar.gz
grocery-windows-x86.tar.gz
grocery-windows-arm64.tar.gz
```

The archives contain the executable named for the matching platform and
architecture. Linux x86 and Windows x86 are 32-bit builds. Current macOS SDKs
no longer support linking 32-bit Intel (`i386`) applications, so macOS
releases target Intel 64-bit (`x64`) and Apple Silicon (`arm64`) only.

## Building

From the project root, run:

```bash
make
```

The release executable is created at:

```text
build/release/grocery
```

To build the debug executable without launching a debugger:

```bash
make build/debug/grocery
```

To build and launch the debug executable in LLDB or GDB:

```bash
make debug
```

The debug executable is created at:

```text
build/debug/grocery
```

You can also build the release target explicitly:

```bash
make release
```

To remove generated build files:

```bash
make clean
```

## Visual Studio

Visual Studio 2026 project files are included for Windows development:

```text
Grocery.sln
```

Open `Grocery.sln` in Visual Studio 2026, select `Debug` or `Release` and either
the `x64` or `ARM64` platform, and build the `Grocery` project. The
executable is written to:

```text
build\vs\<Platform>\<Configuration>\grocery.exe
```

The project uses the repository root as its working directory so
`CS210_Project_Three_Input_File.txt` is found when launched from Visual
Studio. The Visual Studio project is an additional build option; the
Makefile remains the command-line build system for macOS and Unix-like
environments. Visual Studio preserves each source directory in its
intermediate object paths so files with the same name, such as the four
`controller.cpp` files, receive unique intermediate object names and do not
collide during linking. After changing the project configuration, use
**Build → Clean Solution**, then **Build → Rebuild Solution**.

## Running

Run the application with:

```bash
make run
```

The program expects the input file to be available in the current working
directory. It creates or replaces `frequency.dat` in that same directory.

The interactive menu provides these options:

1. Find an item
2. List items and quantities
3. Print a histogram
4. Exit

You can also enter `q` at the main menu to quit. While searching for an item,
enter `q` to return to the main menu.

## Input and output

### Input file

`CS210_Project_Three_Input_File.txt` contains grocery item records. Each item
is represented as a separate line, for example:

```text
Apples
Broccoli
Apples
```

### Output file

`frequency.dat` is generated when the application starts. It contains the
serialized frequency report produced from the in-memory grocery store.

## Project structure

```text
.
├── include/                  Public header files
│   └── grocery/
│       ├── app/              Application orchestration
│       ├── data/             Storage, serialization, and presentation
│       ├── io/               File reading and writing
│       └── ui/               Menu and console dialogs
├── src/                      C++ implementations
├── main.cpp                  Program entry point
├── Makefile                  Build, run, clean, and documentation targets
├── CS210_Project_Three_Input_File.txt
├── frequency.dat
├── Doxyfile                  Doxygen configuration
└── .github/workflows/
    └── docs.yml              GitHub Pages documentation workflow
```

## Documentation

Generate the HTML documentation locally with:

```bash
make docs
```

The generated site is located at:

```text
docs/index.html
```

The published Doxygen documentation is available online at:

```text
https://dr3mro.github.io/CS-210-12997-Project_Three_Grocery_Frequency_Report/
```

[Open the published Doxygen documentation](https://dr3mro.github.io/CS-210-12997-Project_Three_Grocery_Frequency_Report/)

The `Publish Doxygen documentation` GitHub Actions workflow runs whenever
changes are pushed to the `main` branch. It also supports manual execution
from the repository's **Actions** tab. The workflow runs `make docs`, packages
the generated HTML, and deploys it to GitHub Pages.

To enable the online deployment, configure the repository settings as:

```text
Settings → Pages → Build and deployment → Source: GitHub Actions
```

Do not select **Deploy from a branch**. That mode makes GitHub run Jekyll
against the repository's `docs` directory instead of using the Doxygen HTML
artifact produced by the workflow.

The workflow must be selected from the repository's **Actions** tab and run
after changing the Pages source. If an Actions log contains:

```text
Source: /github/workspace/./docs
Error: No such file or directory ... /github/workspace/docs
```

GitHub is running the branch-based Jekyll publisher, not
`.github/workflows/docs.yml`. Change the Pages source to **GitHub Actions**,
save the setting, and rerun the `Publish Doxygen documentation` workflow. If
the workflow reports `Get Pages site failed` or `Not Found`, Pages has not
been enabled for the repository yet, or its source is still set to a branch.
A repository administrator must select **GitHub Actions** in the Pages
settings before the first deployment.

## Development commands

| Command | Description |
| --- | --- |
| `make` | Build the release executable |
| `make release` | Build the release executable explicitly |
| `make run` | Build and run the application |
| `make build/debug/grocery` | Build the debug executable |
| `make debug` | Build and launch the debug executable in LLDB or GDB |
| `make docs` | Generate Doxygen HTML documentation |
| `make clean` | Remove the `build` directory |

## License

This project was created for the SNHU CS-210 course.