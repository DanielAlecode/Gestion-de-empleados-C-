#include "../Model/EmpleadoCRUD.h"
#include <iostream>

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
    std::cout << "Codigo: "; std::getline(std::cin, c);
    std::cout << "Nombre completo: "; std::getline(std::cin, n);
    std::cout << "DUI: "; std::getline(std::cin, d);
    std::cout << "Departamento: "; std::getline(std::cin, dept);
    std::cout << "Cargo: "; std::getline(std::cin, car);
    std::cout << "Estado (Activo/Inactivo): "; std::getline(std::cin, est);
    return Empleado(c, n, d, dept, car, est);
}

int main() {
    EmpleadoCRUD crud;
    int opcion;
    std::string codigo;

    do {
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Limpiar buffer

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
