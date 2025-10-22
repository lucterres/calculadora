#ifndef CONSOLE_PRESENTER_H
#define CONSOLE_PRESENTER_H

#include "interfaces/IPresenter.h"

/**
 * @brief Implementação de apresentador para console
 * 
 * Exibe informações no console (Adapter)
 */
class ConsolePresenter : public IPresenter {
public:
    void presentResult(const CalculationResult& result) override;
    void presentMessage(const std::string& message) override;
    void presentMenu() override;
    void clearScreen() override;
    void pause() override;

private:
    std::string formatResult(double value) const;
};

#endif // CONSOLE_PRESENTER_H
