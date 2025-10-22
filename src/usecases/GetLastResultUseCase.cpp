#include "usecases/GetLastResultUseCase.h"

GetLastResultUseCase::GetLastResultUseCase(ICalculatorRepository* repository)
    : repository(repository) {}

std::optional<double> GetLastResultUseCase::execute() const {
    return repository->getLastResult();
}

void GetLastResultUseCase::clear() {
    repository->clearLastResult();
}
