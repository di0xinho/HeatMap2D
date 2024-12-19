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
    std::vector<std::vector<double>> temperature(NX, std::vector<double>(NY, 0.0));

    // Ustawienie temperatury w jednym punkcie - jak narazie podstawowy test
    temperature[50][50] = 100.0; // Temperatura pocz�tkowa w punkcie (50, 50)

    // Wy�wietlam pocz�tkow� temperatur� w punkcie (50, 50), czyli w samym �rodku siatki
    std::cout << "Poczatkowa temperatura w punkcie (50, 50): " << temperature[50][50] << std::endl;

    // Zapisuj� do pliku wyj�ciowego
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
