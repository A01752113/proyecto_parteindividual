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

void menu(){
    string tipo;
    cout << "PARA SALIR DEL PROGRAMA ESCRIBE  LA LETRA <X>, DA ENTER Y VUELVE A PRESIONAR LA LETRA <X>\n";
    cout << "¿Vendedor o Cliente?\n";
    cin >> tipo;
    if (tipo == "Vendedor" || tipo == "vendedor" || tipo == "VENDEDOR")
    {
        cout << "\nMENU VENDEDOR\n";
        cout << "8 Dar de alta vendedor.\n";
        cout << "9 Agregar producto.\n";
        cout << "10 Eliminar producto de inventario.\n";
        cout << "11 Configurar descuentos.\n";
        cout << "0  Salir.\n";
    }
    else if (tipo == "Cliente" || tipo == "cliente" || tipo == "CLIENTE")
    {
        cout << "\nMENU CLIENTE\n";
        cout << "1 Dar de alta cliente.\n";
        cout << "2 Agregar producto al carrito.\n";
        cout << "3 Eliminar producto del carrito. \n";
        cout << "4 Realizar compra.\n";
        cout << "5 Configurar forma de pago.\n";
        cout << "6 Ver precio desglosado y total.\n";
        cout << "7 Consultar Track ID.\n";
        cout << "0 Salir.\n";
    }
    cout << "\nSelecciona una opcion.\n";
}

vector<Cliente>& altaCliente(vector<Cliente>& clientes){

    string nombre;
    string direccion;
    string telefono;
    string email;
    string clavecliente;
    Cliente cliente;

    cout << "Ingresa el nombre del usuario, sin espacios, usa guines bajos\n";
    cin >> nombre;
    cout << "Ingresa la direccion de envio, sin espacios, usa guines bajos\n",
    cin >> direccion;
    cout << "Ingresa un numero telefonico,\n";
    cin >> telefono;
    cout << "Ingresa un email\n";
    cin >> email;
    cout << "Ingresa  una clave de acceso, sin espacios, usa guines bajos\n";
    cin >> clavecliente;

    cliente = Cliente{nombre, direccion, telefono, email, clavecliente};
    clientes.push_back(cliente);
    
    
    return clientes;
}

vector<Vendedor>& altaVendedor(vector<Vendedor>& vendedores){

    string nombre;
    string direccion;
    string telefono;
    string email;
    string clavevendedor;
    vector <Producto> inventario;
    Vendedor vendedor;

    cout << "Ingresa el nombre del usuario, sin espacios, usa guines bajos\n";
    cin >> nombre;
    cout << "Ingresa la direccion, sin espacios, usa guines bajos\n",
    cin >> direccion;
    cout << "Ingresa un numero telefonico\n";
    cin >> telefono;
    cout << "Ingresa un email\n";
    cin >> email;
    cout << "Ingresa una clave de acceso, sin espacios, usa guines bajos\n";
    cin >> clavevendedor;

    vendedor = Vendedor{nombre, direccion, telefono, email, clavevendedor};
    vendedores.push_back(vendedor);
    
    
    return vendedores;
}

vector<Carrito>& inicializarCarrito(vector<Carrito>& carritos){
    Carrito carrito;
    carritos.push_back(carrito);
    return carritos;
}

vector<Envio>& empezarEnvio(vector<Envio>& envios){
    Envio envio;
    envios.push_back(envio);
    return envios;
}
   //Dar de alta Productor
    //Contructor Producto (nombre, precio, descripcion, descuento, peso, dimensionX, dimensionY, dimensionZ)
