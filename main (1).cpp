#include <iostream>
#include <algorithm>
#include <cmath>    
#include <iomanip> 
#include <string>

bool IsRightTriangle(double a, double b, double c) {
    double sides[3] = {a, b, c};
    
    std::sort(sides, sides + 3);
    
    double x = sides[0];
    double y = sides[1];
    double z = sides[2];

    if (x <= 0 || (x + y <= z)) {
        return false;
}
    
    return std::abs(x * x + y * y - z * z) < 1e-9;
}

int main() {
    double a, b, c;

    for (int i = 0; i < 3; i++) {
        std::cout << "Введіть сторони a, b, c для трикутника " << i + 1 << ": ";
        std::cin >> a >> b >> c;

        bool is_right = IsRightTriangle(a, b, c);
        std::string result_text = is_right ? "Прямокутний" : "НЕ прямокутний";

        std::cout << "Результат: " << result_text 
                  << " (" << (is_right ? "true" : "false") << ")\n" << std::endl;
    }



double CalcMedian(double a, double b, double c) {
    
    if (a <= 0 || b <= 0 || c <= 0 || (a + b <= c) || (a + c <= b) || (b + c <= a)) {
        return -1.0; 
    }

   
    double ma = 0.5 * sqrt(2 * b * b + 2 * c * c - a * a);
    return ma;
}

int main() {
  
    double test_cases[3][3] = {
        {5, 6, 7},     
        {3, 4, 5},     
        {8, 10, 12}    
    };


   cout << fixed << setprecision(2);
    cout << "Результати обчислення медіан ma:\n";
    cout << "-----------------------------------\n";

    for (int i = 0; i < 3; i++) {
        double a = test_cases[i][0];
        double b = test_cases[i][1];
        double c = test_cases[i][2];

        double median_a = CalcMedian(a, b, c);

        cout << "Трикутник " << i + 1 << " (сторона a=" << a 
                  << ", b=" << b << ", c=" << c << "): ";

        if (median_a >= 0) {
            cout << "m_a = " << median_a << endl;
        } else {
            cout << "Неможливо створити трикутник!" << endl;
        }
    }

   int GetDayOfWeek(int K, int N) {
    return ((N - 1 + K - 1) % 7) + 1;
}

int main() {
    int K, N;

    cout << "Введіть номер дня року K (1-365): ";
    cin >> K;

    cout << "Введіть день тижня для 1 січня N (1-7): ";
    cin >> N;

   
    if (K < 1 || K > 365 || N < 1 || N > 7) {
        cout << "Помилка: некоректні вхідні дані!" << endl;
        return 1;
    }

    int day_of_week = GetDayOfWeek(K, N);

    cout << "Для " << K << "-го дня року день тижня має номер: " 
              << day_of_week << endl;

    return 0;
}
}
}