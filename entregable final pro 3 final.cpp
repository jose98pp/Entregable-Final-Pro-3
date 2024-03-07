#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <iomanip>

using namespace std;

const int TAMANO = 4; // Tamaño de los arreglos

// Clase Persona
class Persona {
private:
	int nID;
	string sNombre;
	string sApellido;
	string sEmail;
	
public:
	// Constructor por defecto
	Persona() : nID(0), sNombre("sin nombre"), sApellido("sin apellido"), sEmail("sin email") {}
	
	// Constructor por parámetros
	Persona(int id, string nombre, string apellido, string email) : nID(id), sNombre(nombre), sApellido(apellido), sEmail(email) {}
	
	// Métodos de obtención de los atributos
	int get_ID() const { return nID; }
	string get_Nombre() const { return sNombre; }
	string get_Apellido() const { return sApellido; }
	string get_Email() const { return sEmail; }
	
	
};

// Clase Usuario derivada de Persona
class Usuario : public Persona {
private:
	int nCelular;
	string sDireccion;
	
public:
	// Constructor por defecto
	Usuario() : nCelular(0),sDireccion("sin dirección") {}
	
	// Constructor por parámetros
	Usuario(int id, string nombre, string apellido, string email, int celular,string direccion) : Persona(id, nombre, apellido, email), nCelular(celular),sDireccion(direccion) {}
	
	// Métodos de obtención y modificación del celular
	int get_Celular() const { return nCelular; }
	string get_Direccion() const { return sDireccion; }
	void set_Celular(int celular) { nCelular = celular; }
	void set_Direccion(const string& direccion) { sDireccion = direccion; }
};

// Clase Bibliotecario derivada de Persona
class Bibliotecario : public Persona {
private:
	int nNivel;
	string sHorario;
	
public:
	// Constructor por defecto
	Bibliotecario() : nNivel(0), sHorario("sin horario") {}
	
	// Constructor por parámetros
	Bibliotecario(int id, string nombre, string apellido, string email, int nivel, string horario) : Persona(id, nombre, apellido, email), nNivel(nivel), sHorario(horario) {}
	
	// Métodos de obtención y modificación del nivel y horario
	int get_Nivel() const { return nNivel; }
	string get_Horario() const { return sHorario; }
	void set_Nivel(int nivel) { nNivel = nivel; }
	void set_Horario(const string& horario) { sHorario = horario; }
};

// Clase Libro
class Libro {
private:
	string sTitulo;
	string sAutor;
	string sCategoria;
	string sISBN;
	int publicationYear;
	string sEditorial;
	string sIdioma;
	bool bDisponible;
	
public:
	// Constructor por defecto
	Libro() : sTitulo("sin título"), sAutor("sin autor"), sCategoria("sin categoría") {}
	
	// Constructor por parámetros
	Libro(const string& titulo, const string& autor, const string& categoria, const string& isbn, int year, const string& editorial, const string& idioma, bool disponible)
		: sTitulo(titulo), sAutor(autor), sCategoria(categoria), sISBN(isbn), publicationYear(year), sEditorial(editorial), sIdioma(idioma), bDisponible(disponible) {}
	
	// Métodos de obtención de los atributos
	string get_Titulo() const { return sTitulo; }
	string get_Autor() const { return sAutor; }
	string get_Categoria() const { return sCategoria; }
	string get_ISBN() const { return sISBN; }
	int get_PublicationYear() const { return publicationYear; }
	string get_Editorial() const { return sEditorial; }
	string get_Idioma() const { return sIdioma; }
	bool estaDisponible() const { return bDisponible; }
};

// Clase GestorUsuarios
class GestorUsuarios {
private:
	Usuario usuarios[TAMANO];
	int tamanoActual;
	
public:
	GestorUsuarios() : tamanoActual(0) {}
	
