cmake_minimum_required(VERSION 4.0)
project(Laboratorio_08_2024_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Laboratorio_08_2024_2 main.cpp
        Bibliotecas/FuncionesAuxiliares.cpp
        Bibliotecas/FuncionesAuxiliares.h
        Bibliotecas/Distrito.h
        Bibliotecas/Plato.h
        Bibliotecas/PlatoPedido.h
        Bibliotecas/Cliente.h)
