#include <iostream>
#include <vector>
#include <fstream>

int main() {
    // Wstêpny szkielet symulacji - parametry symulacji
    int NX = 100;    // Liczba punktów w kierunku x
    int NY = 100;    // Liczba punktów w kierunku y
    int STEPS = 1000; // Liczba kroków czasowych
    double ALPHA = 0.01; // Wspó³czynnik przewodzenia ciep³a
    double DT = 0.01;  // Krok czasowy
    double DX = 1.0;   // Odleg³oœæ miêdzy wêz³ami w kierunku x
    double DY = 1.0;   // Odleg³oœæ miêdzy wêz³ami w kierunku y

    // Tworzenie siatki temperatury
    std::vector<std::vector<double>> temperature(NX, std::vector<double>(NY, 20.0)); // Wype³niamy wartoœciami pocz¹tkowymi
    std::vector<std::vector<double>> new_temperature = temperature;

    // Ustawienie Ÿród³a ciep³a - œrodek siatki
    temperature[NX / 2][NY / 2] = 100.0;

    // Symulacja algorytmu w pêtli
    for (int step = 0; step < STEPS; ++step) {
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                // Obliczanie nowych wartoœci temperatur na podstawie równania przewodnictwa ciep³a
                double d2Tdx2 = (temperature[i + 1][j] - 2 * temperature[i][j] + temperature[i - 1][j]) / (DX * DX);
                double d2Tdy2 = (temperature[i][j + 1] - 2 * temperature[i][j] + temperature[i][j - 1]) / (DY * DY);
                new_temperature[i][j] = temperature[i][j] + ALPHA * DT * (d2Tdx2 + d2Tdy2);
            }
        }

        // Aktualizowanie siatki temperatur
        temperature = new_temperature;

        // Postêp symulacji
        if (step % 100 == 0) {
            std::cout << "Krok: " << step << " z " << STEPS << std::endl;
        }
    }

    // Zapis koñcowych wyników do pliku
    std::ofstream output("heatmap.txt");
    if (output.is_open()) {
        for (int i = 0; i < NX; ++i) {
            for (int j = 0; j < NY; ++j) {
                output << temperature[i][j] << " ";
            }
            output << "\n";
        }
        output.close();
        std::cout << "Wyniki zapisane do pliku heatmap.txt" << std::endl;
    }
    else {
        std::cerr << "Blad zapisu pliku!" << std::endl;
    }

    return 0;
}