	// Función para generar datos aleatorios de usuarios
	void generarDatosAleatorios() {
		string listaNombres[] = {"Juan", "Maria", "Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia"};
		string listaApellidos[] = {"Peralta", "Osinaga", "Rodriguez", "Escobar", "Lopez", "Gonzalez", "Mendoza", "Roca", "Garcia", "Torres"};
		
		srand(time(nullptr));
		
		tamanoActual = 0;
		
		for (int i = 0; i < TAMANO; ++i) {
			int indiceNombre = rand() % 10;
			int indiceApellido = rand() % 10;
			int idAleatorio = i + 1;
			int celularAleatorio = (rand() % 2 + 6) * 10000000 + rand() % 10000000;
			string direccionAleatoria = "Calle " + to_string(rand() % 100 + 1) + ", Ciudad";
			
			string nombreAleatorio = listaNombres[indiceNombre];
			string apellidoAleatorio = listaApellidos[indiceApellido];
			string emailAleatorio = nombreAleatorio + apellidoAleatorio + "@upds.net.bo";
			
			usuarios[i] = Usuario(idAleatorio, nombreAleatorio, apellidoAleatorio, emailAleatorio, celularAleatorio,direccionAleatoria);
			
			tamanoActual++;
		}
	}
	// Función para convertir una cadena a minúsculas
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	
	// Función para buscar usuario por nombre, apellido, email, celular o dirección
	bool buscarUsuario(const string& atributo) const {
		string atributoMinuscula = convertir(atributo);
		for (int i = 0; i < tamanoActual; ++i) {
			// Convertir todos los atributos del usuario a minúsculas y verificar si contienen el atributo buscado
			if (convertir(usuarios[i].get_Nombre()).find(atributoMinuscula) != string::npos || 
				convertir(usuarios[i].get_Apellido()).find(atributoMinuscula) != string::npos || 
				convertir(usuarios[i].get_Email()).find(atributoMinuscula) != string::npos ||
				convertir(to_string(usuarios[i].get_Celular())).find(atributoMinuscula) != string::npos ||
				convertir(usuarios[i].get_Direccion()).find(atributoMinuscula) != string::npos) {
				// Imprimir detalles del usuario encontrado
				cout << "Usuario encontrado:" << endl;
				cout << "ID: " << usuarios[i].get_ID() << endl;
				cout << "Nombre: " << usuarios[i].get_Nombre() << endl;
				cout << "Apellido: " << usuarios[i].get_Apellido() << endl;
				cout << "Email: " << usuarios[i].get_Email() << endl;
				cout << "Celular: " << usuarios[i].get_Celular() << endl;
				cout << "Dirección: " << usuarios[i].get_Direccion() << endl;
				return true;
			}
		}
		// Si no se encontró ninguna coincidencia
		cout << "No se encontró ningún usuario con el dato proporcionado." << endl;
		return false;
	}
	
	
	
	void imprimirUsuarios() const {
		cout << "\n--- LISTADO DE USUARIOS ---" << endl;
		cout << setw(10) << "ID" << setw(20) << "Nombre" << setw(20) << "Apellido" << setw(25) << "Email" << setw(15) << "Celular" << setw(15) << "Direccion" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << setw(10) << usuarios[i].get_ID() << setw(20) << usuarios[i].get_Nombre() << setw(20) << usuarios[i].get_Apellido() << setw(25) << usuarios[i].get_Email() << setw(15) << usuarios[i].get_Celular() << setw(15) << usuarios[i].get_Direccion() << endl;
		}
	}
	
	void imprimirUsuariosPorBloques() const {
		cout << "\n--- LISTADO DE USUARIOS POR BLOQUES ---" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << "User ID: " << usuarios[i].get_ID() << endl;
			cout << "Nombre: " << usuarios[i].get_Nombre() << endl;
			cout << "Apellido: " << usuarios[i].get_Apellido() << endl;
			cout << "Email: " << usuarios[i].get_Email() << endl;
			cout << "Celular: " << usuarios[i].get_Celular() << endl;
			cout << "Dirección: " << usuarios[i].get_Direccion() << endl << endl;
		}
	}
};

