#ifndef UTILS_H
#define UTILS_H

#include <string>

/**
 * @brief Limpa a tela do console
 */
void clearScreen();

/**
 * @brief Exibe o menu principal da calculadora
 */
void displayMenu();

/**
 * @brief Lê um número double do usuário com validação
 * @param prompt Mensagem a ser exibida ao usuário
 * @return Número lido
 */
double readDouble(const std::string& prompt);

/**
 * @brief Formata um resultado para exibição
 * @param value Valor a ser formatado
 * @return String formatada
 */
std::string formatResult(double value);

/**
 * @brief Pausa a execução aguardando input do usuário
 */
void pauseExecution();

#endif // UTILS_H
