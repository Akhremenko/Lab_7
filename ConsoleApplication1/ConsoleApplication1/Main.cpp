#include <iostream>
#include <cstring>

using namespace std;

class Transportnoe_sredstvo
{
public:
	string nazvanie;

	Transportnoe_sredstvo()
	{
	};

	Transportnoe_sredstvo(string qwert)
	{
		nazvanie = qwert;
	}

	friend Transportnoe_sredstvo operator +(Transportnoe_sredstvo& V1, Transportnoe_sredstvo& V2)
	{
		return Transportnoe_sredstvo(V1.nazvanie+V2.nazvanie);
	}


};

template<class Type>
class Vektor
{
public:
	Type Arr[3];

	Vektor(Type A, Type B, Type C)
	{
		Arr[0] = A;
		Arr[1] = B;
		Arr[2] = C;
	}

	friend Vektor operator +(Vektor& V1, Vektor& V2)
	{
		return Vektor(V1.Arr[0] + V2.Arr[0], V1.Arr[1] + V2.Arr[1], V1.Arr[2] + V2.Arr[2]);
	}

	Type operator()(int index)
	{
		return Arr[index];
	}

	friend Type operator == (Vektor& V1, Vektor& V2)
	{
		return ((V1.Arr[0] == V2.Arr[0]) && (V1.Arr[1] == V2.Arr[1]) && (V1.Arr[2] == V2.Arr[2]));
	}

	friend Type operator > (Vektor& V1, Vektor& V2)
	{
		return ((V1.Arr[0] > V2.Arr[0]) && (V1.Arr[1] > V2.Arr[1]) && (V1.Arr[2] > V2.Arr[2]));
	}


	~Vektor() {};
	void Vektor::print()
	{
		cout << "Arr[0] = " << Arr[0] << endl;
		cout << "Arr[1] = " << Arr[1] << endl;
		cout << "Arr[2] = " << Arr[2] << endl;
	}
};

void main()
{
	setlocale(LC_CTYPE, "Russian");
	Vektor<int> V1(1, 2, 3);
	Vektor<int> V2(4, 5, 6);
	Vektor<int> V3(0, 0, 0);
	Vektor<int> V4(5, 7, 9);
	V3 = V1 + V2;
	V3.print();
	cout << V2(1) << endl;

	if (V3 == V4)
	{
		cout << "Вектора равны" << endl;
	}

	if (V2 > V1)
	{
		cout << "Вектор V2>V1" << endl << "________________" << endl;
	}

	Vektor<double> V1_1(0.1, 0.2, 0.3);
	Vektor<double> V2_2(0.4, 0.5, 0.6);
	Vektor<double> V3_3(0, 0, 0);
	Vektor<double> V4_4(0.5, 0.7, 0.9);
	V3_3 = V1_1 + V2_2;
	V3_3.print();
	cout << V2_2(1) << endl;

	if (V3_3 == V4_4)
	{
		cout << "Вектора равны" << endl;
	}

	if (V2_2 > V1_1)
	{
		cout << "Вектор V2_2>V1_1" << endl;
	}

	Transportnoe_sredstvo as("lol");
	Transportnoe_sredstvo sd("lal");
	Transportnoe_sredstvo df("lul");
	Transportnoe_sredstvo fg("8");

	Vektor<Transportnoe_sredstvo> V_23(as, sd, df);
	Vektor<Transportnoe_sredstvo> V_34(fg, fg, fg);
	Vektor<Transportnoe_sredstvo> V_45(df, sd, as);

	V_45 = V_23 + V_34;
	printf("%s", (V_45.Arr[0].nazvanie).c_str());
	cout << endl;
	printf("%s", (V_45.Arr[1].nazvanie).c_str());
	cout << endl;
	printf("%s", (V_45.Arr[2].nazvanie).c_str());
	cout << endl;
}