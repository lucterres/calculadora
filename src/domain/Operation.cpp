#include "domain/Operation.h"
#include <stdexcept>

// Construtor para operações com dois operandos
Operation::Operation(OperationType type, double operand1, double operand2)
    : type(type), operand1(operand1), operand2(operand2) {}

// Construtor para operações com um operando
Operation::Operation(OperationType type, double operand1)
    : type(type), operand1(operand1), operand2(0.0) {}

OperationType Operation::getType() const {
    return type;
}

double Operation::getOperand1() const {
    return operand1;
}

double Operation::getOperand2() const {
    return operand2;
}

std::string Operation::getSymbol() const {
    switch (type) {
        case OperationType::ADD:
            return "+";
        case OperationType::SUBTRACT:
            return "-";
        case OperationType::MULTIPLY:
            return "*";
        case OperationType::DIVIDE:
            return "/";
        case OperationType::POWER:
            return "^";
        case OperationType::SQUARE_ROOT:
            return "sqrt";
        default:
            return "?";
    }
}

bool Operation::isValid() const {
    // Validação específica para divisão por zero
    if (type == OperationType::DIVIDE && operand2 == 0.0) {
        return false;
    }
    
    // Validação para raiz quadrada de número negativo
    if (type == OperationType::SQUARE_ROOT && operand1 < 0.0) {
        return false;
    }
    
    return true;
}
