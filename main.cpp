#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Bibliotecas/Distrito.h"
#include "Bibliotecas/Plato.h"
#include "Bibliotecas/PlatoPedido.h"
#include "Bibliotecas/Cliente.h"
#include  "Bibliotecas/FuncionesAuxiliares.h"

#define TAM_PLATOS 150
#define TAM_CLIENTES 150
#define TAM_DISTRITOS 70
int main() {
    struct Distrito arrDistritos[TAM_DISTRITOS];
    struct Plato arrPlatos[TAM_PLATOS]{};
    struct Cliente arrClientes[TAM_CLIENTES]{};
    int cantDistritos,cantPlatos,cantClientes;
    cargarPlatosOfrecidos(arrPlatos,cantPlatos);
    cargarDistritosDeLima(arrDistritos,cantDistritos);
    cargarClientes(arrClientes,cantClientes);
    imprimirReporteSimplePlatosOfrecidos(arrPlatos,cantPlatos);
    imprimirReporteSimpleDistritos(arrDistritos,cantDistritos);
    imprimirReporteSimpleClientes(arrClientes,cantClientes);
    cargarPedidosRealizados(arrClientes,cantClientes,arrPlatos,cantPlatos);
    ordenarAscendenteClientesPorNombre(arrClientes,cantClientes);
    ordenarPlatosPedidos(arrClientes,cantClientes);
    return 0;
}