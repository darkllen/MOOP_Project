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

- MySQL Connector C++ 8.0.22: 

      https://cdn.mysql.com//Downloads/Connector-C++/mysql-connector-c++-8.0.22-winx64.msi

     Installing: Custom -> Install only "New X DevAPI connector"
---

#### CLion configuration

- Settings

    - Build, Execution, Deployment
  
        - Toolchains
    
              Add Visual Studio and select amd64 as Architecture. CLion should automatically find all required file paths.
  
  - CMake -> CMake options ({} - user-defined variables!): 
  
        -DQT_BIN_PATH:PATH={PATH_TO_QT_DIR}\5.15.1\msvc2019_64
        -DMYSQL_CONN_PATH:PATH={PATH_TO_MYSQL_CPP_CONNECTOR_DIR}

#### QtDesigner integratation *(optional)*

 - Settings -> Tools -> External Tools

       Program: `{PATH_TO_QT_DIR}\5.15.1\msvc2019_64\bin\designer`
       Arguments: `$FilePath$`

---
