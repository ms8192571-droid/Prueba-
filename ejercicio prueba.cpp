#include <iostream>
#include <iomanip>
using namespace std;

class RegistroTemperaturas {
private:
    double* lecturas;
    int capacidad;
    int cantidad;

public:
    RegistroTemperaturas(int cap) : capacidad(cap), cantidad(0) {
        lecturas = new double[capacidad];
    }

    ~RegistroTemperaturas() {
        delete[] lecturas;
        lecturas = nullptr;
    }

    void agregar(double temp) {
        if (temp < 50.0 || temp > 60.0) {
            cout << "Temperatura invalida." << endl;
            return;
        }

        if (cantidad >= capacidad) {
            cout << "Registro lleno." << endl;
            return;
        }

        lecturas[cantidad++] = temp;
    } 

    double promedio() const {
        if (cantidad == 0)
            return 0.0;

        double suma = 0;

        for (int i = 0; i < cantidad; i++)
            suma += lecturas[i];

        return suma / cantidad;
    }

    double maxima() const {
        if (cantidad == 0)
            return 0.0;

        double max = lecturas[0];

        for (int i = 1; i < cantidad; i++) {
            if (lecturas[i] > max)
                max = lecturas[i];
        }

        return max;
    }

    double minima() const {
        if (cantidad == 0)
            return 0.0;

        double min = lecturas[0];

        for (int i = 1; i < cantidad; i++) {
            if (lecturas[i] < min)
                min = lecturas[i];
        }

        return min;
    }

    void imprimir() const {
        for (int i = 0; i < cantidad; i++) {
            cout << setprecision(1) << lecturas[i];

            if (i < cantidad - 1)
                cout << " ";
        }

        cout << endl;
    }
};

void resumen(const RegistroTemperaturas& reg) {
    cout << "Temperaturas: ";
    reg.imprimir();

    cout << setprecision(2);
    cout << "Promedio : " << reg.promedio() << endl;
    cout << "Maxima   : " << reg.maxima() << endl;
    cout << "Minima   : " << reg.minima() << endl;
}

    return 0;
}
