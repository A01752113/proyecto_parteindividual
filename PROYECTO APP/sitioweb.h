// CLASE SITIO WEB

// Programada por Rodrigo Mejía Jiménez
// 28 de noviembre 2020

#ifndef SITIOWEB_H
#define SITIOWEB_H

#include "producto.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class SitioWeb{

    private:

       string nombre;
       float descuento;
       vector <Producto> inventario;

    public:

        // constructor
        SitioWeb(string n, float d){
            
            nombre = n;
            inventario = {};
            descuento = d;

        }
        // setter
        void setDescuento(float d){descuento = d;}

        // getter
        float getDescuento(){return descuento;}
        
        // metodos
        void actualizarAgregarInventario(Producto p){

            inventario.push_back(p);
            cout << "El producto: " << p.getNombre() << " se agrego al inventario\n";

        }

        void actualizarEliminarInventario(){

           cout << "El producto se eliminaria del inventario\n";
           cout << "NOTA: NOS COMENTO QUE LO DEJARAMOS ASI POR EL ITERADOR\n";

        }

        void verInventario(){
            
            cout << "\n INVENTARIO\n";
            for(int i = 0; i<inventario.size(); i++){

                cout << "Producto: " << to_string(i) << endl;
                cout << "\tNombre: " << inventario[i].getNombre() << endl;
           }
        }

}; //clase sitioweb

#endif