#ifndef CONSOLE_INPUT_HANDLER_H
#define CONSOLE_INPUT_HANDLER_H

#include <string>

/**
 * @brief Manipulador de entrada do console
 * 
 * Gerencia a leitura de entrada do usuário (Adapter)
 */
class ConsoleInputHandler {
public:
    /**
     * @brief Lê um número inteiro do usuário
     */
    int readInt(const std::string& prompt) const;

    /**
     * @brief Lê um número double do usuário com validação
     */
    double readDouble(const std::string& prompt) const;
};

#endif // CONSOLE_INPUT_HANDLER_H
