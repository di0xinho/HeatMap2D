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
    std::vector<std::vector<double>> temperature(NX, std::vector<double>(NY, 0.0));

    // Ustawienie temperatury w jednym punkcie - jak narazie podstawowy test
    temperature[50][50] = 100.0; // Temperatura pocz¹tkowa w punkcie (50, 50)

    // Wyœwietlam pocz¹tkow¹ temperaturê w punkcie (50, 50), czyli w samym œrodku siatki
    std::cout << "Poczatkowa temperatura w punkcie (50, 50): " << temperature[50][50] << std::endl;

    // Zapisujê do pliku wyjœciowego
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
