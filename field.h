#ifndef FIELD_H
#define FIELD_H
#include <vector>
#include <iostream>
#include <Qdebug>

using namespace std;




struct cell
{
    int val;
    bool open;
    bool flag;
};

class Field
{
private:
    int num_mines; // кол-во мин
    int num_find_mines; // кол-во обнаруженных мин(помеченных)
    int num_false_find_mines; //кол-во неправильно помеченных мин
    unsigned N; // размер поля
    unsigned M; // размер поля

    void Mine_generation(unsigned k); // генерирует мины
    void num_generation(); // генерирует цифры вокруг мин



public:
    vector <vector<cell>> field;

    Field(int n, int m);
    void Print_field(); //выводит состояние поля

    bool check_mines(unsigned n,unsigned m); //проверяет ячейку на то мина ли на
    void Field_generation(int k); // генерирует поле
    void swap_flag(int n, int m);

    cell state_cell(int n, int m); //возвращает состояние ячейки


    ~Field();
};

#endif // FIELD_H
