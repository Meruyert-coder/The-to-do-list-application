#include <iostream>
#include <string>
const int MAX_TASKS = 100;

struct Task {
    std::string title;
    int priority;
    std::string description;
    std::string deadline;
};

struct ToDoList {
    Task tasks[MAX_TASKS];
    int taskCount;
};
void addTask(ToDoList& todo) {
    if (todo.taskCount < MAX_TASKS) {
        Task newTask;
        std::cout << "Введите название задачи: ";
        std::cin.ignore();
        std::getline(std::cin, newTask.title);
        std::cout << "Введите приоритет (целое число): ";
        std::cin >> newTask.priority;
        std::cin.ignore();
        std::cout << "Введите описание задачи: ";
        std::getline(std::cin, newTask.description);
        std::cout << "Введите дедлайн задачи (гггг-мм-дд чч:мм): ";
        std::getline(std::cin, newTask.deadline);

        todo.tasks[todo.taskCount++] = newTask;
        std::cout << "Задача успешно добавлена!\n";
    }
    else {
        std::cout << "Достигнуто максимальное количество задач!\n";
    }
}

void removeTask(ToDoList& todo) {
    if (todo.taskCount > 0) {
        std::cout << "Выберите номер задачи для удаления (от 1 до " << todo.taskCount << "): ";
        int index;
        std::cin >> index;

        if (index >= 1 && index <= todo.taskCount) {
            for (int i = index - 1; i < todo.taskCount - 1; ++i) {
                todo.tasks[i] = todo.tasks[i + 1];
            }
            todo.taskCount--;
            std::cout << "Задача успешно удалена!\n";
        }
        else {
            std::cout << "Некорректный номер задачи!\n";
        }
    }
    else {
        std::cout << "Список задач пуст!\n";
    }
}

void editTask(ToDoList& todo) {
    if (todo.taskCount > 0) {
        std::cout << "Выберите номер задачи для редактирования (от 1 до " << todo.taskCount << "): ";
        int index;
        std::cin >> index;

        if (index >= 1 && index <= todo.taskCount) {
            Task& task = todo.tasks[index - 1];

            std::cout << "Текущее название: " << task.title << "\nВведите новое название: ";
            std::cin.ignore();
            std::getline(std::cin, task.title);

            std::cout << "Текущий приоритет: " << task.priority << "\nВведите новый приоритет: ";
            std::cin >> task.priority;

            std::cin.ignore();
            std::cout << "Текущее описание: " << task.description << "\nВведите новое описание: ";
            std::getline(std::cin, task.description);

            std::cout << "Текущий дедлайн: " << task.deadline << "\nВведите новый дедлайн (гггг-мм-дд чч:мм): ";
            std::getline(std::cin, task.deadline);

            std::cout << "Задача успешно отредактирована!\n";
        }
        else {
            std::cout << "Некорректный номер задачи!\n";
        }
    }
    else {
        std::cout << "Список задач пуст!\n";
    }
}

void searchByTitle(const ToDoList& todo, std::string title) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        if (todo.tasks[i].title == title) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи с таким названием не найдены.\n";
    }
}

void searchByPriority(const ToDoList& todo, int priority) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        if (todo.tasks[i].priority == priority) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи с таким приоритетом не найдены.\n";
    }
}

void searchByDescription(const ToDoList& todo, std::string description) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        if (todo.tasks[i].description == description) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи с таким описанием не найдены.\n";
    }
}

void searchByDeadline(const ToDoList& todo, std::string deadline) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        if (todo.tasks[i].deadline == deadline) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи с таким дедлайном не найдены.\n";
    }
}

void displayTasks(const ToDoList& todo) {
    if (todo.taskCount > 0) {
        for (int i = 0; i < todo.taskCount; ++i) {
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    else {
        std::cout << "Список задач пуст!\n";
    }
}

void displayTasksForDay(const ToDoList& todo, std::string date) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        if (todo.tasks[i].deadline.substr(0, 10) == date) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи на эту дату не найдены.\n";
    }
}

void displayTasksForWeek(const ToDoList& todo, std::string startDate, std::string endDate) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        std::string taskDate = todo.tasks[i].deadline.substr(0, 10);
        if (taskDate >= startDate && taskDate <= endDate) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи на этот период не найдены.\n";
    }
}

