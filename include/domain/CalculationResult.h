#ifndef CALCULATION_RESULT_H
#define CALCULATION_RESULT_H

#include <string>
#include <optional>

/**
 * @brief Classe de domínio que representa o resultado de uma operação
 * 
 * Encapsula o resultado ou erro de uma operação matemática
 */
class CalculationResult {
private:
    std::optional<double> value;
    std::string errorMessage;
    bool success;

public:
    /**
     * @brief Construtor para resultado bem-sucedido
     */
    static CalculationResult Success(double value);

    /**
     * @brief Construtor para resultado com erro
     */
    static CalculationResult Failure(const std::string& errorMessage);

    /**
     * @brief Verifica se a operação foi bem-sucedida
     */
    bool isSuccess() const;

    /**
     * @brief Retorna o valor do resultado (se sucesso)
     */
    double getValue() const;

    /**
     * @brief Retorna a mensagem de erro (se falha)
     */
    std::string getErrorMessage() const;

private:
    CalculationResult(bool success, std::optional<double> value, const std::string& error);
};

#endif // CALCULATION_RESULT_H
