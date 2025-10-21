#include <iostream>
using namespace std;

class clsCalculator
{
private:
	short _LastInput = 0;
	short _Result = 0;
    string _LastOperation = "";
	float _PreviousResult = 0;

	void ProtectDivisionByZero(float& Number)
    {
        if (Number == 0)
            Number = 1;
    }

public:

    void Add(float Number)
    {
        _LastInput = Number;
        _PreviousResult = _Result;
        _LastOperation = "Adding";
        _Result += Number;
    }
    void Sub(float Number)
    {
        _LastInput = Number;
        _PreviousResult = _Result;
        _LastOperation = "Subtracting";
        _Result -= Number;
    }
    void Div(float Number)
    {
        _LastInput = Number;
        ProtectDivisionByZero(Number);
        _PreviousResult = _Result;
        _LastOperation = "Dividing";
        _Result /= Number;
    }
    void Mul(float Number)
    {
        _LastInput = Number;
        _PreviousResult = _Result;
        _LastOperation = "Multiplying";
        _Result *= Number;
    }
    float GetFinalResult()
    {
        return _Result;
    }
    void Clear()
    {
        _LastInput = 0;
        _PreviousResult = 0;
        _LastOperation = "Clear";
        _Result = 0;
    }
    void CancelLastOperation()
    {
        _LastInput = 0;
        _LastOperation = "Cancelling Last Operation";
        _Result = _PreviousResult;
    }
    void PrintResult()
    { 
        cout << "Result ";
        cout << "After " << _LastOperation << " " << _LastInput << " is: " << _Result << endl;
    }

};

int main()
{
    clsCalculator Calculator1;

    Calculator1.Clear();

    Calculator1.Add(10);
    Calculator1.PrintResult();

    Calculator1.Add(100);
    Calculator1.PrintResult();

    Calculator1.Sub(20);
    Calculator1.PrintResult();

    Calculator1.Div(0);
    Calculator1.PrintResult();

    Calculator1.Div(2);
    Calculator1.PrintResult();

    Calculator1.Mul(3);
    Calculator1.PrintResult();

    Calculator1.CancelLastOperation();
    Calculator1.PrintResult();

    Calculator1.Clear();
    Calculator1.PrintResult();

    system("pause>0");
    return 0;
}
 