#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount { // Класс представляет банковский счет. Номер счета, владельцев, банаса и историей операций на счете
private:
    string accountNumber; // Строка представляет номер банковского счета
    string ownerName; // Строка, представляющая имя владельца счета
    double balance; // Даблавская переменная, которая представляет текущий баланс на счете
    vector<string> transactionHistory; // Вектор строк, который представляет историю операций на счете

public:
    BankAccount(string number, string owner, double initialBalance) // Конструктор класса, который создаеть объект банковского счета с заданным номером.
        : accountNumber(number), ownerName(owner), balance(initialBalance) {}

    void deposit(double amount) { // Метод для внесения денег на счет. Принимает сумму денег в качестве аргумента, если сумма положительная, баланс увеличивается на эту сумму.
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Депонированный " + to_string(amount) + " долларов.");
        }
    }

    void withdraw(double amount) { // Метод для снятия денег со счета, принимает сумму денег в качестве аргумента.
        if (amount > 0 && amount <= balance) { // Если сумма положительная и не превышает балан, баланс уменьшается на эту сумму, и запись добавляется
            balance -= amount;
            transactionHistory.push_back("Отозвано " + to_string(amount) + "долларов.");
        }
    }

    vector<string> getTransactionHistory() const { // Метод для получения истории операций на счете. 
        return transactionHistory; // Возвращает вектор строк, содержающи описания операций
    }

    // Метод для вывода информации о банковском счете, включая номер счета, владельца, балан и историю операций.
    void displayInfo() const {
        cout << "Номер счета: " << accountNumber << "\n";
        cout << "Владелец: " << ownerName << "\n";
        cout << "Баланс: " << balance << " долларов\n";
        cout << "История транзакций:\n";
        for (const string& transaction : transactionHistory) {
            cout << "- " << transaction << "\n";
        }
    }
};

class Client { // Этот класс представляет клиент банка, содержит информацию о клиенте и списках его банковских счетов
private:
   string firstName; // строка, представляющая имя клиента
   string lastName; // Строка, представляющая фамлию клиента
   vector<BankAccount> accounts; // Вектор объектов "BankAccount", представляющих счета клиента

public:
    Client(std::string first, string last) // Конструктор класса. Создает объект клиента с заданным именем и фамилией
        : firstName(first), lastName(last) {}

    void addAccount(BankAccount account) { // Метод для добавления банковского счета к списку счетов клиента
        accounts.push_back(account);
    }

    void displayInfo() const { // Метод для вывода информации о клиенте и всех его банковских счетах
        cout << "Клиент: " << firstName << " " << lastName << "\n";
        cout << "Счета:\n";
        for (const BankAccount& account : accounts) {
            account.displayInfo();
            cout << "\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "russian");
    // Создаем два объектов класса "BankAccount" для представления банковских счетовю
    BankAccount account1("12345", "John Doe", 1000.0);
    BankAccount account2("67890", "Jane Smith", 500.0);

    account1.deposit(200.0);
    account1.withdraw(50.0);
    account2.deposit(100.0);

    Client client("Alice", "Johnson"); // Создаем объекта класса Client для представления клиента и добавление к нему банковский счетов
    client.addAccount(account1);
    client.addAccount(account2);

    client.displayInfo();

    return 0;
}