// Clase GestorBibliotecarios
class GestorBibliotecarios {
private:
	Bibliotecario bibliotecarios[TAMANO];
	int tamanoActual;
	
public:
	GestorBibliotecarios() : tamanoActual(0) {}
	
	// Función para generar datos aleatorios de bibliotecarios
	void generarDatosAleatorios() {
		string listaNombres[] = {"Luis", "Ana", "Carlos", "Laura", "Pedro", "Elena", "Javier", "Sofia", "Jose", "Maria"};
		string listaApellidos[] = {"Peralta", "Osinaga", "Rodriguez", "Escobar", "Lopez", "Gonzalez", "Mendoza", "Roca", "Garcia", "Torres"};
		
		srand(time(nullptr));
		
		for (int i = 0; i < TAMANO; ++i) {
			int indiceNombre = rand() % 10;
			int indiceApellido = rand() % 10;
			int idAleatorio = i + 1;
			int nivelAleatorio = rand() % 3 + 1;
			
			// Generar hora de entrada aleatoria entre 7:00 y 16:00
			int horaEntrada = rand() % 10 + 7;
			int minutoEntrada = rand() % 60;
			string horaEntradaStr = to_string(horaEntrada) + ":" + (minutoEntrada < 10 ? "0" : "") + to_string(minutoEntrada);
			
			// Generar hora de salida aleatoria entre hora de entrada y 21:00
			int horaSalida = rand() % (21 - horaEntrada) + horaEntrada;
			int minutoSalida = rand() % 60;
			string horaSalidaStr = to_string(horaSalida) + ":" + (minutoSalida < 10 ? "0" : "") + to_string(minutoSalida);
			
			string horarioAleatorio = horaEntradaStr + " - " + horaSalidaStr;
			
			string nombreAleatorio = listaNombres[indiceNombre];
			string apellidoAleatorio = listaApellidos[indiceApellido];
			string emailAleatorio = nombreAleatorio + apellidoAleatorio + "@upds.net.bo.com";
			
			bibliotecarios[i] = Bibliotecario(idAleatorio, nombreAleatorio, apellidoAleatorio, emailAleatorio, nivelAleatorio, horarioAleatorio);
			
			tamanoActual++;
		}
	}
	// Función para convertir una cadena a minúsculas
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	
	// Función para buscar bibliotecario por nombre, apellido o email
	bool buscarBibliotecario(const string& atributo) const {
		string atributoMinuscula = convertir(atributo);
		for (int i = 0; i < tamanoActual; ++i) {
			// Convertir nombres y apellidos a minúsculas y verificar si contienen el atributo buscado
			if (convertir(bibliotecarios[i].get_Nombre()).find(atributoMinuscula) != string::npos ||
				convertir(bibliotecarios[i].get_Apellido()).find(atributoMinuscula) != string::npos ||
				convertir(bibliotecarios[i].get_Email()) == atributoMinuscula) {
				// Imprimir detalles del bibliotecario encontrado
				cout << "Bibliotecario encontrado:" << endl;
				cout << "ID: " << bibliotecarios[i].get_ID() << endl;
				cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
				cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
				cout << "Email: " << bibliotecarios[i].get_Email() << endl;
				cout << "Nivel: " << bibliotecarios[i].get_Nivel() << endl;
				cout << "Horario: " << bibliotecarios[i].get_Horario() << endl;
				return true;
			}
		}
		// Si no se encontró ninguna coincidencia
		cout << "No se encontró ningún bibliotecario con el dato proporcionado." << endl;
		return false;
	}
	
	
	// Función para imprimir los datos de los bibliotecarios
	void imprimirBibliotecarios() const {
		cout << "\n--- LISTADO DE BIBLIOTECARIOS ---" << endl;
		cout << setw(10) << "ID" << setw(20) << "Nombre" << setw(20) << "Apellido" << setw(25) << "Email" << setw(10) << "Nivel" << setw(15) << "Horario" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << setw(10) << bibliotecarios[i].get_ID() << setw(20) << bibliotecarios[i].get_Nombre() << setw(20) << bibliotecarios[i].get_Apellido() << setw(25) << bibliotecarios[i].get_Email() << setw(10) << bibliotecarios[i].get_Nivel() << setw(15) << bibliotecarios[i].get_Horario() << endl;
		}
	}
	
	// Función para imprimir los datos de los bibliotecarios en forma de bloques
	void imprimirBibliotecariosPorBloques() const {
		cout << "\n--- LISTADO DE BIBLIOTECARIOS POR BLOQUES ---" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << "ID: " << bibliotecarios[i].get_ID() << endl;
			cout << "Nombre: " << bibliotecarios[i].get_Nombre() << endl;
			cout << "Apellido: " << bibliotecarios[i].get_Apellido() << endl;
			cout << "Email: " << bibliotecarios[i].get_Email() << endl;
			cout << "Nivel: " << bibliotecarios[i].get_Nivel() << endl;
			cout << "Horario: " << bibliotecarios[i].get_Horario() << endl << endl;
		}
	}
	
};

