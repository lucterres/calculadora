#ifndef ICALCULATOR_REPOSITORY_H
#define ICALCULATOR_REPOSITORY_H

#include <optional>

/**
 * @brief Interface para repositório de cálculos
 * 
 * Define o contrato para persistência de resultados (Port)
 */
class ICalculatorRepository {
public:
    virtual ~ICalculatorRepository() = default;

    /**
     * @brief Salva o último resultado calculado
     */
    virtual void saveLastResult(double result) = 0;

    /**
     * @brief Recupera o último resultado
     */
    virtual std::optional<double> getLastResult() const = 0;

    /**
     * @brief Limpa o último resultado
     */
    virtual void clearLastResult() = 0;
};

#endif // ICALCULATOR_REPOSITORY_H
