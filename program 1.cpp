#include <iostream>
#include <cmath>
#include <stdexcept>

// Function to calculate the sum of the series
double calculateSeries(int n) {
    double sum = 0.0;
    for (int i = 1; i <= n; i++) {
        double term = pow(-1.0, i + 1) / pow(i, i);
        sum += term;
    }
    return sum;
}

int main(int argc, char* argv[]) {
    int n;

    // Check if command line argument is provided
    if (argc > 1) {
        try {
            n = std::stoi(argv[1]);
            if (n <= 0) {
                throw std::invalid_argument("n must be a positive integer");
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
            return 1;
        }
    } else {
        // Prompt user to enter the value of n
        std::cout << "Enter the number of terms (n): ";
        std::cin >> n;
        while (n <= 0) {
            std::cout << "Error: n must be a positive integer. Try again: ";
            std::cin >> n;
        }
    }

    double sum = calculateSeries(n);
    std::cout << "Sum of the series: " << sum << std::endl;

    return 0;
}
