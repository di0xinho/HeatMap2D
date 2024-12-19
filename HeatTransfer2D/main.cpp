#include <iostream>
#include <vector>
#include <fstream>

int main() {
    // Wst�pny szkielet symulacji - parametry symulacji
    int NX = 100;    // Liczba punkt�w w kierunku x
    int NY = 100;    // Liczba punkt�w w kierunku y
    int STEPS = 1000; // Liczba krok�w czasowych
    double ALPHA = 0.01; // Wsp�czynnik przewodzenia ciep�a
    double DT = 0.01;  // Krok czasowy
    double DX = 1.0;   // Odleg�o�� mi�dzy w�z�ami w kierunku x
    double DY = 1.0;   // Odleg�o�� mi�dzy w�z�ami w kierunku y

    // Tworzenie siatki temperatury
    std::vector<std::vector<double>> temperature(NX, std::vector<double>(NY, 20.0)); // Wype�niamy warto�ciami pocz�tkowymi
    std::vector<std::vector<double>> new_temperature = temperature;

    // Ustawienie �r�d�a ciep�a - �rodek siatki
    temperature[NX / 2][NY / 2] = 100.0;

    // Symulacja algorytmu w p�tli
    for (int step = 0; step < STEPS; ++step) {
        for (int i = 1; i < NX - 1; ++i) {
            for (int j = 1; j < NY - 1; ++j) {
                // Obliczanie nowych warto�ci temperatur na podstawie r�wnania przewodnictwa ciep�a
                double d2Tdx2 = (temperature[i + 1][j] - 2 * temperature[i][j] + temperature[i - 1][j]) / (DX * DX);
                double d2Tdy2 = (temperature[i][j + 1] - 2 * temperature[i][j] + temperature[i][j - 1]) / (DY * DY);
                new_temperature[i][j] = temperature[i][j] + ALPHA * DT * (d2Tdx2 + d2Tdy2);
            }
        }

        // Aktualizowanie siatki temperatur
        temperature = new_temperature;

        // Post�p symulacji
        if (step % 100 == 0) {
            std::cout << "Krok: " << step << " z " << STEPS << std::endl;
        }
    }

    // Zapis ko�cowych wynik�w do pliku
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
