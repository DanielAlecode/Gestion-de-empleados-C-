#include "EmpleadoCRUD.h"
#include <fstream>
#include <sstream>
#include <iostream>

void EmpleadoCRUD::crearEmpleado(const Empleado& e) {
    std::ofstream file("empleados.txt", std::ios::app);
    file << e.codigo << "," << e.nombre << "," << e.dui << "," << e.departamento << ","
         << e.cargo << "," << e.estado << "\n";
    file.close();
}

std::vector<Empleado> EmpleadoCRUD::leerEmpleados() {
    std::ifstream file("empleados.txt");
    std::vector<Empleado> lista;
    std::string linea;

    while (getline(file, linea)) {
        std::stringstream ss(linea);
        std::string codigo, nombre, dui, departamento, cargo, estado;

        getline(ss, codigo, ',');
        getline(ss, nombre, ',');
        getline(ss, dui, ',');
        getline(ss, departamento, ',');
        getline(ss, cargo, ',');
        getline(ss, estado, ',');

        lista.push_back(Empleado(codigo, nombre, dui, departamento, cargo, estado));
    }

    return lista;
}

void EmpleadoCRUD::actualizarEmpleado(const std::string& codigo, const Empleado& nuevo) {
    std::vector<Empleado> lista = leerEmpleados();
    std::ofstream file("empleados.txt", std::ios::trunc);

    for (auto& emp : lista) {
        if (emp.codigo == codigo) {
            emp = nuevo;
        }
        file << emp.codigo << "," << emp.nombre << "," << emp.dui << "," << emp.departamento << ","
             << emp.cargo << "," << emp.estado << "\n";
    }
    file.close();
}

void EmpleadoCRUD::eliminarEmpleado(const std::string& codigo) {
    std::vector<Empleado> lista = leerEmpleados();
    std::ofstream file("empleados.txt", std::ios::trunc);

    for (const auto& emp : lista) {
        if (emp.codigo != codigo) {
            file << emp.codigo << "," << emp.nombre << "," << emp.dui << "," << emp.departamento << ","
                 << emp.cargo << "," << emp.estado << "\n";
        }
    }
    file.close();
}
