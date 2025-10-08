#include <iostream>

class Employee {
    public:
        std::string name;
        int experience;
        int wagesPerHour;
        int hoursWorked;

        Employee() {
            name = "John";
            experience = 0;
            wagesPerHour = 500;
            hoursWorked = 100;
        }

        Employee(std::string name_, int experience_, int wagesPerHour_, int hoursWorked_){
            name = name_;
            experience = experience_;
            wagesPerHour = wagesPerHour_;
            hoursWorked = hoursWorked_;
        }
        
        void info() {
            std::cout << "Имя: " << name << std::endl;
            std::cout << "Стаж работы: " << experience << std::endl;
            std::cout << "Зарплата в час: " << wagesPerHour << "р" << std::endl;
            std::cout << "Часов отработано: " << hoursWorked << std::endl;
        }

        float premium() {     // возвращает процент
            if (experience < 1)      return 0;
            else if (experience < 3) return 0.05;
            else if (experience < 5) return 0.08;
            else if (experience > 5) return 0.15;
        }

        float monthWages() {
            int mainWages = wagesPerHour * hoursWorked;
            int pr = mainWages * premium();
            return mainWages + pr;
        }

};

int main() {
    setlocale(LC_ALL, "rus");
    
    Employee designer;
    Employee engineer("Steve", 4, 650, 111);

    designer.info();
    std::cout << "Премия: " << designer.premium() * 100 << "%\n";
    std::cout << "Зарплата: " << designer.monthWages() << "р\n";

    std::cout << std::endl;

    engineer.info();
    std::cout << "Премия: " << engineer.premium() * 100 << "%\n";
    std::cout << "Зарплата: " << engineer.monthWages() << "р\n";


}
