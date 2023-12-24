#include <bits/stdc++.h>
using namespace std;

vector<double> convertTemperature(double celsius)
{
    setprecision(6);
    double kelvin = celsius + 273.15;
    double fahrenheit = celsius * 1.80 + 32.00;
    return {kelvin, fahrenheit};
}

int main()
{
    vector<double> ans = convertTemperature(122.11);
    cout << ans[0] << " " << ans[1] << endl;
}