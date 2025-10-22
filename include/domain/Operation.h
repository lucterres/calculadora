#ifndef OPERATION_H
#define OPERATION_H

#include <string>

/**
 * @brief Enum que representa os tipos de operações matemáticas
 */
enum class OperationType {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE,
    POWER,
    SQUARE_ROOT
};

/**
 * @brief Classe de domínio que representa uma operação matemática
 * 
 * Esta é uma entidade pura de domínio, sem dependências externas
 */
class Operation {
private:
    OperationType type;
    double operand1;
    double operand2;

public:
    /**
     * @brief Construtor para operações com dois operandos
     */
    Operation(OperationType type, double operand1, double operand2);

    /**
     * @brief Construtor para operações com um operando (ex: raiz quadrada)
     */
    Operation(OperationType type, double operand1);

    /**
     * @brief Retorna o tipo da operação
     */
    OperationType getType() const;

    /**
     * @brief Retorna o primeiro operando
     */
    double getOperand1() const;

    /**
     * @brief Retorna o segundo operando
     */
    double getOperand2() const;

    /**
     * @brief Retorna o símbolo da operação como string
     */
    std::string getSymbol() const;

    /**
     * @brief Verifica se a operação é válida
     */
    bool isValid() const;
};

#endif // OPERATION_H
