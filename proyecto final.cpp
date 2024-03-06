#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <iomanip>

using namespace std;

const int NUM_ELEMENTOS = 4;

class Persona {
protected:
	string nombres[NUM_ELEMENTOS];
	string apellidos[NUM_ELEMENTOS];
	string emails[NUM_ELEMENTOS];
public:
	virtual void generarDatosAleatorios() = 0;
	virtual void imprimir(bool enColumnas) const = 0;
	virtual void buscar(const string& nombreApellido) const = 0;
};

class Usuario : public Persona {
private:
	string telefonos[NUM_ELEMENTOS];
	string direcciones[NUM_ELEMENTOS];
public:
	void generarDatosAleatorios() override {
		// Arrays de nombres y apellidos fijos
		string nombresFijos[NUM_ELEMENTOS] = {"Juan", "María", "Carlos", "Laura"};
		string apellidosFijos[NUM_ELEMENTOS] = {"González", "Rodríguez", "Martínez", "López"};
		
		srand(time(0));
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			// Generar datos aleatorios usando los nombres y apellidos fijos
			int indiceNombre = rand() % NUM_ELEMENTOS;
			int indiceApellido = rand() % NUM_ELEMENTOS;
			
			nombres[i] = nombresFijos[indiceNombre];
			apellidos[i] = apellidosFijos[indiceApellido];
			emails[i] = nombres[i] + "." + apellidos[i] + "@example.com";
			telefonos[i] = "123456789";
			direcciones[i] = "Dirección" + to_string(i + 1);
		}
	}
	
	void imprimir(bool enColumnas) const override {
		if (enColumnas) {
			cout << "Listado de Usuarios (en columnas):\n";
			cout << "ID,Nombre,Apellido,Email,Teléfono,Dirección\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << i + 1 << "," << nombres[i] << "," << apellidos[i] << "," << emails[i] << "," << telefonos[i] << "," << direcciones[i] << "\n";
			}
		} else {
			cout << "Listado de Usuarios (en filas):\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << "ID: " << i + 1 << endl;
				cout << "Nombre: " << nombres[i] << endl;
				cout << "Apellido: " << apellidos[i] << endl;
				cout << "Email: " << emails[i] << endl;
				cout << "Teléfono: " << telefonos[i] << endl;
				cout << "Dirección: " << direcciones[i] << endl;
				cout << endl;
			}
		}
	}
	
	void buscar(const string& nombreApellido) const override {
		cout << "Búsqueda de Usuario por Nombre y Apellido: " << nombreApellido << endl;
		bool encontrado = false;
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			string nombreCompleto = nombres[i] + " " + apellidos[i];
			if (nombreCompleto.find(nombreApellido) != string::npos) {
				cout << "Usuario encontrado:\n";
				cout << "ID,Nombre,Apellido,Email,Teléfono,Dirección\n";
				cout << i + 1 << "," << nombres[i] << "," << apellidos[i] << "," << emails[i] << "," << telefonos[i] << "," << direcciones[i] << "\n";
				encontrado = true;
			}
		}
		if (!encontrado)
			cout << "Usuario no encontrado.\n";
	}
};

