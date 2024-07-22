# Building Neural Networks from Scratch in C++

Following [Building Neural Networks from Scratch](https://www.youtube.com/playlist?list=PLPTV0NXA_ZSj6tNyn_UadmUeU3Q3oR-hu) by [Vizuara](https://www.youtube.com/@vizuara), this project aims to implement the concepts in C++. The goal is to learn the foundational elements of deep learning frameworks by building one from the ground up. This endeavor not only enhances understanding of neural networks but also explores the possibility of creating a package that can be imported into C++ or Python applications.

## Requirements

- **GCC**: Ensure you have GCC installed on your system to compile the C++ code. You can check if GCC is installed by running `gcc --version` in your terminal. If you need to install GCC, visit [GCC's official page](https://gcc.gnu.org/install/).

- **Eigen**: This project uses the Eigen library for linear algebra operations. Download Eigen from [Eigen's official website](http://eigen.tuxfamily.org/index.php?title=Main_Page) and extract it to a known location on your system.

- **gnuplot**: This project utilizes gnuplot for generating plots and visualizing data. Ensure you have gnuplot installed on your system. You can check if gnuplot is installed by running `gnuplot --version` in your terminal. If you need to install gnuplot, visit [gnuplot's official page](http://www.gnuplot.info/) for installation instructions.


## Setting up in Visual Studio Code

The repository includes Visual Studio Code configuration files to simplify the build and debug process:

- `.vscode/launch.json`: Configures the debugger settings. It allows you to launch your compiled C++ programs directly from Visual Studio Code and debug them.

- `.vscode/tasks.json`: Defines build tasks for compiling the C++ code. It includes the necessary commands and flags for invoking the GCC compiler, including paths to any dependencies like the Eigen library.

To use these configurations, simply open the project folder in Visual Studio Code. You can then build the project by running the predefined build task (Terminal > Run Build Task...) and debug by starting a debug session (Run > Start Debugging).

Including these files in the repository ensures that anyone cloning the project can get up and running with the same setup, making it easier to contribute or learn from the project.

## How to Contribute

We welcome contributions! If you're interested in helping improve this project, please feel free to fork the repository, make your changes, and submit a pull request. If you have any questions or suggestions, feel free to open an issue in the repository.

## License

This project is open-sourced under the MIT license. See the [LICENSE](https://github.com/naga-k/low_level_nn/blob/main/LICENSE) file for more details.