vector<Producto>& crearProducto(vector<Producto>& productos){
    Producto producto;
    string nombre;
    float precio;
    string descripcion;
    float descuento;
    float peso;
    float dimensionX;
    float dimensionY;
    float dimensionZ;
    cout << "Ingresa el nombre del producto\n";
    cin >> nombre;
    cout << "Ingresa el precio del producto\n";
    cin >> precio;
    cout << "Ingresa la descripcion del producto\n";
    cin >> descripcion;
    cout << "Ingresa el descuento del producto\n";
    cin >> descuento;
    cout << "Ingresa el peso del producto\n";
    cin >> peso;
    cout << "Ingresa el largo del producto\n";
    cin >> dimensionX;
    cout << "Ingresa el ancho del producto\n";
    cin >> dimensionY;
    cout << "Ingresa la profundidad del producto\n";
    cin >> dimensionZ;
    producto = Producto{nombre, precio, descripcion, descuento,  peso, dimensionX, dimensionY, dimensionZ};
    productos.push_back(producto);
    return productos;
}
main()
{
    vector<Cliente> carteraClientes;
    vector<Producto> listaProductos;
    vector<Vendedor> vendedores;
    vector<Envio> listaEnvios;
    vector<Carrito> listaCarritos;


    //Dar de alta Sitios Web
    //Constructor SitioWeb (nombre sitio web, descuento)
    SitioWeb amazon{"amazon.com",0};
    SitioWeb mercadolibre{"mercadolibre.com.mx", 5};
    SitioWeb ebay{"ebay.com", 0};
    SitioWeb oficial{"oficial.com",10};
    SitioWeb wish{"wish.com",7};

    //Dar de alta Productor
    //Contructor Producto (nombre, precio, descripcion, descuento, peso, dimensionX, dimensionY, dimensionZ)
    Producto chamarra("chamarra", 500,"Chammara azul", 0, 0.2, 2,3,4);
    Producto pantalones("pantalones", 500,"Pantalones azules", 0, 0.6, 3,4,3);

    listaProductos.push_back(chamarra);
    listaProductos.push_back(pantalones);

    string tipoEnvio;
    string formaPago;
    string clavecliente;
    string clavevendedor;
    string nuevo;
    int opcion;
    int numProducto;

    while (opcion != 0)
    {
        menu();
        cin >> opcion;

        switch (opcion)
        {
        case 1:  //Dar de alta cliente
            carteraClientes = altaCliente(carteraClientes);
            cout << "Cliente aceptado\n";
            listaCarritos = inicializarCarrito(listaCarritos);
            cout << "Carrito creado\n";
            listaEnvios = empezarEnvio(listaEnvios);
            cout << "Envio registrado, track id  generado.\n";
            break;

        case 2:  //Agregar producto al carrito
            for (int i = 0; i < listaProductos.size(); i++)
                {
                    cout << to_string(i + 1) << listaProductos[i].getNombre() << endl;
                }    
                cout << "¿Que numero de producto deseas agregar al carrito?\n";
                cin >> numProducto;
                cout << "Ingresa tu clave de cliente\n";
                cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave())
                    {
                        carteraClientes[i].agregarProductoCarrito(listaProductos[numProducto]);
                        cout << "El producto ha sido agregado correctamente al carrito\n";
                    }
                }               
            break;

        case 3:  //Eliminar producto del carrito
            for (int i = 0; i < listaProductos.size(); i++)
                {
                    cout << to_string(i + 1) << listaProductos[i].getNombre() << endl;
                }    
                cout << "¿Que numero de producto deseas eliminar al carrito?\n";
                cin >> numProducto;
                cout << "Ingresa tu clave de cliente\n";
                cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave())
                    {
                        carteraClientes[i].eliminarProductoCarrito(amazon);
                        cout << "El producto ha sido eliminado correctamente del carrito\n";
                    }
                }
            break;

        case 4:  //Realizar compra
            cout << "Ingresa tu clave de cliente\n";
            cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave())
                    {   
                        cout << "Tipo de envio (gratis, pago, express).\n";
                        cin >> tipoEnvio;
                        listaEnvios[i].setTipoEnvio(tipoEnvio);
                        carteraClientes[i].realizarCompra();
                        cout << "Compra realizada correctamente.\n";
                    }
                }
            break;

        case 5:  //Configurar forma de pago
            cout << "¿Que forma de pago deseas?";
            cin >> formaPago;
            cout << "Ingresa tu clave de cliente\n";
                cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave())
                    {
                        listaCarritos[i].setFormaPago(formaPago);
                        cout << "Compra realizada correctamente.\n";
                    }
                }
            break;

        case 6:  //Ver precio desglosado y total
            cout << "Ingresa tu clave de cliente\n";
                cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave())
                    {
                        listaCarritos[i].calcularTotal();
                        listaCarritos[i].mostrarPrecioDesglosado();
                        cout << listaCarritos[i].getTotal() << endl;
                    }
                }    
            break;

        case 7:  //Consultar Track ID
            cout << "Ingresa tu clave de cliente\n";
                cin >> clavecliente;
                for (int i = 0; i < carteraClientes.size(); i++)
                {
                    if (clavecliente == carteraClientes[i].getClave()){
                        cout << "Tu track ID es: " << listaEnvios[i].getTrackID() << endl;
                    }
                }    
            break;

        case 8:  //Dar de alta vendedor
            vendedores = altaVendedor(vendedores);
            cout << "Vendedor aceptado\n";
            break;

        case 9:  //Agregar producto 
            cout << "Quieres agregar un producto nuevo\n";
            cin >> nuevo;
            if (nuevo == "SI" || nuevo == "Si" || nuevo == "si")
            {
                listaProductos = crearProducto(listaProductos); //Aqui agrega el producto a la lista
            }
            
            
            for (int i = 0; i < listaProductos.size(); i++)
            {
                cout << to_string(i + 1)<< " " << listaProductos[i].getNombre() << endl; //Aqui imprime una lista de productos 
            }    
            cout << "¿Que numero de producto deseas agregar al inventario?\n";
            cin >> numProducto; //Se selecciona el producto
            cout << "Ingresa tu clave de vendedor\n";
            cin >> clavevendedor; //Pide la clave para buscar que vendedor es en el for
            for (int i = 0; i < vendedores.size(); i++) //Aqui no entra al for
            {
                if (clavevendedor == vendedores[i].getClave())
                {
                    vendedores[i].agregarProductosInventario(listaProductos[numProducto], amazon);
                    vendedores[i].agregarProductosInventario(listaProductos[numProducto], mercadolibre);
                    vendedores[i].agregarProductosInventario(listaProductos[numProducto], oficial);
                    vendedores[i].agregarProductosInventario(listaProductos[numProducto], wish);
                    vendedores[i].agregarProductosInventario(listaProductos[numProducto], ebay);
                    cout << "El producto ha sido agregado correctamente a todos los sitios Web.\n";
                }
                    
            }            
            break;

        case 10:  //Eliminar producto de inventario
            for (int i = 0; i < listaProductos.size(); i++)
            {
                cout << to_string(i + 1)<< " " << listaProductos[i].getNombre() << endl; //Aqui imprime una lista de productos 
            }    
            cout << "¿Que numero de producto deseas agregar al inventario?\n";
            cin >> numProducto; //Se selecciona el producto
            cout << "Ingresa tu clave de vendedor\n";
            cin >> clavevendedor; //Pide la clave para buscar que vendedor es en el for
            for (int i = 0; i < vendedores.size(); i++) //Aqui no entra al for
            {
                if (clavevendedor == vendedores[i].getClave())
                {
                    vendedores[i].eliminarProductosInventario(amazon);
                    vendedores[i].eliminarProductosInventario(mercadolibre);
                    vendedores[i].eliminarProductosInventario(oficial);
                    vendedores[i].eliminarProductosInventario(wish);
                    vendedores[i].eliminarProductosInventario(ebay);
                    cout << "El producto ha sido agregado correctamente a todos los sitios Web.\n";
                }
                    
            }  
            break;

        case 11:  //Configurar descuentos

            cout << "Ingresa tu clave de vendedor\n";
            cin >> clavevendedor; //Pide la clave para buscar que vendedor es en el for
            for (int i = 0; i < vendedores.size(); i++) //Aqui no entra al for
            {
                if (clavevendedor == vendedores[i].getClave()){
                    vendedores[i].configurarDescuentos(amazon);
                    vendedores[i].configurarDescuentos(mercadolibre);
                    vendedores[i].configurarDescuentos(oficial);
                    vendedores[i].configurarDescuentos(wish);
                    vendedores[i].configurarDescuentos(ebay);
                    cout << "El descuento ha sido configurado en todos tus anuncios.\n";
                }
            }
            break;  
        
        default:
            break;
        }

    }
return 0;
}
