#include "presentation/ConsolePresenter.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <iomanip>
#include <cstdlib>

void ConsolePresenter::presentResult(const CalculationResult& result) {
    if (result.isSuccess()) {
        std::cout << "\nResultado: " << formatResult(result.getValue()) << "\n";
    } else {
        std::cout << "\n" << result.getErrorMessage() << "\n";
    }
}

void ConsolePresenter::presentMessage(const std::string& message) {
    std::cout << message << "\n";
}

void ConsolePresenter::presentMenu() {
    std::cout << "\n";
    std::cout << "========================================\n";
    std::cout << "        CALCULADORA C++                 \n";
    std::cout << "        (Clean Architecture)            \n";
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

void ConsolePresenter::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void ConsolePresenter::pause() {
    std::cout << "\nPressione ENTER para continuar...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

std::string ConsolePresenter::formatResult(double value) const {
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(4) << value;
    return oss.str();
}
