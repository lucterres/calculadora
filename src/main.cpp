#include <iostream>
#include <exception>
#include <limits>
#include "calculator.h"
#include "utils.h"

int main() {
    Calculator calc;
    int choice;
    double a, b, result;
    bool running = true;

    std::cout << "Bem-vindo a Calculadora C++!\n";

    while (running) {
        displayMenu();
        std::cout << "Escolha uma opcao: ";
        std::cin >> choice;

        // Limpa o buffer de entrada
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "\nOpcao invalida! Tente novamente.\n";
            pauseExecution();
            clearScreen();
            continue;
        }

        clearScreen();

        try {
            switch (choice) {
                case 1: // Adição
                    std::cout << "=== ADICAO ===\n";
                    a = readDouble("Digite o primeiro numero: ");
                    b = readDouble("Digite o segundo numero: ");
                    result = calc.add(a, b);
                    std::cout << "\nResultado: " << a << " + " << b << " = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 2: // Subtração
                    std::cout << "=== SUBTRACAO ===\n";
                    a = readDouble("Digite o primeiro numero: ");
                    b = readDouble("Digite o segundo numero: ");
                    result = calc.subtract(a, b);
                    std::cout << "\nResultado: " << a << " - " << b << " = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 3: // Multiplicação
                    std::cout << "=== MULTIPLICACAO ===\n";
                    a = readDouble("Digite o primeiro numero: ");
                    b = readDouble("Digite o segundo numero: ");
                    result = calc.multiply(a, b);
                    std::cout << "\nResultado: " << a << " * " << b << " = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 4: // Divisão
                    std::cout << "=== DIVISAO ===\n";
                    a = readDouble("Digite o dividendo: ");
                    b = readDouble("Digite o divisor: ");
                    result = calc.divide(a, b);
                    std::cout << "\nResultado: " << a << " / " << b << " = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 5: // Potenciação
                    std::cout << "=== POTENCIACAO ===\n";
                    a = readDouble("Digite a base: ");
                    b = readDouble("Digite o expoente: ");
                    result = calc.power(a, b);
                    std::cout << "\nResultado: " << a << " ^ " << b << " = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 6: // Raiz Quadrada
                    std::cout << "=== RAIZ QUADRADA ===\n";
                    a = readDouble("Digite o numero: ");
                    result = calc.squareRoot(a);
                    std::cout << "\nResultado: sqrt(" << a << ") = " << formatResult(result) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 7: // Limpar Resultado
                    calc.clearResult();
                    std::cout << "Resultado limpo!\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 8: // Mostrar Último Resultado
                    std::cout << "Ultimo resultado: " << formatResult(calc.getResult()) << "\n";
                    pauseExecution();
                    clearScreen();
                    break;

                case 0: // Sair
                    std::cout << "Encerrando calculadora. Ate logo!\n";
                    running = false;
                    break;

                default:
                    std::cout << "Opcao invalida! Escolha um numero entre 0 e 8.\n";
                    pauseExecution();
                    clearScreen();
                    break;
            }
        } catch (const std::invalid_argument& e) {
            std::cout << "\n" << e.what() << "\n";
            pauseExecution();
            clearScreen();
        } catch (const std::exception& e) {
            std::cout << "\nErro inesperado: " << e.what() << "\n";
            pauseExecution();
            clearScreen();
        }
    }

    return 0;
}
