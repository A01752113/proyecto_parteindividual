// CLASE CARRITO

// Programada por Rodrigo Mejía Jiménez
// 28 de noviembre 2020

#ifndef CARRITO_H
#define CARRITO_H

#include "producto.h"
#include "envio.h" 
#include "sitioweb.h"

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

using namespace std;

class Carrito{

    private:

      vector <Producto> producto;
      int numeroProductos;
      string formaPago;
      float costoEnvio;
      float costoProductos;
      float total;

    public:

      // default
      Carrito(){

        numeroProductos = 0;
        formaPago = "tarjeta";
        costoEnvio = 0;
        costoProductos = 0;
        total = 0;
        producto = {}; 
      }

      // setter
      void setFormaPago(string f){formaPago = f;}

      // getter
      float getTotal(){return total;}
      string getFormaPago(){return formaPago;}

      // metodos
      void mostrarPrecioDesglosado(){

        cout << "\nPRECIOS DESGLOSADOS\n\n";
        cout << "El numero de productos en el carrito es de: " << to_string(numeroProductos) << endl;

        for (int i = 0; i < numeroProductos; i++){
          
          cout << "Producto: " << producto[i].getNombre() << endl;
          cout << "Precio: " << to_string(producto[i].getPrecio()) << endl;
          cout << " \n";

        }
      }

      void agregarProducto(Producto p){

        producto.push_back(p);
        numeroProductos ++;

        cout << "Se ha agreagado el producto: " << p.getNombre() << " al carrito\n";

      }

      void eliminarProducto(SitioWeb& s){
        
        int n;
        s.verInventario();

        cout << "El producto se eliminaria del carrito\n";
        cout << "NOTA: NOS COMENTO QUE LO DEJARAMOS ASI POR EL ITERADOR\n";

      }

      void costoProductosAplicandoDescuentos(){

        float precio = 0, descuento = 0, tot = 0;

        for (int i = 0; i < numeroProductos; i++){

          precio = producto[i].getPrecio();
          descuento = producto[i].getDescuento() * precio;

          tot = tot + precio + descuento;
          cout << tot << endl;

        }
        costoProductos = tot;

      }
      
      void precioEnvio(Envio& env, Producto p){

        costoEnvio = env.getCostoEnvio(p);
      }

      void precioEnvio(){costoEnvio = 0;}

      void calcularTotal(){

        costoProductosAplicandoDescuentos();
        precioEnvio();
        total = costoEnvio + costoProductos;
      }

};//clase carrito

#endif

