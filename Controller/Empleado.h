#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

class Empleado {
public:
    std::string codigo;
    std::string nombre;
    std::string dui;
    std::string departamento;
    std::string cargo;
    std::string estado;

    Empleado() = default;

    Empleado(std::string c, std::string n, std::string d, std::string dept, std::string car, std::string est)
        : codigo(c), nombre(n), dui(d), departamento(dept), cargo(car), estado(est) {}
};

#endif
