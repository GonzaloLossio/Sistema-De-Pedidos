//
// Created by Gonzalo on 14/11/2025.
//
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

#include "Distrito.h"
#include "Plato.h"
#include "PlatoPedido.h"
#include "Cliente.h"
#include "FuncionesAuxiliares.h"


#define NO_ENCONTRADO -1
void cargarPlatosOfrecidos(struct Plato *arrPlatos,int &cantPlatos) {
    ifstream archPlatosOfrecidos("ArchivosDeDatos/PlatosOfrecidos.csv",ios::in);
    if (not archPlatosOfrecidos.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeDatos/PlatosOfrecidos.csv"<<endl;
        exit(1);
    }
    cantPlatos=0;
    char car;
    while (true) {
        arrPlatos[cantPlatos].codigo=leeCadenaExactaConDeLim(archPlatosOfrecidos,',');
        if (archPlatosOfrecidos.eof()) break;
        arrPlatos[cantPlatos].descripcion=leeCadenaExactaConDeLim(archPlatosOfrecidos,',');
        archPlatosOfrecidos>>arrPlatos[cantPlatos].precio>>car;
        arrPlatos[cantPlatos].categoria=leeCadenaExactaConDeLim(archPlatosOfrecidos,'\n');
        arrPlatos[cantPlatos].cantidad++;
        cantPlatos++;
    }
}
char *leeCadenaExactaConDeLim(ifstream&arch,char carLim) {
    char *ptr,cadena[100];
    arch.getline(cadena,100,carLim);
    if (arch.eof()) return nullptr;
    ptr=new char [strlen(cadena)+1];
    strcpy(ptr,cadena);
    return ptr;
}
void cargarDistritosDeLima(struct Distrito *arrDistritos,int&cantDistritos) {
    ifstream archDistritos("ArchivosDeDatos/Distritos.csv",ios::in);
    if (not archDistritos.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeDatos/Distritos.csv"<<endl;
        exit(1);
    }
    cantDistritos=0;
    while (true) {
        arrDistritos[cantDistritos].codigo=leeCadenaExactaConDeLim(archDistritos,',');
        if (archDistritos.eof()) break;
        arrDistritos[cantDistritos].nombre=leeCadenaExactaConDeLim(archDistritos,',');
        arrDistritos[cantDistritos].ubicacion=leeCadenaExactaConDeLim(archDistritos,'\n');
        cantDistritos++;
    }
}
void cargarClientes(struct Cliente *arrClientes,int&cantClientes) {
    ifstream archClientes("ArchivosDeDatos/Clientes.csv",ios::in);
    if (not archClientes.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeDatos/Clientes.csv"<<endl;
        exit(1);
    }
    cantClientes=0;
    char car;
    while (true) {
        archClientes>>arrClientes[cantClientes].dni;
        if (archClientes.eof()) break;
        archClientes>>car;
        arrClientes[cantClientes].nombre=leeCadenaExactaConDeLim(archClientes,',');
        arrClientes[cantClientes].distrito.codigo=leeCadenaExactaConDeLim(archClientes,'\n');
        cantClientes++;
    }
}
void imprimirReporteSimplePlatosOfrecidos(struct Plato *arrPlatos,int cantPlatos) {
   ofstream archReporte("ArchivosDeReporte/ReporteSimplePlatosOfrecidos.txt",ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeReporte/ReporteSimplePlatosOfrecidos.txt"<<endl;
        exit(1);
    }
    archReporte<<fixed<<setprecision(2);
    archReporte<<setw(50)<<"LISTADO DE INFORMACION DE LOS PLATOS"<<endl;
    archReporte<<setw(12)<<"CODIGO"<<setw(12)<<"NOMBRE"<<setw(12)<<"PRECIO"<<setw(12)<<"CATEGORIA"<<endl;
    for (int i=0;i<cantPlatos;i++) {
        archReporte<<setw(12)<<' '<<left<<setw(10)<<arrPlatos[i].codigo<<right<<setw(12)<<' '<<left<<setw(20)<<
            arrPlatos[i].descripcion<<right<<setw(15)<<arrPlatos[i].precio<<setw(12)<<' '<<left<<setw(15)<<
                arrPlatos[i].categoria<<left<<endl;
    }
}
void imprimirReporteSimpleDistritos(struct Distrito *arrDistritos,int cantDistritos) {
    ofstream archReporte("ArchivosDeReporte/ReporteSimpleDistritosDeLima.txt",ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeReporte/ReporteSimpleDistritosDeLima.txt"<<endl;
        exit(1);
    }
    archReporte<<setw(50)<<"LISTADO DE INFORMACION DE LOS DISTRITOS"<<endl;
    archReporte<<setw(12)<<"CODIGO"<<setw(12)<<"NOMBRE"<<setw(12)<<"UBICACION"<<endl;
    for (int i=0;i<cantDistritos;i++) {
        archReporte<<setw(12)<<' '<<left<<setw(10)<<arrDistritos[i].codigo<<right<<setw(12)<<' '<<
            left<<setw(20)<<arrDistritos[i].nombre<<right<<setw(12)<<' '<<left<<setw(15)<<
                arrDistritos[i].ubicacion<<right<<endl;
    }
}
void imprimirReporteSimpleClientes(struct Cliente *arrClientes,int&cantClientes) {
    ofstream archReporte("ArchivosDeReporte/ReporteSimpleClientes.txt",ios::out);
    if (not archReporte.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeReporte/ReporteSimpleClientes.txt"<<endl;
        exit(1);
    }
    archReporte<<setw(50)<<"LISTADO DE INFORMACION DE LOS CLIENTES"<<endl;
    archReporte<<setw(12)<<"DNI"<<setw(12)<<"NOMBRE"<<setw(12)<<"DISTRITO"<<endl;
    for (int i=0;i<cantClientes;i++) {
        archReporte<<setw(15)<<arrClientes[i].dni<<setw(12)<<' '<<
            left<<setw(20)<<arrClientes[i].nombre<<right<<setw(12)<<' '<<left<<setw(15)<<
                arrClientes[i].distrito.codigo<<right<<endl;
    }
}
void cargarPedidosRealizados(struct Cliente *arrClientes,int cantClientes,struct Plato*arrPlatos,int cantPlatos) {
    ifstream archPedidosRealizados("ArchivosDeDatos/PedidosRealizados.txt",ios::in);
    if (not archPedidosRealizados.is_open()) {
        cout<<"Error al abrir el archivo ArchivosDeDatos/PedidosRealizados.txt"<<endl;
        exit(1);
    }
    int codigoPedido,dni,idCliente,idPlato;
    char *codigoPlato;
    while (true) {
        archPedidosRealizados>>codigoPedido;
        if (archPedidosRealizados.eof()) break;
        archPedidosRealizados>>dni;
        idCliente=buscarIdCliente(arrClientes,cantClientes,dni);
        if (idCliente!=NO_ENCONTRADO) {
            archPedidosRealizados>>ws;
            codigoPlato=leeCadenaExactaConDeLim(archPedidosRealizados,' ');
            idPlato=buscarIdPlato(arrPlatos,codigoPlato,cantPlatos);
            if (idPlato!=NO_ENCONTRADO) {
                //actualizamos los valores que nos faltan del arreglo//
                int i=arrClientes[idCliente].cantidadPedidos;
                arrClientes[idCliente].pedidos[i].codigoPedido=codigoPedido;
                arrClientes[idCliente].pedidos[i].codigoPlato=codigoPlato;
                arrClientes[idCliente].pedidos[i].descripcion=arrPlatos[idPlato].descripcion;
                archPedidosRealizados>>arrClientes[idCliente].pedidos[i].cantidad;
                arrClientes[idCliente].pedidos[i].precio=arrPlatos[idPlato].precio;
                arrClientes[idCliente].pedidos[i].subTotal=arrClientes[idCliente].pedidos[i].cantidad*arrPlatos[idPlato].precio;
                arrClientes[idCliente].cantidadPedidos++;
                arrClientes[idCliente].montoTotal+=arrClientes[idCliente].pedidos[i].subTotal;
            }else {
                while (archPedidosRealizados.get()!='\n');
            }
        }else {
            while (archPedidosRealizados.get()!='\n');
        }
    }
}
int buscarIdCliente(struct Cliente *arrClientes,int cantClientes,int dni) {
    for (int i=0;i<cantClientes;i++) {
        if (arrClientes[i].dni==dni) return i;
    }
    return NO_ENCONTRADO;
}
int buscarIdPlato(struct Plato *arrPlatos,char*codigoPlato,int cantPlatos) {
    for (int i=0;i<cantPlatos;i++) {
        if (strcmp(arrPlatos[i].codigo,codigoPlato)==0) return i;
    }
    return NO_ENCONTRADO;
}
void ordenarAscendenteClientesPorNombre(struct Cliente*arrClientes,int cantClientes) {
    for (int i=0;i<cantClientes-1;i++) {
        for (int j=i+1;j<cantClientes;j++) {
            if (strcmp(arrClientes[i].nombre,arrClientes[j].nombre)>0) {
                cambiarStruct(arrClientes[i],arrClientes[j]);
            }
        }
    }
}
void cambiarInt(int &datoI,int &datoJ ) {
    int aux=datoI;
    datoI=datoJ;
    datoJ=aux;
}
void cambiarCC(char*&datoI ,char* &datoJ ) {
    char* aux=datoI;
    datoI=datoJ;
    datoJ=aux;
}
void cambiarStruct(struct Cliente & datoI ,struct Cliente &datoJ ) {
    struct Cliente aux=datoI;
    datoI=datoJ;
    datoJ=aux;
}
void cambiarDouble(double &datoI ,double &datoJ ) {
    double aux=datoI;
    datoI=datoJ;
}
void ordenarPlatosPedidos(struct Cliente *arrClientes,int cantClientes) {
    for (int k=0;k<cantClientes;k++) {
        int n=arrClientes[k].cantidadPedidos;
        for (int i=0;i<n-1;i++) {
            for (int j=i+1;j<n;j++) {
                if (arrClientes[k].pedidos[i].codigoPedido>arrClientes[k].pedidos[j].codigoPedido or
                    (arrClientes[k].pedidos[i].codigoPedido==arrClientes[k].pedidos[j].codigoPedido) and
                    (strcmp(arrClientes[k].pedidos[i].codigoPlato,arrClientes[k].pedidos[j].codigoPlato)<0)) {
                    cambiarInt(arrClientes[k].pedidos[i].codigoPedido,
                        arrClientes[k].pedidos[j].codigoPedido);
                    cambiarInt(arrClientes[k].pedidos[i].cantidad,
                        arrClientes[k].pedidos[j].cantidad);
                    cambiarCC(arrClientes[k].pedidos[i].codigoPlato,arrClientes[k].pedidos[j].codigoPlato);
                    cambiarCC(arrClientes[k].pedidos[i].descripcion,arrClientes[k].pedidos[j].descripcion);
                    cambiarDouble(arrClientes[k].pedidos[i].precio,arrClientes[k].pedidos[j].precio);
                    cambiarDouble(arrClientes[k].pedidos[i].subTotal,arrClientes[k].pedidos[j].subTotal);
                }
            }
        }
    }
}