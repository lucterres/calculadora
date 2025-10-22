#ifndef EXECUTE_OPERATION_USE_CASE_H
#define EXECUTE_OPERATION_USE_CASE_H

#include "domain/Operation.h"
#include "domain/CalculationResult.h"
#include "interfaces/ICalculatorRepository.h"

/**
 * @brief Caso de uso para executar operações matemáticas
 * 
 * Orquestra a lógica de negócio para realizar cálculos
 */
class ExecuteOperationUseCase {
private:
    ICalculatorRepository* repository;

    double performCalculation(const Operation& operation) const;

public:
    /**
     * @brief Construtor com injeção de dependência
     */
    explicit ExecuteOperationUseCase(ICalculatorRepository* repository);

    /**
     * @brief Executa uma operação matemática
     * @param operation A operação a ser executada
     * @return Resultado da operação ou erro
     */
    CalculationResult execute(const Operation& operation);
};

#endif // EXECUTE_OPERATION_USE_CASE_H
