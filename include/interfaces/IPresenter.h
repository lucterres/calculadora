#ifndef IPRESENTER_H
#define IPRESENTER_H

#include <string>
#include "domain/CalculationResult.h"

/**
 * @brief Interface para apresentação de resultados
 * 
 * Define o contrato para exibição de informações ao usuário (Port)
 */
class IPresenter {
public:
    virtual ~IPresenter() = default;

    /**
     * @brief Exibe o resultado de uma operação
     */
    virtual void presentResult(const CalculationResult& result) = 0;

    /**
     * @brief Exibe uma mensagem
     */
    virtual void presentMessage(const std::string& message) = 0;

    /**
     * @brief Exibe o menu principal
     */
    virtual void presentMenu() = 0;

    /**
     * @brief Limpa a tela
     */
    virtual void clearScreen() = 0;

    /**
     * @brief Pausa a execução
     */
    virtual void pause() = 0;
};

#endif // IPRESENTER_H
