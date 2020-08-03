#include "../lib/Usuario.h"

#include <iostream>
using std::cout;
using std::endl;

Usuario::Usuario(string nom, string eml, int snh, int ql)
{
    setNome(nom);
    setEmail(eml);
    setSenha(snh);
    setQLivros(ql);
}

void Usuario::setNome(string nom)
{
    nome = nom;
}

void Usuario::setEmail(string eml)
{
    email = eml;
}

void Usuario::setSenha(int snh)
{
    senha = snh;
}

void Usuario::setQLivros(int ql)
{
    q_livros = ql;
}

string Usuario::getNome() const
{
    return nome;
}

string Usuario::getEmail() const
{
    return email;
}

int Usuario::getSenha() const
{
    return senha;
}

int Usuario::getQLivros() const
{
    return q_livros;
}

void Usuario::imprimeDados() const
{
    cout << "Nome: " << getNome()
        << "\nE-mail: " << getEmail()
        << "\nQuantidade de livros emprestados: " << getQLivros() << endl;
}