// Clase GestorLibros
class GestorLibros {
private:
	Libro libros[TAMANO];
	int tamanoActual;
	
public:
	GestorLibros() : tamanoActual(0) {}
	
	// Función para generar datos aleatorios de libros
	void generarDatosAleatorios() {
		string listaTitulos[] = {"El alquimista", "Cien años de soledad", "Don Quijote de la Mancha", "Harry Potter y la piedra filosofal"};
		string listaAutores[] = {"Paulo Coelho", "Gabriel García Márquez", "Miguel de Cervantes", "J.K. Rowling"};
		string listaCategorias[] = {"Ficción", "Novela", "Fantasía", "Aventura"};
		
		srand(time(nullptr));
		
		tamanoActual = 0;
		
		for (int i = 0; i < TAMANO; ++i) {
			int indiceTitulo = rand() % 4;
			int indiceAutor = rand() % 4;
			int indiceCategoria = rand() % 4;
			
			string tituloAleatorio = listaTitulos[indiceTitulo];
			string autorAleatorio = listaAutores[indiceAutor];
			string categoriaAleatoria = listaCategorias[indiceCategoria];
			string isbnAleatorio = "ISBN-" + to_string(rand() % 1000 + 1000);
			int yearAleatorio = rand() % 50 + 1970;
			string editorialAleatoria = "Editorial-" + to_string(rand() % 10);
			string idiomaAleatorio = (rand() % 2 == 0) ? "Español" : "Inglés";
			bool disponibleAleatorio = rand() % 2 == 0;
			
			libros[i] = Libro(tituloAleatorio, autorAleatorio, categoriaAleatoria, isbnAleatorio, yearAleatorio, editorialAleatoria, idiomaAleatorio, disponibleAleatorio);
			
			tamanoActual++;
		}
	}
	// Función para convertir una cadena a minúsculas
	string convertir(const string& cadena) const {
		string resultado = cadena;
		for (char& c : resultado) {
			c = tolower(c);
		}
		return resultado;
	}
	
