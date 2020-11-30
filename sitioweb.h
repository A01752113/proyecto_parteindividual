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
       vector <Producto> inventario;
       float descuento;

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

            inventario.push_back(p)
            cout << "El producto: " << p.getNombre() << " se agrego al inventario\n";

        }

        void actualizarEliminarInventario(Producto p){

           inventario.erase(inventario.find(p))
           cout << "El producto: " << p.getNombre() << " se elimino del inventario\n";

        }

        void verInventario(){

            for(int i = 0; i<inventario.size(); i++){

                cout << "\n INVENTARIO\n";
                cout << "Producto" << to_string(i+1) << endl;
                cout << "\n\tNombre" << inventario[i].getNombre() << endl;
           }
        }

}; //clase sitioweb

#endif