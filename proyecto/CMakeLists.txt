cmake_minimum_required(VERSION 3.17)
project(proyecto)

set(CMAKE_CXX_STANDARD 14)

add_executable(proyecto main.cpp ProductoServicio.cpp ProductoServicio.h Cliente.cpp Cliente.h Empresa.cpp Empresa.h Transporte.cpp Transporte.h Fecha.cpp Fecha.h MetodoPago.cpp MetodoPago.h Solicitud.cpp Solicitud.h Tarjeta.cpp Tarjeta.h Transferencia.cpp Transferencia.h Efectivo.cpp Efectivo.h)