	// Función para buscar libro por cualquier atributo
	bool buscarLibro(const string& atributo) const {
		string atributoMinuscula = convertir(atributo);
		for (int i = 0; i < tamanoActual; ++i) {
			// Convertir todos los atributos del libro a minúsculas y verificar si contienen el atributo buscado
			if (convertir(libros[i].get_Titulo()).find(atributoMinuscula) != string::npos || 
				convertir(libros[i].get_Autor()).find(atributoMinuscula) != string::npos || 
				convertir(libros[i].get_Categoria()).find(atributoMinuscula) != string::npos ||
				convertir(libros[i].get_ISBN()).find(atributoMinuscula) != string::npos ||
				convertir(to_string(libros[i].get_PublicationYear())).find(atributoMinuscula) != string::npos ||
				convertir(libros[i].get_Editorial()).find(atributoMinuscula) != string::npos ||
				convertir(libros[i].get_Idioma()).find(atributoMinuscula) != string::npos) {
				// Imprimir detalles del libro encontrado
				cout << "Libro encontrado:" << endl;
				cout << "Titulo: " << libros[i].get_Titulo() << endl;
				cout << "Autor: " << libros[i].get_Autor() << endl;
				cout << "Categoria: " << libros[i].get_Categoria() << endl;
				cout << "ISBN: " << libros[i].get_ISBN() << endl;
				cout << "Año de publicación: " << libros[i].get_PublicationYear() << endl;
				cout << "Editorial: " << libros[i].get_Editorial() << endl;
				cout << "Idioma: " << libros[i].get_Idioma() << endl;
				cout << "Disponible: " << (libros[i].estaDisponible() ? "Sí" : "No") << endl;
				return true;
			}
		}
		// Si no se encontró ninguna coincidencia
		cout << "No se encontró ningún libro con el dato proporcionado." << endl;
		return false;
	}
	
	// Función para imprimir los datos de los libros
	void imprimirLibros() const {
		cout << "\n--- LISTADO DE LIBROS ---" << endl;
		cout << setw(40) << "Título" << setw(30) << "Autor" << setw(25) << "Categoría" << setw(20) << "ISBN" << setw(20) << "Año Publicación" << setw(20) << "Editorial" << setw(15) << "Idioma" << setw(15) << "Disponible" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << setw(40) << libros[i].get_Titulo() << setw(30) << libros[i].get_Autor() << setw(25) << libros[i].get_Categoria() << setw(20) << libros[i].get_ISBN() << setw(20) << libros[i].get_PublicationYear() << setw(20) << libros[i].get_Editorial() << setw(15) << libros[i].get_Idioma() << setw(15) << (libros[i].estaDisponible() ? "Sí" : "No") << endl;
		}
	}
	
	// Función para imprimir los datos de los libros en forma de bloques
	void imprimirLibrosPorBloques() const {
		cout << "\n--- LISTADO DE LIBROS POR BLOQUES ---" << endl;
		for (int i = 0; i < tamanoActual; ++i) {
			cout << "Título: " << libros[i].get_Titulo() << endl;
			cout << "Autor: " << libros[i].get_Autor() << endl;
			cout << "Categoría: " << libros[i].get_Categoria() << endl;
			cout << "ISBN: " << libros[i].get_ISBN() << endl;
			cout << "Año de Publicación: " << libros[i].get_PublicationYear() << endl;
			cout << "Editorial: " << libros[i].get_Editorial() << endl;
			cout << "Idioma: " << libros[i].get_Idioma() << endl;
			cout << "Disponible: " << (libros[i].estaDisponible() ? "Sí" : "No") << endl << endl;
		}
	}
	
};

