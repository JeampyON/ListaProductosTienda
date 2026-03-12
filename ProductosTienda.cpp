#include <iostream> //I/O Stream permite usar cin para entrada de datos y cout para imprimir texto
#include <vector> //define el contenedor std::vector significa que el vector sera dinamico 
#include <string> //permite crear variables como palabras o frases 
#include <iomanip> //I/O manipulation, permite usar setprecision(2) para los decimales, en este caso el dinero

using namespace std; //organiza funciones en paquetes (namespaces) e indica el uso del paquete standard por defecto

	struct Producto { //Corresponde a la estructura que tendra cada producto
		int IdProducto;
		string nombre;
		double precio;
		int stock;
	};
	
	class Tienda {//clase tienda la cual lleva todas las funcionalidades del programa 
	private: 
		vector<Producto> ListaDeCosas; 	
	
	public: 
		void datosIniciales(){ //Aqui se digitan los 10 primeros datos iniciales que pide el enunciado
			ListaDeCosas.push_back({100, "Leche 1lt", 1.00, 7});
			ListaDeCosas.push_back({101, "Huevos cubeta", 3.50, 13});
			ListaDeCosas.push_back({102, "Fideos 400g", 1.00, 10});
			ListaDeCosas.push_back({103, "Cafe sachet", 1.00, 14});
			ListaDeCosas.push_back({104, "Azucar 1kg", 1.00, 16});
			ListaDeCosas.push_back({105, "Coca Cola 1lt", 1.00, 4});
			ListaDeCosas.push_back({106, "Agua 1gl", 1.00, 9});
			ListaDeCosas.push_back({107, "Queso de mesa", 1.00, 12});
			ListaDeCosas.push_back({108, "Arroz 1kg", 1.00, 15});
			ListaDeCosas.push_back({109, "Manzanas", 1.00, 20});
			
		}
		
		void mostrarListaDeCosas(){ //Funcion que primero valida si no existe productos, 
									//y al existir los imprime lo de la funcion "datosIniciales" mediante el for
			if (ListaDeCosas.empty()){
				cout << "No existen productos" << endl;
				return;
			}
		
		
		cout << "---------Lista de Producto----------" << endl;
		cout << "ID\tNombre\t\tPrecio\tStock" << endl;
		
			for (int i=0;i<ListaDeCosas.size();i++){
			cout << ListaDeCosas[i].IdProducto << "\t"
				 << ListaDeCosas[i].nombre << "\t\t"
				 << "$" << ListaDeCosas[i].precio << "\t"
				 << ListaDeCosas[i].stock << endl;
			}
		}
		
		void ingresarProducto() { //Funcion donde ingresare nuevos productos
			Producto nuevo; //objeto en blanco
			
			cout << "\nDigite el ID del producto nuevo: ";
			cin >> nuevo.IdProducto;
			
			cin.ignore();//sentencia que evita problemas con los espacios en los nombres
			cout << "Digite el nombre del producto: ";
			getline(cin, nuevo.nombre);
			
			cout << "Digite el precio del producto (unitario): ";
			cin >> nuevo.precio;
			
			cout << "Digite el stock inicial del producto: ";
			cin >> nuevo.stock;
			
			ListaDeCosas.push_back(nuevo); //aplicacion del producto a la lista;
			cout << "\nNuevo producto ingresado con exito" << endl;
		}
		
		void buscarProducto(){
			int idBuscar;
			bool encontrado = false; //se añade una variable tipo boolean
							 //porque vamos a comparar ID's y si son similares el boolean dara verdadero
				
			cout << "\nDigite el ID del producto que desea buscar: ";
			cin >> idBuscar;
			
			for(int i=0; i<ListaDeCosas.size(); i++){
				if (ListaDeCosas[i].IdProducto == idBuscar){ //iteracion con for que permite, mediante comparaciones en un recorrido
															 //encontrar la ID similar y modificar
					cout << "\nProducto localizado" << endl;
					cout << "Nombre: " << ListaDeCosas[i].nombre << endl;	
					cout << "Precio: $" << ListaDeCosas[i].precio << endl;
					cout << "Stock disponible: " << ListaDeCosas[i].stock << endl;
					encontrado = true;
					break;
				}
			}
			
			if (!encontrado) {
				cout << "El ID: " << idBuscar << " no se encuentra en el inventario de productos\n" << endl;
			}	
		}
		
		void modificarProducto(){ //funcion que me permite modificar los datos de un producto 
			int idModificar;
			bool encontrado = false; //se empean un dato booleano para cuando se encuentre le producto similar de true
			cout << "\nDigite el ID del producto que desea modificar: ";
			cin >> idModificar;
			
			for(int i=0; i<ListaDeCosas.size(); i++){
				if (ListaDeCosas[i].IdProducto == idModificar){ //interaccion del for que compara las ID hasta encontrar su similar
					int seleccion;
					cout << "\nProducto localizado" << endl;
					cout << "Nombre: " << ListaDeCosas[i].nombre << endl;	
					cout << "Precio: $" << ListaDeCosas[i].precio << endl;
					cout << "Stock disponible: " << ListaDeCosas[i].stock << endl;
					encontrado = true;
					cout << "Continuar la modificacion [SI = 1] [NO = 0]: "; //estructura de validacion
					cin >> seleccion;
					
					if (seleccion == 1 ){
						cout << "Digite los nuevos datos del producto: " << endl;
						
						cin.ignore(); //estructura que ignora los espacios entre nombres y toma todos los datos digitados
						cout << "Nuevo nombre: ";
						getline(cin, ListaDeCosas[i].nombre); //toma la linea ingresada por el usuario y la imprime 
						
						cout << "Nuevo precio: ";
						cin >> ListaDeCosas[i].precio;
						
						cout << "Nuevo stock: ";
						cin >> ListaDeCosas[i].stock;
						
						cout << "Producto actualizado exitosamente" << endl;
						break;	
					} else{
						cout << "Volviendo al menu" << endl;
					}
				}
			}
				if (!encontrado){
					cout << "El ID: " << idModificar << " no se encuentra en el inventario\n" << endl;
				}
			}
			
			void eliminarProducto(){ //funcion que me perite eliminar un producto especifico mediante el ID
				int idEliminar;
				bool encontrado = false; //se emplea un dato booleano para validadr cuando se encuentre el producto
				
				cout << "\nDigite el ID del producto a eliminar: ";
				cin >> idEliminar;
				
				for(int i=0; i<ListaDeCosas.size(); i++){
					if (ListaDeCosas[i].IdProducto == idEliminar){ //interaccion del for que compara las ID hasta encontrar su similar
						int seleccion;
						encontrado = true;
						cout << "\nProducto localizado" << endl;
						cout << "Nombre: " << ListaDeCosas[i].nombre << endl;	
						cout << "Precio: $" << ListaDeCosas[i].precio << endl;
						cout << "Stock disponible: " << ListaDeCosas[i].stock << endl;
						
						encontrado = true;
						cout << "Continuar con la extradicion [SI = 1] [NO = 0]: "; //estructura de validacion 
						cin >> seleccion;
						
						if(seleccion == 1){
							ListaDeCosas.erase(ListaDeCosas.begin() + i); //linea que elimina el producto
							cout << "Producto eliminado correctamente";
							break;
						}else{
							cout << "Volviendo al menu" << endl;
						}
					}	
				}
				if (!encontrado){
					cout << "El ID: " << idEliminar << " no se encuentra en el inventario\n" << endl;
				}
			}
			
			void generarReporteFinal() { //funcion donde se genera el reporte final imprimiendo el total de productos, el producto mas caro
										 //y la inversion total que lleva el inventario
    			double inversionTotal = 0;
    			int productoMasCaroIdx = 0;

   					for (int i = 0; i < ListaDeCosas.size(); i++) {
        				inversionTotal += (ListaDeCosas[i].precio * ListaDeCosas[i].stock);
        				if (ListaDeCosas[i].precio > ListaDeCosas[productoMasCaroIdx].precio) {
            				productoMasCaroIdx = i;
       				 	}
    				}
    				
    			cout << "\n              REPORTE FINAL                " << endl;
    			cout << "---------------------------------------------" << endl;
    			cout << "Total de productos en catalogo: " << ListaDeCosas.size() << endl;
    			cout << "Inversion total del inventario: $" << fixed << setprecision(2) << inversionTotal << endl;
   				cout << "Producto estrella (Mas caro): " << ListaDeCosas[productoMasCaroIdx].nombre 
        			 << " ($" << ListaDeCosas[productoMasCaroIdx].precio << ")\n" << endl;
			}
			
		};
	
	int main(){ //funcion main en donde se ejecutara las funciones de clase tienda
		Tienda MiTienda; //creamos la tienda (objeto)
		MiTienda.datosIniciales();
		
		int menu;
		do { //implementacion del menu interactivo
			cout << "\n--- MENU TIENDA ---" << endl;
        	cout << "1. Mostrar Inventario" << endl;
        	cout << "2. Registrar Producto" << endl;
        	cout << "3. Buscar Producto (ID)" << endl;
        	cout << "4. Modificar Producto" << endl;
        	cout << "5. Eliminar Producto" << endl;
        	cout << "6. Generar Reporte" << endl;
        	cout << "7. Salir" << endl;
        	cout << "Seleccione una opcion: ";
        	cin >> menu;
        	
        	switch (menu){ //se emplea una estructura de control switch la cual
        				   //me permite interactuar con el menu de manera sencilla
        				   //y mediante casos ir colocando las funciones correspondientes 
        		case 1:
        			MiTienda.mostrarListaDeCosas();
        			break;
				case 2: 
					MiTienda.ingresarProducto();
					break;	
				case 3:
					MiTienda.buscarProducto();
					break;
				case 4:
					MiTienda.modificarProducto();
					break;
				case 5:
					MiTienda.eliminarProducto();
					break;
				case 6:
					MiTienda.generarReporteFinal();
					break;
        		case 7:
                	cout << "Saliendo..." << endl;
                	break;
            	default:
                	cout << "Opcion no valida" << endl;	
			}
		}while (menu != 7); //sentencia que indica que si el usuario ingresa un dato mayor a 7 
							//el programa imprime "Opcion no valida" y me devuelve al menu interactivo
		
		return 0;
	}
