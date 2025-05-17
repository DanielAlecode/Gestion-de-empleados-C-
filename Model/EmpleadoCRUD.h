#ifndef EMPLEADOCRUD_H
#define EMPLEADOCRUD_H

#include "../Controller/Empleado.h"
#include <vector>

class EmpleadoCRUD {
public:
    void crearEmpleado(const Empleado& empleado);
    std::vector<Empleado> leerEmpleados();
    void actualizarEmpleado(const std::string& codigo, const Empleado& nuevoEmpleado);
    void eliminarEmpleado(const std::string& codigo);
};

#endif
