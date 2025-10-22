#include "usecases/ExecuteOperationUseCase.h"
#include <cmath>
#include <stdexcept>

ExecuteOperationUseCase::ExecuteOperationUseCase(ICalculatorRepository* repository)
    : repository(repository) {}

CalculationResult ExecuteOperationUseCase::execute(const Operation& operation) {
    // Validação da operação
    if (!operation.isValid()) {
        if (operation.getType() == OperationType::DIVIDE) {
            return CalculationResult::Failure("Erro: Divisao por zero nao permitida!");
        }
        if (operation.getType() == OperationType::SQUARE_ROOT) {
            return CalculationResult::Failure("Erro: Raiz quadrada de numero negativo!");
        }
        return CalculationResult::Failure("Erro: Operacao invalida!");
    }

    try {
        // Executa o cálculo
        double result = performCalculation(operation);
        
        // Salva o resultado no repositório
        repository->saveLastResult(result);
        
        return CalculationResult::Success(result);
    } catch (const std::exception& e) {
        return CalculationResult::Failure(std::string("Erro inesperado: ") + e.what());
    }
}

double ExecuteOperationUseCase::performCalculation(const Operation& operation) const {
    double a = operation.getOperand1();
    double b = operation.getOperand2();

    switch (operation.getType()) {
        case OperationType::ADD:
            return a + b;
        
        case OperationType::SUBTRACT:
            return a - b;
        
        case OperationType::MULTIPLY:
            return a * b;
        
        case OperationType::DIVIDE:
            return a / b;
        
        case OperationType::POWER:
            return std::pow(a, b);
        
        case OperationType::SQUARE_ROOT:
            return std::sqrt(a);
        
        default:
            throw std::runtime_error("Tipo de operacao nao reconhecido");
    }
}
