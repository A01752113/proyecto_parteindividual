// CLASE VENDEDOR

// Programada por Ana Patricia Islas Mainou 
// 28 de noviembre 2020

#ifndef VENDEDOR_H
#define VENDEDOR_H

#include "producto.h"
#include "sitioweb.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Vendedor{

    private:

        string nombre;
        string dirreccion;
        string telefono;
        string email;
        string claveAcceso;

        vector <Producto> inventario;

    public:
        Vendedor(){
            nombre = "";
            dirreccion = "";
            telefono = "";
            email = "";
            claveAcceso = "";
            inventario = {};
        }
        // CONSTRUCTOR
        Vendedor(string n, string d, string t, string e, string c){
            
            nombre = n;
            dirreccion = d;
            telefono = t;
            email = e;
            claveAcceso = c;
            inventario = {};

        }

        // SETTERS

        void setDireccion(string d){

            string clave;
            cout << "Escriba su calve de acceso: "; cin >> clave;
            
            if (clave == claveAcceso){
                dirreccion = d;
                cout << "Se cambio la informacion\n";
            }

            else{
                cout << "La clave de acceso no es valida, no es posible cambiar la inofrmación\n";
            }

        }

        void setTelefono(string t){

            string clave;
                cout << "Escriba su calve de acceso: "; cin >> clave;
                
                if (clave == claveAcceso){
                    telefono = t;
                    cout << "Se cambio la informacion\n";
                }

                else{
                    cout << "La clave de acceso no es valida, no es posible cambiar la inofrmación\n";
                }
                
        }

        void setEmail(string e){

            string clave;
                cout << "Escriba su calve de acceso: "; cin >> clave;
                
                if (clave == claveAcceso){
                    email = e;
                    cout << "Se cambio la informacion\n";
                }

                else{
                    cout << "La clave de acceso no es valida, no es posible cambiar la inofrmación\n";
                }
                
        }

        void setClaveAcceso(string c){

            string clave;
                cout << "Escriba su calve de acceso: "; cin >> clave;
                
                if (clave == claveAcceso){
                    claveAcceso = c;
                    cout << "Se cambio la informacion\n";
                }

                else{
                    cout << "La clave de acceso no es valida, no es posible cambiar la inofrmación\n";
                }
                
        }

        // GETTERS
        string getClave(){return claveAcceso;}
        string getNombre(){return nombre;}
        string getDireccion(){return dirreccion;}
        vector <Producto> getInventario(){return inventario;}

        // METODOS

        void configurarDescuentos(SitioWeb s){

            float descuento;
            cout << "Escribe el nuevo descuento en el sitio web: "; cin >> descuento;
            s.setDescuento(descuento);
        }

        void agregarProductosInventario(Producto p, SitioWeb& s){

            inventario.push_back(p);
            s.actualizarAgregarInventario(p);
        }

        void eliminarProductosInventario(SitioWeb& s){
            
            int n;
            s.verInventario();
            cout << "Escriba el numero del producto que desea eliminar\n"; cin >> n;
            
            s.actualizarEliminarInventario();
        }
};

#endif