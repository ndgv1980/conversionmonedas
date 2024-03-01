#include <stdio.h>

enum MONEDAS {quetzal, dolar, euro};

struct TIPO 
{
    enum MONEDAS moneda1;
    enum MONEDAS moneda2;
    float valor;
};

struct TIPO tabla_conversion[3];

void setTablaConversion()
{
    tabla_conversion[0].moneda1 = quetzal;
    tabla_conversion[0].moneda2 = dolar;
    tabla_conversion[0].valor = 0.125;
    
    tabla_conversion[1].moneda1 = quetzal;
    tabla_conversion[1].moneda2 = euro;
    tabla_conversion[1].valor = 0.12;
    
    tabla_conversion[2].moneda1 = dolar;
    tabla_conversion[2].moneda2 = euro;
    tabla_conversion[2].valor = 0.8;
}

int leerMoneda ()
{
    int moneda;
    printf("1. Quetzal\n2. Dolar\n3. Euro\n");
    printf("Elija una moneda: ");
    scanf("%d", &moneda);
    return moneda;
}

float obtenerMonto()
{
    float monto;
    printf("Ingrese el monto: ");
    scanf("%f", &monto);
    return monto;
}

float convertir(int m1, int m2, float m)
{
    if (m1 == m2)
        return m;
    else if ((m1 == 1) && (m2 == 2))
            return m * tabla_conversion[0].valor;
    else if ((m1 == 2) && (m2 == 1))
            return m / tabla_conversion[0].valor;
    else if ((m1 == 1) && (m2 == 3))
            return m * tabla_conversion[1].valor;
    else if ((m1 == 3) && (m2 == 1))
        return m / tabla_conversion[1].valor;
    else if ((m1 == 2) && (m2 == 3))
        return m * tabla_conversion[2].valor;
    else if ((m1 == 3) && (m2 == 2))
        return m / tabla_conversion[2].valor;
}

void mostrarMoneda(int moneda)
{
    switch (moneda)
    {
        case 1: printf("quetzales");
        break;
        case 2: printf("dólares");
        break;
        case 3: printf("euros");
    }
}

int main()
{
    setTablaConversion();
    
    int moneda1 = 0, moneda2 = 0;
    float monto_i = 0.0, monto_o = 0.0;
    
    moneda1 = leerMoneda();
    moneda2 = leerMoneda();
    monto_i = obtenerMonto();
    monto_o = convertir(moneda1, moneda2, monto_i);
    
    printf("La cantidad de %f ", monto_i);
    mostrarMoneda(moneda1);
    printf(" es equivalente a %f ", monto_o);
    mostrarMoneda(moneda2);
    
    return 0;
}