// Función para mostrar el menú principal
void mostrarMenuPrincipal(GestorUsuarios& gestorUsuarios, GestorBibliotecarios& gestorBibliotecarios, GestorLibros& gestorLibros) {
	char opcion;
	
	do {
		cout << "\n--- MENU ---" << endl;
		cout << "1) Llenado de datos." << endl;
		cout << "2) Listados" << endl;
		cout << "3) Busquedas" << endl;
		cout << "0) Salir." << endl;
		cout << "Ingrese su opción: ";
		cin >> opcion;
		
		switch (opcion) {
		case '1': {
			gestorUsuarios.generarDatosAleatorios();
			gestorBibliotecarios.generarDatosAleatorios();
			gestorLibros.generarDatosAleatorios();
			cout << "Datos generados aleatoriamente." << endl;
			break;
		}
		case '2': {
			char opcionListados;
			
			do {
				cout << "\n--- SUBMENU LISTADOS ---" << endl;
				cout << "A) Listado de Libros" << endl;
				cout << "B) Listado Usuarios" << endl;
				cout << "C) Listado Bibliotecarios" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese su opción: ";
				cin >> opcionListados;
				
				switch (opcionListados) {
				case 'A':
				case 'a':
					char respuestaLibros;
					cout << "Desea ver los datos en forma de lista (l) o en bloques (b)?: ";
					cin >> respuestaLibros;
					if (respuestaLibros == 'b' || respuestaLibros == 'B') {
						gestorLibros.imprimirLibrosPorBloques();
					} else {
						gestorLibros.imprimirLibros();
					}
					break;
				case 'B':
				case 'b':
					char respuesta;
					cout << "Desea ver los datos en forma de lista (l) o en bloques (b)?: ";
					cin >> respuesta;
					if (respuesta == 'b' || respuesta == 'B') {
						gestorUsuarios.imprimirUsuariosPorBloques();
					} else {
						gestorUsuarios.imprimirUsuarios();
					}
					break;
				case 'C':
				case 'c':
				{
					char respuesta;
					cout << "Desea ver los datos en forma de lista (l) o en bloques (b)?: ";
					cin >> respuesta;
					if (respuesta == 'b' || respuesta == 'B') {
						gestorBibliotecarios.imprimirBibliotecariosPorBloques();
					} else {
						gestorBibliotecarios.imprimirBibliotecarios();
					}
					break;
				}
				case 'X':
				case 'x':
					break;
				default:
					cout << "Opción inválida. Intente de nuevo." << endl;
				}
			} while (opcionListados != 'X' && opcionListados != 'x');
			break;
		}
		case '3': {
			char opcionBusquedas;
			
			do {
				cout << "\n--- SUBMENU BUSQUEDAS ---" << endl;
				cout << "A) Buscar Libro" << endl;
				cout << "B) Buscar Usuario" << endl;
				cout << "C) Buscar Bibliotecario" << endl;
				cout << "X) Salir" << endl;
				cout << "Ingrese su opción: ";
				cin >> opcionBusquedas;
				
				string atributo;
				
				switch (opcionBusquedas) {
				case 'A':
				case 'a':
					cout << "Ingrese el atributo del libro a buscar (Título, Autor, Categoría, ISBN, Año de publicación, Editorial, Idioma): ";
					cin.ignore();
					getline(cin, atributo);
					gestorLibros.buscarLibro(atributo);
					break;
				case 'B':
				case 'b':
					cout << "Ingrese el nombre, apellido o email del usuario a buscar: ";
					cin.ignore();
					getline(cin, atributo);
					gestorUsuarios.buscarUsuario(atributo);
					break;
				case 'C':
				case 'c':
					cout << "Ingrese el nombre, apellido o email del bibliotecario a buscar: ";
					cin.ignore();
					getline(cin, atributo);
					gestorBibliotecarios.buscarBibliotecario(atributo);
					break;
				case 'X':
				case 'x':
					break;
				default:
					cout << "Opción inválida. Intente de nuevo." << endl;
				}
			} while (opcionBusquedas != 'X' && opcionBusquedas != 'x');
			break;
		}
		case '0':
			cout << "Saliendo del programa." << endl;
			break;
		default:
			cout << "Opción inválida. Intente de nuevo." << endl;
		}
	} while (opcion != '0');
}

int main() {
	// Crear instancias de los gestores
	GestorUsuarios gestorUsuarios;
	GestorBibliotecarios gestorBibliotecarios;
	GestorLibros gestorLibros;
	
	// Mostrar el menú principal
	mostrarMenuPrincipal(gestorUsuarios, gestorBibliotecarios, gestorLibros);
	
	return 0;
}
