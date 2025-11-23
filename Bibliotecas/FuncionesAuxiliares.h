//
// Created by Gonzalo on 14/11/2025.
//

#ifndef LABORATORIO_08_2024_2_FUNCIONESAUXILIARES_H
#define LABORATORIO_08_2024_2_FUNCIONESAUXILIARES_H
void cargarPlatosOfrecidos(struct Plato *arrPlatos,int &cantPlatos);
char *leeCadenaExactaConDeLim(ifstream&arch,char carLim);
void cargarDistritosDeLima(struct Distrito *arrDistritos,int&cantDistritos);
void cargarClientes(struct Cliente *arrClientes,int&cantClientes);
void imprimirReporteSimplePlatosOfrecidos(struct Plato *arrPlatos,int cantPlatos);
void imprimirReporteSimpleDistritos(struct Distrito *arrDistritos,int cantDistritos);
void imprimirReporteSimpleClientes(struct Cliente *arrClientes,int&cantClientes);
void cargarPedidosRealizados(struct Cliente *arrClientes,int cantClientes,struct Plato*arrPlatos,int cantPlatos);
int buscarIdCliente(struct Cliente *arrClientes,int cantClientes,int dni) ;
int buscarIdPlato(struct Plato *arrPlatos,char*codigoPlato,int cantPlatos);
void ordenarAscendenteClientesPorNombre(struct Cliente*arrClientes,int cantClientes);
void cambiarInt(int &datoI,int &datoJ );
void cambiarCC(char*&datoI ,char* &datoJ ) ;
void cambiarStruct(struct Cliente & datoI ,struct Cliente &datoJ );
void cambiarDouble(double &datoI ,double &datoJ );
void ordenarPlatosPedidos(struct Cliente *arrClientes,int cantClientes);
#endif //LABORATORIO_08_2024_2_FUNCIONESAUXILIARES_H