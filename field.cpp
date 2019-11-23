#include "field.h"
#include <ctime>
#include <cstdlib>

Field::Field(int n, int m)
{
    if ((n < 0) || (m < 0))
    {
        qDebug() <<  "Поле не сгенерировванно" << endl;
        return;
    }
    cell Buf;
    Buf.val = 0; Buf.open =false; ; Buf.flag = false;
    vector<cell> buf(unsigned(m),Buf);
    for (int i = 0; i < n; i++)
    {
        field.push_back(buf);
    }
    num_mines = 0;
    num_find_mines = 0;
    num_false_find_mines = 0;
    N = unsigned(n);
    M = unsigned(m);
}

void Field::Mine_generation(unsigned k)
{
    try
    {
          if (k > N*M / 5 + 1) throw 1;
          if (k <= 0) throw 0;

    } catch (int)
    {
        qDebug() << "недопустимое кол-во мин" << endl;
        return;
    }

  srand(time(0));
  unsigned n = 0,m = 0;
  num_mines = int(k);
  for (unsigned i = 0; i < k; i++)
  {
      while(true)
      {
          n = unsigned(rand()) % N;
          m = unsigned(rand()) % M;
          if (!check_mines(n,m)) break;
      }
      field.at(n).at(m).val = -1;
  }
}

void Field::Print_field()
{
    for(unsigned i = 0; i < N; i++)
    {
        for (unsigned j = 0; j < M; j++)
        {
            cout << field[i][j].val << " ";
        }
        cout << endl;
    }
}

bool Field::check_mines(unsigned n, unsigned m)
{
    try
    {
        if ((unsigned(n) > N) || (unsigned(m) > M))
            throw 1;
    } catch (int)
    {
        qDebug() << "Такой ячейка не существует" << endl;
        return false;
    }

    if (field.at(n).at(m).val == -1) return true;
    else return false;
}


void Field::Field_generation(int k)
{
    if (k < 0)
    {
        qDebug() << "кол-во мин задано не верно" << endl;
        return;
    }
    Mine_generation(unsigned(k));
    num_generation();
}

void Field::swap_flag(int n, int m)
{
    try
    {
        if ((n < 0) || (unsigned(n) > N) || (m < 0) || (unsigned(m) > M))
            throw 1;
    } catch (int)
    {
        qDebug() << "Такой ячейка не существует" << endl;
        return;
    }

    field.at(unsigned(n)).at(unsigned(m)).flag = !field.at(unsigned(n)).at(unsigned(m)).flag;

}

cell Field::state_cell(int n, int m)
{
    try
    {
        if ((n < 0) || (unsigned(n) > N) || (m < 0) || (unsigned(m) > M))
            throw 1;
    } catch (int)
    {
        qDebug() << "Такой ячейка не существует" << endl;
        cell buf; buf.val = -2; buf.flag = -2; buf.open = -2;
        return buf;
    }

    return field.at(unsigned(n)).at(unsigned(m));

}

void Field::num_generation()
{
    int k = 0;
    for (unsigned i = 1; i < N-1; i++)
    {
        for (unsigned j = 1; j < M-1; j++)
        {
            k = 0;
            if (field.at(i).at(j).val == -1) continue;
            if (field.at(i-1).at(j).val  == -1) k++;
            if (field.at(i-1).at(j-1).val  == -1) k++;
            if (field.at(i-1).at(j+1).val  == -1) k++;
            if (field.at(i+1).at(j).val  == -1) k++;
            if (field.at(i+1).at(j+1).val  == -1) k++;
            if (field.at(i+1).at(j-1).val  == -1) k++;
            if (field.at(i).at(j+1).val  == -1) k++;
            if (field.at(i).at(j-1).val  == -1) k++;
            field.at(i).at(j).val  = k;
        }
    }
}

Field::~Field()
{
    field.clear();
}
