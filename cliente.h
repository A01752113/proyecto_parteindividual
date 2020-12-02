// CLASE CLIENTE

// Programada por Ana Patricia Islas Mainou 
// 28 de noviembre 2020

#ifndef CLIENTE_H
#define CLIENTE_H

#include "carrito.h"
#include "producto.h"

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

class Cliente{

    private:
        string nombre;
        string dirreccionEnvio;
        string telefono;
        string email;
        string claveAcceso;
        Carrito carritoCompras;
    
    public:

        // CONSTRUCTOR
        // default
        Cliente(){
            nombre ="";
            dirreccionEnvio ="";
            telefono = "";
            email ="";
            claveAcceso ="";

        }
        Cliente(string n, string d, string t, string e, string c){
            
            nombre = n;
            dirreccionEnvio = d;
            telefono = t;
            email = e;
            claveAcceso = c;
        }

        // SETTERS
        void setDireccion(string d){

            string clave;
            cout << "Escriba su calve de acceso: "; cin >> clave;
            
            if (clave == claveAcceso){
                dirreccionEnvio = d;
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
    
        // GETTERES
        string getClave(){return claveAcceso;}
        string getNombre(){return nombre;}
        string getDireccion(){return dirreccionEnvio;}
        
        // METODOS

        void agregarProductoCarrito(Producto p){
            carritoCompras.agregarProducto(p);
        }

        void eliminarProductoCarrito(SitioWeb& s){
            carritoCompras.eliminarProducto(s);
        }
        
        void realizarCompra(){

            carritoCompras.calcularTotal();
            carritoCompras.mostrarPrecioDesglosado();
            cout << "El total de la compra es de: " << to_string(carritoCompras.getTotal()) << endl;
            cout << "La forma de pago es: " << carritoCompras.getFormaPago() << endl;

        }

};

#endif