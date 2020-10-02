# MOOP_ATM_Project

MOOP class team project

---

#### **Requirements**

- MSVC v142

- Qt 5.15.1
  
  - MSVC 2019 64-bit
  
  - Qt Debug Information Files
  
  - Qt WebEngine
  
  - Sources *(optional)*

- CMake >= 3.16

- CLion >= 2020.1 

---

#### CLion configuration

Run/Debug Configurations -> Working directory `PATH_TO_QT_FOLDER\5.15.1\msvc2019_64\bin`

##### Settings

- Build, Execution, Deployment
  
  - Toolchains
    
    Add Visual Studio and select amd64 as Architecture. CLion should automatically find all required file paths.
  
  - CMake -> CMake options:  `PATH_TO_QT_FOLDER\5.15.1\msvc2019_64\`

##### QtDesigner integratation *(optional)*

             Settings -> Tools -> External Tools

                    Program: `PATH_TO_QT_FOLDER\5.15.1\msvc2019_64\bin\designer`

                    Arguments: `$FilePath$`

---
