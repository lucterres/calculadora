#include "utils.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>

// Limpa a tela do console
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Exibe o menu principal
void displayMenu() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "        CALCULADORA C++                 \n";
    std::cout << "========================================\n";
    std::cout << " 1. Adicao (+)\n";
    std::cout << " 2. Subtracao (-)\n";
    std::cout << " 3. Multiplicacao (*)\n";
    std::cout << " 4. Divisao (/)\n";
    std::cout << " 5. Potenciacao (^)\n";
    std::cout << " 6. Raiz Quadrada (sqrt)\n";
    std::cout << " 7. Limpar Resultado\n";
    std::cout << " 8. Mostrar Ultimo Resultado\n";
    std::cout << " 0. Sair\n";
    std::cout << "========================================\n";
}

// Lê um número double do usuário
double readDouble(const std::string& prompt) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Entrada invalida! Por favor, digite um numero.\n";
        } else {
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }
}

// Formata o resultado para exibição
std::string formatResult(double value) {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4) << value;
    return oss.str();
}

// Pausa a execução
void pauseExecution() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}
