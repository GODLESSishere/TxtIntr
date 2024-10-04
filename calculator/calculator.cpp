#include <iostream>
#include <cmath>
#include <stdexcept>
#include <getopt.h>

double calculateExp(double x) {
    return exp(x);
}

double calculatePower(double x, double y) {
    return pow(x, y);
}

void printHelp() {
    std::cout << "Использование:\n";
    std::cout << "  -o, --operation <операция>  Выберите операцию (exp или power)\n";
    std::cout << "  количество операндов для функции:\n";
    std::cout << "  exp - 1\n";
    std::cout << "  power - 2\n";
    std::cout << "  ВАЖНО: кальтулятор не работает с отрицательными числами\n";
}

int main(int argc, char* argv[]) {
    int opt;
    int index;
    std::string operation;

    static struct option long_options[] = {
        {"operation", required_argument, 0, 'o'},
        {"help", no_argument, 0, 'h'},
        {0, 0, 0, 0}
    };

    while ((opt = getopt_long(argc, argv, "ho:", long_options, &index)) != -1) {
        switch (opt) {
            case 'o':
                operation = optarg;
                break;
            case 'h':
                printHelp();
                return 0;
            default:
                printHelp();
                return 1;
        }
    }

    if (operation.empty()) {
        printHelp();
        return 1;
    }

    if (operation == "exp" && argc - optind != 1) {
        std::cerr << "Ошибка: Неправильное количество операндов для exp.\n";
        return 1;
    }

    if (operation == "power" && argc - optind != 2) {
        std::cerr << "Ошибка: Неправильное количество операндов для power.\n";
        return 1;
    }

    if (operation == "exp") {
        double x = std::stod(argv[optind]);
        double result = calculateExp(x);
        std::cout << "e^" << x << " = " << result << std::endl;
    } else if (operation == "power") {
        double x = std::stod(argv[optind]);
        double y = std::stod(argv[optind + 1]);
        double result = calculatePower(x, y);
        std::cout << x << "^" << y << " = " << result << std::endl;
    } else {
        std::cerr << "Ошибка: Неизвестная операция.\n";
        return 1;
    }

    return 0;
}
