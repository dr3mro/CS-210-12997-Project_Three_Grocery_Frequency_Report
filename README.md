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

## Requirements

- A C++17-compatible compiler
- GNU Make
- Doxygen for local documentation generation
- GitHub Actions and GitHub Pages for automatic online documentation publishing

The project has been tested with the compiler and tools available on macOS.

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
docs/html/index.html
```

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