#include "calculator.h"
#include <cmath>

// Construtor
Calculator::Calculator() : result(0.0) {}

// Adição
double Calculator::add(double a, double b) {
    result = a + b;
    return result;
}

// Subtração
double Calculator::subtract(double a, double b) {
    result = a - b;
    return result;
}

// Multiplicação
double Calculator::multiply(double a, double b) {
    result = a * b;
    return result;
}

// Divisão
double Calculator::divide(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("Erro: Divisao por zero nao permitida!");
    }
    result = a / b;
    return result;
}

// Potenciação
double Calculator::power(double base, double exponent) {
    result = std::pow(base, exponent);
    return result;
}

// Raiz quadrada
double Calculator::squareRoot(double n) {
    if (n < 0.0) {
        throw std::invalid_argument("Erro: Raiz quadrada de numero negativo!");
    }
    result = std::sqrt(n);
    return result;
}

// Retorna o último resultado
double Calculator::getResult() const {
    return result;
}

// Limpa o resultado
void Calculator::clearResult() {
    result = 0.0;
}
