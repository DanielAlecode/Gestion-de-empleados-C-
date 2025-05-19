#include "../Model/EmpleadoCRUD.h"
#include <iostream>
#include <algorithm>
#include <cctype>
#include <regex>

// Validacion del formato del DUI 
bool validarDUI(const std::string& dui) {
    std::regex pattern("^\\d{8}-\\d$");
    return std::regex_match(dui, pattern);
}


//Funcion para convertir a minusculas en los estados para evitar errores y estandarizar el texto
std::string toMinusculas(const std::string& s) {
    std::string copia = s;
    std::transform(copia.begin(), copia.end(), copia.begin(),
                   [](unsigned char c){ return std::tolower(c); });
    return copia;
}

void mostrarMenu() {
    std::cout << "===== CRUD EMPLEADOS =====\n";
    std::cout << "1. Crear empleado\n";
    std::cout << "2. Listar empleados\n";
    std::cout << "3. Actualizar empleado\n";
    std::cout << "4. Eliminar empleado\n";
    std::cout << "5. Salir\n";
    std::cout << "Opcion: ";
}

Empleado capturarEmpleado() {
    std::string c, n, d, dept, car, est;

    do {
        std::cout << "Codigo: ";
        std::getline(std::cin, c);
        if (c.empty()) std::cout << "El codigo no puede estar vacio.\n";
    } while (c.empty());

    do {
        std::cout << "Nombre completo: ";
        std::getline(std::cin, n);
        if (n.empty()) std::cout << "El nombre no puede estar vacio.\n";
    } while (n.empty());

    do {
        std::cout << "DUI (formato 12345678-9): ";
        std::getline(std::cin, d);
        if (!validarDUI(d)) std::cout << "Formato de DUI invalido.\n";
    } while (!validarDUI(d));

    do {
        std::cout << "Departamento: ";
        std::getline(std::cin, dept);
        if (dept.empty()) std::cout << "El departamento no puede estar vacio.\n";
    } while (dept.empty());

    do {
        std::cout << "Cargo: ";
        std::getline(std::cin, car);
        if (car.empty()) std::cout << "El cargo no puede estar vacio.\n";
    } while (car.empty());

    do {
        std::cout << "Estado (Activo/Inactivo): ";
        std::getline(std::cin, est);
        std::string eMin = toMinusculas(est);
        if (eMin != "activo" && eMin != "inactivo") {
            std::cout << "Estado invalido.\n";
        } else {
            est = eMin;
            est[0] = std::toupper(est[0]);
            break;
        }
    } while (true);

    return Empleado(c, n, d, dept, car, est);
}

int main() {
    EmpleadoCRUD crud;
    int opcion;
    std::string codigo;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: {
                Empleado nuevo = capturarEmpleado();
                crud.crearEmpleado(nuevo);
                break;
            }
            case 2: {
                auto empleados = crud.leerEmpleados();
                for (const auto& e : empleados) {
                    std::cout << e.codigo << " | " << e.nombre << " | " << e.dui
                              << " | " << e.departamento << " | " << e.cargo
                              << " | " << e.estado << "\n";
                }
                break;
            }
            case 3: {
                std::cout << "Codigo a actualizar: ";
                std::getline(std::cin, codigo);
                Empleado nuevo = capturarEmpleado();
                crud.actualizarEmpleado(codigo, nuevo);
                break;
            }
            case 4: {
                std::cout << "Codigo a eliminar: ";
                std::getline(std::cin, codigo);
                crud.eliminarEmpleado(codigo);
                break;
            }
            case 5:
                std::cout << "Saliendo...\n";
                break;
            default:
                std::cout << "Opcion invalida.\n";
        }

    } while (opcion != 5);

    return 0;
}
