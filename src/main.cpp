#include <iostream>
#include <memory>
#include "domain/Operation.h"
#include "infrastructure/InMemoryCalculatorRepository.h"
#include "presentation/ConsolePresenter.h"
#include "presentation/ConsoleInputHandler.h"
#include "usecases/ExecuteOperationUseCase.h"
#include "usecases/GetLastResultUseCase.h"

/**
 * @brief Composition Root - Ponto de entrada com Dependency Injection
 * 
 * Aplica Clean Architecture injetando dependências e conectando todas as camadas
 */
int main() {
    // Dependency Injection - Criação das dependências
    InMemoryCalculatorRepository repository;
    ConsolePresenter presenter;
    ConsoleInputHandler inputHandler;
    
    // Criação dos Use Cases com dependências injetadas
    ExecuteOperationUseCase executeOperation(&repository);
    GetLastResultUseCase getLastResult(&repository);
    
    // Interface do usuário
    std::cout << "Bem-vindo a Calculadora C++ com Clean Architecture!\n";
    
    bool running = true;
    while (running) {
        presenter.presentMenu();
        int choice = inputHandler.readInt("Escolha uma opcao: ");
        
        presenter.clearScreen();
        
        try {
            switch (choice) {
                case 1: { // Adição
                    std::cout << "=== ADICAO ===\n";
                    double a = inputHandler.readDouble("Digite o primeiro numero: ");
                    double b = inputHandler.readDouble("Digite o segundo numero: ");
                    Operation op(OperationType::ADD, a, b);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 2: { // Subtração
                    std::cout << "=== SUBTRACAO ===\n";
                    double a = inputHandler.readDouble("Digite o primeiro numero: ");
                    double b = inputHandler.readDouble("Digite o segundo numero: ");
                    Operation op(OperationType::SUBTRACT, a, b);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 3: { // Multiplicação
                    std::cout << "=== MULTIPLICACAO ===\n";
                    double a = inputHandler.readDouble("Digite o primeiro numero: ");
                    double b = inputHandler.readDouble("Digite o segundo numero: ");
                    Operation op(OperationType::MULTIPLY, a, b);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 4: { // Divisão
                    std::cout << "=== DIVISAO ===\n";
                    double a = inputHandler.readDouble("Digite o dividendo: ");
                    double b = inputHandler.readDouble("Digite o divisor: ");
                    Operation op(OperationType::DIVIDE, a, b);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 5: { // Potenciação
                    std::cout << "=== POTENCIACAO ===\n";
                    double a = inputHandler.readDouble("Digite a base: ");
                    double b = inputHandler.readDouble("Digite o expoente: ");
                    Operation op(OperationType::POWER, a, b);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 6: { // Raiz Quadrada
                    std::cout << "=== RAIZ QUADRADA ===\n";
                    double a = inputHandler.readDouble("Digite o numero: ");
                    Operation op(OperationType::SQUARE_ROOT, a, 0.0);
                    presenter.presentResult(executeOperation.execute(op));
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 7: { // Limpar Resultado
                    repository.clearLastResult();
                    presenter.presentMessage("Resultado limpo!");
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 8: { // Mostrar Último Resultado
                    auto result = getLastResult.execute();
                    if (result.has_value()) {
                        std::cout << "Ultimo resultado: " << result.value() << "\n";
                    } else {
                        presenter.presentMessage("Nenhum resultado armazenado.");
                    }
                    presenter.pause();
                    presenter.clearScreen();
                    break;
                }
                
                case 0: { // Sair
                    presenter.presentMessage("Encerrando calculadora. Ate logo!");
                    running = false;
                    break;
                }
                
                default:
                    presenter.presentMessage("Opcao invalida! Escolha um numero entre 0 e 8.");
                    presenter.pause();
                    presenter.clearScreen();
                    break;
            }
        } catch (const std::exception& e) {
            presenter.presentMessage(std::string("Erro: ") + e.what());
            presenter.pause();
            presenter.clearScreen();
        }
    }
    
    return 0;
}
