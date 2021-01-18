//
// Created by noel on 8/1/21.
//

#ifndef PROYECTOSO_TRANSPORTE_H
#define PROYECTOSO_TRANSPORTE_H
#include <String.h>
using namespace std;
class Transporte {
private:
    int capacidad;
    String nombre;
    String cedulaPropetario;
    String vehiculo;
    String placa;
public:
    Transporte(int capacidad, const String &nombre, const String &cedulaPropetario, const String &vehiculo,
               const String &placa);

    int getCapacidad() const;

    void setCapacidad(int capacidad);

    const String &getNombre() const;

    void setNombre(const String &nombre);

    const String &getCedulaPropetario() const;

    void setCedulaPropetario(const String &cedulaPropetario);

    const String &getVehiculo() const;

    void setVehiculo(const String &vehiculo);

    const String &getPlaca() const;

    void setPlaca(const String &placa);
};


#endif //PROYECTOSO_TRANSPORTE_H
