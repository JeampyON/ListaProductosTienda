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
	
	class Tienda {
	private: 
		vector<Producto> ListaDeCosas; 	
	
	public: 
		void datosIniciales(){
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
				if (ListaDeCosas[i].IdProducto == idBuscar){
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
		
		void modificarProducto(){
			int idModificar;
			bool encontrado = false;
			cout << "\nDigite el ID del producto que desea modificar: ";
			cin >> idModificar;
			
			for(int i=0; i<ListaDeCosas.size(); i++){
				if (ListaDeCosas[i].IdProducto == idModificar){
					int seleccion;
					cout << "\nProducto localizado" << endl;
					cout << "Nombre: " << ListaDeCosas[i].nombre << endl;	
					cout << "Precio: $" << ListaDeCosas[i].precio << endl;
					cout << "Stock disponible: " << ListaDeCosas[i].stock << endl;
					encontrado = true;
					cout << "Continuar la modificacion [SI = 1] [NO = 0]: ";
					cin >> seleccion;
					
					if (seleccion == 1 ){
						cout << "Digite los nuevos datos del producto: " << endl;
						
						cin.ignore();
						cout << "Nuevo nombre: ";
						getline(cin, ListaDeCosas[i].nombre);
						
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
			
			void eliminarProducto(){
				int idEliminar;
				bool encontrado = false;
				
				cout << "\nDigite el ID del producto a eliminar: ";
				cin >> idEliminar;
				
				for(int i=0; i<ListaDeCosas.size(); i++){
					if (ListaDeCosas[i].IdProducto == idEliminar){
						int seleccion;
						encontrado = true;
						cout << "\nProducto localizado" << endl;
						cout << "Nombre: " << ListaDeCosas[i].nombre << endl;	
						cout << "Precio: $" << ListaDeCosas[i].precio << endl;
						cout << "Stock disponible: " << ListaDeCosas[i].stock << endl;
						
						encontrado = true;
						cout << "Continuar con la extradicion [SI = 1] [NO = 0]: ";
						cin >> seleccion;
						
						if(seleccion == 1){
							ListaDeCosas.erase(ListaDeCosas.begin() + i);
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
			
			void generarReporteFinal() {
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
	
	int main(){
		Tienda MiTienda;
		MiTienda.datosIniciales();
		
		int menu;
		do {
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
        	
        	switch (menu){
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
                	cout << "Opcion no valida." << endl;	
			}
		}while (menu != 7);
		
		return 0;
	}
