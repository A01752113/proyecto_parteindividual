// PROYECTO INTEGRADOR EN EQUIPO 

// José Miguel García Gurtubay Moreno A01373750 
// Rodrigo Mejía Jiménez A01752113 
// Ana Patricia Islas Mainou A01751676

#include "producto.h"
#include "carrito.h"
#include "cliente.h"
#include "vendedor.h"
#include "sitioweb.h"
#include "envio.h"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){

    cout << "\nCASOS DE PRUEBA DE LAS CLASES\n\n";

    // DAR DE ALTA A UN VENDEDOR Y SU SITO WEB
    SitioWeb s1("Electronicos Apple", 0);
    Vendedor v1("Ramon Sanchez", "Calzada del Sol 34, Estado de México", "5556768735", "r.sanchez@gmail.com", "RAMONramon");
    
    // PRUEBAS DONDE SE CAMBIAN LOS ATRIBUTOS DEL VENDEDORS
cout << "\nSE QUIERE CAMBIAR EL TELEFONO DEL VENDEDORS\n";
    v1.setTelefono("5510047658"); // se cambia el telefono

    // DAR DE ALTA 4 PRODUCTOS 
    Producto p1("I Pad", 13568.50, "I Pad Pro de 516 GB y pantalla retina", 0, 0.14, 2, 3, 4);
    Producto p2("Air pods", 1600, "audifonos wireless airpods", 0, 0.001, 0.1, 0.2, 0.1);
    Producto p3("I Phone", 26470.99, "telefono I Phone X de 216 GB", 0, 0.2, 0.4, 0.2, 0.3);
    Producto p4("Mac Book Pro", 38654.98, "Mac Book Pro de 516 BG y pantalla retina, core-i 7", 0, 1.5, 0.8, 0.7, 0.3);

    // CAMBIAR EL PRECIO DEL PRODUCTO 2
    cout << "\nSE CAMBIA EL PRECIO A UNO DE LOS PRODUCTOS\n\n";
    cout << p1.getNombre() << ", precio anterior: " << to_string(p1.getPrecio()) << endl;
    p1.setPrecio(14056.60);
    cout << p1.getNombre() << ", nuevo precio: " << to_string(p1.getPrecio()) << endl;
    
    // AGREGAR PRODUCTOS AL INVENTARIO DEL VENDEDOR

    cout << "\nSE AGREGAN PRODUCTOS AL INVENTARIO DEL VENDEDOR Y AL SITIO WEB\n\n";
    v1.agregarProductosInventario(p1, s1);
    v1.agregarProductosInventario(p2, s1);
    v1.agregarProductosInventario(p3, s1);

    // ELIMINAR PRODUCTOS DEL INVENTARIO
    cout << "\nSE ELIMINAN PRODUCTOS DEL INVENTARIO DEL VENDEDOR\n\n";
    v1.eliminarProductosInventario(s1);
    
    // CONFIGURAR DESCUENTOS DEL SITIO WEB
    cout << "\nSE CONFIGURAN LOS DESCUENTOS DEL SITIO WEB\n\n";
    v1.configurarDescuentos(s1);
    
    // CLIENTE
    Cliente c1("Luis Perez","Homero 2, Polanco CDMX","5567091156","lperez@gmail.com","Luisito2020");
    
    cout << "\nSE INTENTA CAMBIAR LA CLAVE DE ACCESO DEL CLIENTE\n\n";
    c1.setClaveAcceso("LUISLUIS2020");

    cout << "\nSE AGREGA UN PRODUCTO AL CARRITO DEL CLIENTE\n\n";
    c1.agregarProductoCarrito(p1);
    c1.agregarProductoCarrito(p2);
    c1.agregarProductoCarrito(p3);

    cout << "\nSE REALIZA LA COMPRA\n\n";
    
    c1.realizarCompra();

    s1.verInventario();
    
    // PRUEBAS DE ENVIO
    cout << "\nPRUEBAS DE LA CLASE ENVIO\n\n";

    cout << "El costo del envio es: " << to_string(c1.getCostoEnvio(p1)) << endl;
}