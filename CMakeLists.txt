cmake_minimum_required(VERSION 3.28)
project(ED2___AV2)

# Definir a arquitetura e o padrão C++
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -m64")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64")

# Adicionar o executável
add_executable(ED2___AV2
        main.c
        Q1.c
        Q2.c
        Q3.c
        Q4.c)

# Incluir diretórios, se necessário
# include_directories(${PROJECT_SOURCE_DIR}/include)

# Link de bibliotecas, se necessário
# target_link_libraries(ED2___AV2 <libraries>)

# Instalação do script para o diretório: C:/Users/gabri/OneDrive/Documentos/ED2 - AV2/ED2 - AV2
set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/ED2___AV2")
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Definir o nome da configuração de instalação
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
    if(BUILD_TYPE)
        string(REGEX REPLACE "^[^A-Za-z0-9_]+" "" CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
    else()
        set(CMAKE_INSTALL_CONFIG_NAME "Debug")
    endif()
    message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Definir o componente que está sendo instalado
if(NOT CMAKE_INSTALL_COMPONENT)
    if(COMPONENT)
        message(STATUS "Install component: \"${COMPONENT}\"")
        set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
    else()
        set(CMAKE_INSTALL_COMPONENT)
    endif()
endif()

# Verificar se esta instalação é resultado de um crosscompile
if(NOT DEFINED CMAKE_CROSSCOMPILING)
    set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Definir permissões padrão do diretório de instalação
if(NOT DEFINED CMAKE_OBJDUMP)
    set(CMAKE_OBJDUMP "C:/Program Files/JetBrains/CLion 2023.3.4/bin/mingw/bin/objdump.exe")
endif()

if(CMAKE_INSTALL_COMPONENT)
    set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
    set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/Users/gabri/OneDrive/Documentos/ED2 - AV2/ED2 - AV2/cmake-build-debug/${CMAKE_INSTALL_MANIFEST}" "${CMAKE_INSTALL_MANIFEST_CONTENT}")
