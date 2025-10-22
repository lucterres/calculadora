#ifndef IN_MEMORY_CALCULATOR_REPOSITORY_H
#define IN_MEMORY_CALCULATOR_REPOSITORY_H

#include "interfaces/ICalculatorRepository.h"
#include <optional>

/**
 * @brief Implementação de repositório em memória
 * 
 * Armazena o último resultado em memória (Adapter)
 */
class InMemoryCalculatorRepository : public ICalculatorRepository {
private:
    std::optional<double> lastResult;

public:
    InMemoryCalculatorRepository();

    void saveLastResult(double result) override;
    std::optional<double> getLastResult() const override;
    void clearLastResult() override;
};

#endif // IN_MEMORY_CALCULATOR_REPOSITORY_H
