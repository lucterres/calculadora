#ifndef CALCULATOR_H
#define CALCULATOR_H

#include <stdexcept>

/**
 * @brief Classe Calculator para operações matemáticas
 * 
 * Implementa operações básicas e avançadas com tratamento de erros
 */
class Calculator {
private:
    double result;

public:
    /**
     * @brief Construtor padrão
     */
    Calculator();

    /**
     * @brief Realiza adição de dois números
     * @param a Primeiro operando
     * @param b Segundo operando
     * @return Soma de a e b
     */
    double add(double a, double b);

    /**
     * @brief Realiza subtração de dois números
     * @param a Primeiro operando
     * @param b Segundo operando
     * @return Diferença entre a e b
     */
    double subtract(double a, double b);

    /**
     * @brief Realiza multiplicação de dois números
     * @param a Primeiro operando
     * @param b Segundo operando
     * @return Produto de a e b
     */
    double multiply(double a, double b);

    /**
     * @brief Realiza divisão de dois números
     * @param a Dividendo
     * @param b Divisor
     * @return Quociente de a por b
     * @throws std::invalid_argument Se b for zero
     */
    double divide(double a, double b);

    /**
     * @brief Calcula a potência de um número
     * @param base Base da potência
     * @param exponent Expoente
     * @return base elevado a exponent
     */
    double power(double base, double exponent);

    /**
     * @brief Calcula a raiz quadrada de um número
     * @param n Número para calcular a raiz
     * @return Raiz quadrada de n
     * @throws std::invalid_argument Se n for negativo
     */
    double squareRoot(double n);

    /**
     * @brief Retorna o último resultado calculado
     * @return Valor do último resultado
     */
    double getResult() const;

    /**
     * @brief Limpa o resultado armazenado
     */
    void clearResult();
};

#endif // CALCULATOR_H