class Bibliotecario : public Persona {
private:
	int niveles[NUM_ELEMENTOS];
	string horarios[NUM_ELEMENTOS];
public:
	void generarDatosAleatorios() override {
		// Arrays de nombres y apellidos fijos
		string nombresFijos[NUM_ELEMENTOS] = {"Pedro", "Ana", "Luis", "Elena"};
		string apellidosFijos[NUM_ELEMENTOS] = {"Sánchez", "Gómez", "Díaz", "Pérez"};
		
		srand(time(0));
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			// Generar datos aleatorios usando los nombres y apellidos fijos
			int indiceNombre = rand() % NUM_ELEMENTOS;
			int indiceApellido = rand() % NUM_ELEMENTOS;
			
			nombres[i] = nombresFijos[indiceNombre];
			apellidos[i] = apellidosFijos[indiceApellido];
			emails[i] = nombres[i] + "." + apellidos[i] + "@example.com";
			niveles[i] = rand() % 10 + 1;
			string horario;
			switch (rand() % 3) {
			case 0:
				horario = "Mañana";
				break;
			case 1:
				horario = "Tarde";
				break;
			case 2:
				horario = "Noche";
				break;
			}
			horarios[i] = horario;
		}
	}
	
	void imprimir(bool enColumnas) const override {
		if (enColumnas) {
			cout << "Listado de Bibliotecarios (en columnas):\n";
			cout << "ID,Nombre,Apellido,Email,Nivel,Horario\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << i + 1 << "," << nombres[i] << "," << apellidos[i] << "," << emails[i] << "," << niveles[i] << "," << horarios[i] << "\n";
			}
		} else {
			cout << "Listado de Bibliotecarios (en filas):\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << "ID: " << i + 1 << endl;
				cout << "Nombre: " << nombres[i] << endl;
				cout << "Apellido: " << apellidos[i] << endl;
				cout << "Email: " << emails[i] << endl;
				cout << "Nivel: " << niveles[i] << endl;
				cout << "Horario: " << horarios[i] << endl;
				cout << endl;
			}
		}
	}
	
	void buscar(const string& nombreApellido) const override {
		cout << "Búsqueda de Bibliotecario por Nombre y Apellido: " << nombreApellido << endl;
		bool encontrado = false;
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			string nombreCompleto = nombres[i] + " " + apellidos[i];
			if (nombreCompleto.find(nombreApellido) != string::npos) {
				cout << "Bibliotecario encontrado:\n";
				cout << "ID,Nombre,Apellido,Email,Nivel,Horario\n";
				cout << i + 1 << "," << nombres[i] << "," << apellidos[i] << "," << emails[i] << "," << niveles[i] << "," << horarios[i] << "\n";
				encontrado = true;
			}
		}
		if (!encontrado)
			cout << "Bibliotecario no encontrado.\n";
	}
};

class Libro {
private:
	string titulos[NUM_ELEMENTOS];
	string autores[NUM_ELEMENTOS];
	string categorias[NUM_ELEMENTOS];
public:
	void generarDatosAleatorios() {
		// Arrays de títulos de libros fijos
		string titulosFijos[NUM_ELEMENTOS] = {"El señor de los anillos", "Cien años de soledad", "Don Quijote de la Mancha", "1984"};
		string autoresFijos[NUM_ELEMENTOS] = {"J.R.R. Tolkien", "Gabriel García Márquez", "Miguel de Cervantes", "George Orwell"};
		
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			// Generar datos aleatorios usando los títulos de libros fijos
			int indiceTitulo = rand() % NUM_ELEMENTOS;
			titulos[i] = titulosFijos[indiceTitulo];
			autores[i] = autoresFijos[indiceTitulo];
			categorias[i] = "Categoría" + to_string(i + 1);
		}
	}
	
	void imprimir(bool enColumnas) const {
		if (enColumnas) {
			cout << "Listado de Libros (en columnas):\n";
			cout << "ID,Título,Autor,Categoría\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << i + 1 << "," << titulos[i] << "," << autores[i] << "," << categorias[i] << "\n";
			}
		} else {
			cout << "Listado de Libros (en filas):\n";
			for (int i = 0; i < NUM_ELEMENTOS; ++i) {
				cout << "ID: " << i + 1 << endl;
				cout << "Título: " << titulos[i] << endl;
				cout << "Autor: " << autores[i] << endl;
				cout << "Categoría: " << categorias[i] << endl;
				cout << endl;
			}
		}
	}
	
	void buscar(const string& titulo) const {
		cout << "Búsqueda de Libro por Título: " << titulo << endl;
		bool encontrado = false;
		for (int i = 0; i < NUM_ELEMENTOS; ++i) {
			if (titulos[i] == titulo) {
				cout << "Libro encontrado:\n";
				cout << "ID,Título,Autor,Categoría\n";
				cout << i + 1 << "," << titulos[i] << "," << autores[i] << "," << categorias[i] << "\n";
				encontrado = true;
			}
		}
		if (!encontrado)
			cout << "Libro no encontrado.\n";
	}
};

class GestorLibros {
private:
	Libro libros;
public:
	void generarDatosAleatorios() {
		libros.generarDatosAleatorios();
	}
	
	void imprimir(bool enColumnas) const {
		libros.imprimir(enColumnas);
	}
	
	void buscar(const string& titulo) const {
		libros.buscar(titulo);
	}
};

