# MIPS 16 bits Emulator - 2016
# Matheus Nogueira	<mnogueir@lakeheadu.ca>
#
#

cmake_minimum_required (VERSION 2.6)

# Modulos utilizados por esse sistema de build
# Os modulos se encontram na pasta cmake na raiz do projeto.
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake")

# Para definir modo de debug
# -Ddebug=OFF
# Padrão: Desativado
option(debug "Buiding in debug mode" ON)

# Define se o GNU G++ será utilizado para compilar o código
# -Dgnucompiler=ON
# Padrão: Ativado
option(gnucompiler "Building using GNU G++" ON)

# Tipo de build que será realizada
# Por padrão, o programa é compilado para modo release, porém, caso -Ddebug=ON é especificado,
# o modo de construção do programa é alterado para Debug
set(PROJECT_BUILD_TYPE Release)

#### Condições de configuração ####
# Área que usa as opções do usuário para construir o programa corretamente.
# Compilador que será utilizado
if (gnucompiler)
	SET (CMAKE_CXX_COMPILER				"/usr/bin/g++")
	SET (CMAKE_COMPILER_IS_GNUCXX ON)
else()
	SET (CMAKE_CXX_COMPILER             "/usr/bin/clang++")
endif()

# Ativa o modo de debug para a construção do programa
if (debug)
	MESSAGE (WARNING "DEBUG MODE ENABLED.")
	# Muda o tipo de build do programa
	set (PROJECT_BUILD_TYPE Debug)
	# Ativa a cobertura de testes
	# Ainda será incorporado ao build system
	# TODO: Consertar falha com CMP0037 no target do cmake
	# set (COVERAGE_TEST ON)
	# Define as flags de debug do compilador
	set (CMAKE_CXX_FLAGS "-g -O0 -Wall")
endif()


# Configuração do projeto em si
# Nessa área, o cmake irá utilizar todas as configurações utilizadas previamente para
# montar o makefile
#
# ============================ VOCÊ NÃO PRECISA ALTERAR DAQUI PARA BAIXO ==========================
#

# Define o nome do projeto
project (main)

# Define o tipo de build
set(CMAKE_BUILD_TYPE ${PROJECT_BUILD_TYPE})

# Inclui a pasta "include" como local para se procurar arquivos de cabeçalho
# do programa.
include_directories(include)

# Procura todos os arquivos com extensão cpp para ser compilados e gerar
# os arquivos objeto.
file (GLOB_RECURSE SOURCES source/unitcl/*.c)

# Cria uma biblioteca para ser linkada ao programa real, dessa forma, fica mais
# simples de executar os testes de unidade, se eles existirem.
add_library(unitcl ${SOURCES})

# Cria um executável para o projeto
# Esse executável só será o arquivo main, pois o restante do programa já foi
# compilado previamente, e foi gerado uma biblioteca com suas funções.
add_executable (main source/main.c)

# Linka o programa main com a biblioteca previamente gerada com o restante dos
# arquivos fonte.
TARGET_LINK_LIBRARIES (${PROJECT_NAME} unitcl)

if (COVERAGE_TEST)
	# Ativa a cobertura de testes
	INCLUDE(CodeCoverage)
	SETUP_TARGET_FOR_COVERAGE(coverage, mips_test, coverage)
endif()

##### DEFINIÇÂO DAS VARIAVEIS DO CMAKE #####
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