void displayTasksForMonth(const ToDoList& todo, std::string month) {
    bool found = false;
    for (int i = 0; i < todo.taskCount; ++i) {
        std::string taskMonth = todo.tasks[i].deadline.substr(0, 7);
        if (taskMonth == month) {
            found = true;
            std::cout << "Название: " << todo.tasks[i].title << ", Приоритет: " << todo.tasks[i].priority
                << ", Описание: " << todo.tasks[i].description << ", Дедлайн: " << todo.tasks[i].deadline << "\n";
        }
    }
    if (!found) {
        std::cout << "Задачи на этот месяц не найдены.\n";
    }
}

void sortTasksByPriority(ToDoList& todo) {
    for (int i = 0; i < todo.taskCount - 1; ++i) {
        for (int j = 0; j < todo.taskCount - i - 1; ++j) {
            if (todo.tasks[j].priority < todo.tasks[j + 1].priority) {
                Task temp = todo.tasks[j];
                todo.tasks[j] = todo.tasks[j + 1];
                todo.tasks[j + 1] = temp;
            }
        }
    }
}

void sortTasksByDeadline(ToDoList& todo) {
    for (int i = 0; i < todo.taskCount - 1; ++i) {
        for (int j = 0; j < todo.taskCount - i - 1; ++j) {
            if (todo.tasks[j].deadline > todo.tasks[j + 1].deadline) {
                Task temp = todo.tasks[j];
                todo.tasks[j] = todo.tasks[j + 1];
                todo.tasks[j + 1] = temp;
            }
        }
    }
}
int main() {
    setlocale(0, "rus");
    ToDoList todo;
    todo.taskCount = 0;

    int choice = -1;

    while (choice != 0) {
        std::cout << "Выберите действие:" << std::endl
            << "1. Добавить задачу" << std::endl
            << "2. Удалить задачу" << std::endl
            << "3. Редактировать задачу" << std::endl
            << "4. Поиск по названию" << std::endl
            << "5. Поиск по приоритету" << std::endl
            << "6. Поиск по описанию" << std::endl
            << "7. Поиск по дедлайну" << std::endl
            << "8. Отобразить задачи" << std::endl
            << "9. Отобразить задачи на день" << std::endl
            << "10. Отобразить задачи на неделю" << std::endl
            << "11. Отобразить задачи на месяц" << std::endl
            << "12. Сортировать по приоритету" << std::endl
            << "13. Сортировать по дедлайну" << std::endl
            << "0. Выйти" << std::endl;
        std::cin >> choice;

        if (choice == 1) {
            addTask(todo);
        }
        else if (choice == 2) {
            removeTask(todo);
        }
        else if (choice == 3) {
            editTask(todo);
        }
        else if (choice == 4) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string title;
            std::cout << "Введите название для поиска: ";
            std::getline(std::cin, title);
            searchByTitle(todo, title);
        }
        else if (choice == 5) {
            int priority;
            std::cout << "Введите приоритет для поиска: ";
            std::cin >> priority;
            searchByPriority(todo, priority);
        }
        else if (choice == 6) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string description;
            std::cout << "Введите описание для поиска: ";
            std::getline(std::cin, description);
            searchByDescription(todo, description);
        }
        else if (choice == 7) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string deadline;
            std::cout << "Введите дедлайн для поиска (гггг-мм-дд чч:мм): ";
            std::getline(std::cin, deadline);
            searchByDeadline(todo, deadline);
        }
        else if (choice == 8) {
            displayTasks(todo);
        }
        else if (choice == 9) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string date;
            std::cout << "Введите дату для отображения (гггг-мм-дд): ";
            std::getline(std::cin, date);
            displayTasksForDay(todo, date);
        }
        else if (choice == 10) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string startDate, endDate;
            std::cout << "Введите начальную дату для недели (гггг-мм-дд): ";
            std::getline(std::cin, startDate);
            std::cout << "Введите конечную дату для недели (гггг-мм-дд): ";
            std::getline(std::cin, endDate);
            displayTasksForWeek(todo, startDate, endDate);
        }
        else if (choice == 11) {
            std::cin.ignore(); // Очистка буфера после cin
            std::string month;
            std::cout << "Введите месяц для отображения (гггг-мм): ";
            std::getline(std::cin, month);
            displayTasksForMonth(todo, month);
        }
        else if (choice == 12) {
            sortTasksByPriority(todo);
        }
        else if (choice == 13) {
            sortTasksByDeadline(todo);
        }
        else if (choice == 0) {
            std::cout << "Выход из программы." << std::endl;
        }
        else {
            std::cout << "Неверный выбор. Попробуйте еще раз." << std::endl;
        }
    }

    return 0;
}