int main() {
	Usuario usuario;
	Bibliotecario bibliotecario;
	GestorLibros gestorLibros;
	
	char opcionMenuPrincipal;
	
	do {
		system("cls");
		
		cout << "MENU PRINCIPAL\n";
		cout << "1) Llenado de datos\n";
		cout << "2) Listados\n";
		cout << "3) Búsquedas\n";
		cout << "0) Salir\n";
		cout << "Ingrese opción: ";
		cin >> opcionMenuPrincipal;
		opcionMenuPrincipal = tolower(opcionMenuPrincipal);
		
		switch (opcionMenuPrincipal) {
		case '1': {
			usuario.generarDatosAleatorios();
			bibliotecario.generarDatosAleatorios();
			gestorLibros.generarDatosAleatorios();
			cout << "Datos generados aleatoriamente.\n";
			break;
		}
		case '2': {
			char opcionListados;
			do {
				system("cls");
				cout << "SUBMENU LISTADOS\n";
				cout << "a) Listado Usuarios\n";
				cout << "b) Listado Bibliotecarios\n";
				cout << "c) Listado Libros\n";
				cout << "x) Volver al menú principal\n";
				cout << "Ingrese opción: ";
				cin >> opcionListados;
				opcionListados = tolower(opcionListados);
				
				bool imprimirEnColumnas = true;
				char opcionFormatoImpresion;
				
				if (opcionListados != 'x') {
					cout << "¿Cómo deseas imprimir los datos? (c para columnas, f para filas): ";
					cin >> opcionFormatoImpresion;
					imprimirEnColumnas = (tolower(opcionFormatoImpresion) == 'c');
				}
				
				switch (opcionListados) {
				case 'a':
					usuario.imprimir(imprimirEnColumnas);
					break;
				case 'b':
					bibliotecario.imprimir(imprimirEnColumnas);
					break;
				case 'c':
					gestorLibros.imprimir(imprimirEnColumnas);
					break;
				case 'x':
					break;
				default:
					cout << "Opción no válida. Intente de nuevo.\n";
				}
				
				if (opcionListados != 'x') {
					cout << "\nPresione Enter para volver al menú principal...";
					cin.ignore();
					cin.get();
				}
				
			} while (opcionListados != 'x');
			break;
		}
		case '3': {
			char opcionBusqueda;
			do {
				system("cls");
				cout << "SUBMENU BUSQUEDAS\n";
				cout << "a) Búsqueda de Usuario (Nombre y Apellido)\n";
				cout << "b) Búsqueda de Bibliotecario (Nombre y Apellido)\n";
				cout << "c) Búsqueda de Libro (Título)\n";
				cout << "x) Volver al menú principal\n";
				cout << "Ingrese opción: ";
				cin >> opcionBusqueda;
				opcionBusqueda = tolower(opcionBusqueda);
				
				switch (opcionBusqueda) {
				case 'a': {
					string nombreApellidoBusqueda;
					cout << "Ingrese parte del nombre o del apellido del usuario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBusqueda);
					usuario.buscar(nombreApellidoBusqueda);
					break;
				}
				case 'b': {
					string nombreApellidoBusqueda;
					cout << "Ingrese parte del nombre o del apellido del bibliotecario a buscar: ";
					cin.ignore();
					getline(cin, nombreApellidoBusqueda);
					bibliotecario.buscar(nombreApellidoBusqueda);
					break;
				}
				case 'c': {
					string tituloBusqueda;
					cout << "Ingrese el título del libro que desea buscar: ";
					cin.ignore();
					getline(cin, tituloBusqueda);
					gestorLibros.buscar(tituloBusqueda);
					break;
				}
				case 'x':
					break;
				default:
					cout << "Opción no válida. Intente de nuevo.\n";
				}
				
				if (opcionBusqueda != 'x') {
					cout << "\nPresione Enter para volver al menú principal...";
					cin.ignore();
					cin.get();
				}
				
			} while (opcionBusqueda != 'x');
			break;
		}
		case '0':
			cout << "Saliendo...\n";
			break;
		default:
			cout << "Opción no válida. Intente de nuevo.\n";
		}
		
		if (opcionMenuPrincipal != '0') {
			cout << "\nPresione Enter para volver al menú principal...";
			cin.ignore();
			cin.get();
		}
		
	} while (opcionMenuPrincipal != '0');
	
	return 0;
}
