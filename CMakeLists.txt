cmake_minimum_required(VERSION 3.15)

# Nome do projeto
project(Calculadora VERSION 2.0.0 LANGUAGES CXX)

# Define o padrão C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Diretórios de include
include_directories(${PROJECT_SOURCE_DIR}/include)

# Encontrar todos os arquivos fonte da Clean Architecture
file(GLOB_RECURSE SOURCES 
    "src/domain/*.cpp"
    "src/usecases/*.cpp"
    "src/infrastructure/*.cpp"
    "src/presentation/*.cpp"
    "src/main.cpp"
)

# Criar o executável
add_executable(calculadora ${SOURCES})

# Definir diretório de saída para o executável
set_target_properties(calculadora PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${PROJECT_SOURCE_DIR}/bin"
)

# Opções de compilação
if(MSVC)
    target_compile_options(calculadora PRIVATE /W4)
else()
    target_compile_options(calculadora PRIVATE -Wall -Wextra -pedantic)
endif()

# Mensagem de status
message(STATUS "===================================")
message(STATUS "Configurando projeto: ${PROJECT_NAME}")
message(STATUS "Versão: ${PROJECT_VERSION}")
message(STATUS "Arquitetura: Clean Architecture")
message(STATUS "Padrão C++: ${CMAKE_CXX_STANDARD}")
message(STATUS "===================================")

# Exibir estrutura de camadas
message(STATUS "Camadas da Clean Architecture:")
message(STATUS "  - Domain (Entities)")
message(STATUS "  - Use Cases")
message(STATUS "  - Interfaces (Ports)")
message(STATUS "  - Infrastructure (Adapters)")
message(STATUS "  - Presentation (Adapters)")
message(STATUS "===================================")
