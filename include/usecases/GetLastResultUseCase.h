#ifndef GET_LAST_RESULT_USE_CASE_H
#define GET_LAST_RESULT_USE_CASE_H

#include <optional>
#include "interfaces/ICalculatorRepository.h"

/**
 * @brief Caso de uso para recuperar o último resultado
 */
class GetLastResultUseCase {
private:
    ICalculatorRepository* repository;

public:
    /**
     * @brief Construtor com injeção de dependência
     */
    explicit GetLastResultUseCase(ICalculatorRepository* repository);

    /**
     * @brief Retorna o último resultado calculado
     */
    std::optional<double> execute() const;

    /**
     * @brief Limpa o último resultado
     */
    void clear();
};

#endif // GET_LAST_RESULT_USE_CASE_H
