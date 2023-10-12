# VsCode & Platformio
![](https://hack.depta.dev/uploads/upload_314d7020e9b723d1e35b947897c27788.png)

## Installation
### 1. VSCode
![](https://hack.depta.dev/uploads/upload_3bb7c9551a88732ab577e90b7d311ef4.png)
- An Electron Editor by Microsoft
- Open source and lightweight
- Highly configurable and versatile
- Plugins for various languages and tools
- Available on Windows, Mac, Linux

Download: https://code.visualstudio.com/

### 2. Platformio Extension
![](https://hack.depta.dev/uploads/upload_ea4fa86035e278fe73d72320c1026f88.png)
1. Select the Extensions tab
2. Enter "Platformio" in the search
3. Select Platformio from the search results
4. Install Platformio. VSCode will restart after the installation

## Create a project
1. Select Platformio Extension
2. Select PIO Home
3. Choose New Project
![](https://hack.depta.dev/uploads/upload_9a532915a17ab2fc2e862e44b2561278.PNG)

4. Choose Board & Framework
5. Wait for Platformio to set up the project

## Platformio Folder Structure
![](https://hack.depta.dev/uploads/upload_c5bca1067f233a19ddfeba6c2f673bc1.PNG)

1. **.pio** Folder for Platformio. This is where the framework, build files, libraries, and more reside.
2. **.vscode** Folder for VSCode. The C++ linter and extensions are linked here. Usually, you don't need to make changes here.
3. **include** Headers can be placed here.
4. **lib** Libraries can be placed here.
5. **src** C files should be placed here. The main.cpp must be in this folder.
6. **test** Unit tests can be placed here.
7. **platformio.ini** Configuration file for Platformio.

## platformio.ini
![](https://hack.depta.dev/uploads/upload_a582c83df56e60e0cd46c7080de2a24e.PNG)

The platformio.ini is the central configuration file for the project. Multiple environments (e.g. [env:esp32dev]) can be created to easily switch between production and debugging. The file format is in Yaml, so be careful with the spacing.

More info here: https://docs.platformio.org/en/latest/projectconf/index.html
https://docs.platformio.org/en/latest/envvars.html

## Build, Debug, Upload
![](https://hack.depta.dev/uploads/upload_bae93705a813d506fdfc3dbf35b46275.PNG)

1. PIO Home - Opens the Platformio homepage
2. Build - Build the project
3. Upload - Load the project onto the microcontroller
4. Clean - Clean up build files
5. Test - Start unit tests or call the testing environment
6. Serial Monitor - Serial communication
7. Terminal - A terminal loaded with PIO variables
8. Environment - Quickly switch the environment here
9. Serial Monitor Config - Settings for the serial monitor

More info here: https://docs.platformio.org/en/latest/projectconf/build_configurations.html

