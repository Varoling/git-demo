#include <iostream>
#include <thread>

using namespace std;

class MoneyChange {
	int ruble;
public:
	void SetRuble(float ruble) {
		this->ruble = ruble;
	}
	int DollarChange() {
		int dollar = ruble / 92;
		return dollar;
	}
	int EuroChange() {
		int euro = ruble / 100;
		return euro;
	}

};

int main()
{
	setlocale(LC_ALL, "rus");

	int ruble;
	int dollar;
	int euro;
	MoneyChange rub;
	cout << "Введите количество рублей." << endl;
	cin >>  ruble;
	rub.SetRuble(ruble);

	thread th1([&rub, &dollar]() {
		dollar = rub.DollarChange();
		});
	thread th2([&rub, &euro]() {
		euro = rub.EuroChange();
		});
	th1.join();
	th2.join();
	cout << "Такое количество рублей можно обменять на " << dollar << " долларов" << endl;
	cout << "Такое количество рублей можно обменять на " << euro << " евро" << endl;


	return 0;
}
