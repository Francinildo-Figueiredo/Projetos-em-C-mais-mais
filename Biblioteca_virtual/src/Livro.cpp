#include "../lib/Livro.h"

#include <iostream>
using std::wcout;
using std::cout;
using std::endl;

Livro::Livro(string nom, string aut, string i, bool est)
{
    setNome(nom);
    setAutor(aut);
    setID(i);
    setEstado(est);
}

void Livro::setNome(string nom)
{
    nome = nom;
}

void Livro::setAutor(string aut)
{
    autor = aut;
}

void Livro::setID(string i)
{
    id = i;
}

void Livro::setEstado(bool est)
{
    estado = est;
}

string Livro::getNome() const
{
    return nome;
}

string Livro::getAutor() const
{
    return autor;
}

string Livro::getID() const
{
    return id;
}

bool Livro::getEstado() const
{
    return estado;
}

void Livro::imprimeDados() const
{
    cout << "Nome: " << getNome()
        << "\nAutor: " << getAutor()
        << "\nID: " << getID();
    if(getEstado())
        wcout << L"\nEstado: Disponível" << endl;
    else
       wcout << L"\nEstado: Indisponível" << endl;
}



