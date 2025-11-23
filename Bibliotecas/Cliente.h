//
// Created by Gonzalo on 14/11/2025.
//

#ifndef LABORATORIO_08_2024_2_CLIENTE_H
#define LABORATORIO_08_2024_2_CLIENTE_H
struct Cliente {
    int dni;
    char *nombre;
    struct Distrito distrito;
    struct PlatoPedido pedidos[30];
    //este es un arreglo//
    int cantidadPedidos;
    double montoTotal;
};
#endif //LABORATORIO_08_2024_2_CLIENTE_H