// PROYECTO INTEGRADOR EN EQUIPO 

// José Miguel García Gurtubay Moreno A01373750 
// Rodrigo Mejía Jiménez A01752113 
// Ana Patricia Islas Mainou A01751676

#include "producto.h"
#include "carrito.h"
#include "cliente.h"
#include "vendedor.h"
#include "sitioweb.h"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

int main(){

    // DAR DE ALTA 4 PRODUCTOS PARA EL VENDEDOR
    Producto p1("I Pad", 13568.50, "I Pad Pro de 516 GB y pantalla retina", 0, 0.14, 2, 3, 4);
    Producto p2("Air pods", 1600, "audifonos wireless airpods", 0, 0.001, 0.1, 0.2, 0.1);
    Producto p3("I Phone", 26470.99, "telefono I Phone X de 216 GB", 0, 0.2, 0.4, 0.2, 0.3);
    Producto p4("Mac Book Pro", 38654.98, "Mac Book Pro de 516 BG y pantalla retina, core-i 7", 0, 1.5, 0.8, 0.7, 0.3);

    vector <Producto> lista1 = {p1, p2, p3, p4};

    SitioWeb s1("Electronicos Apple", 0);
    Vendedor v1("Ramon Sanchez", "Calzada del Sol 34, Estado de México", "5556768735", "r.sanchez@gmail.com", "RAMONramon");


    v1.agregarProductosInventario(lista1, s1);
    
    // DAR DE ALTA A UN VENDEDOR

    return 0;
}