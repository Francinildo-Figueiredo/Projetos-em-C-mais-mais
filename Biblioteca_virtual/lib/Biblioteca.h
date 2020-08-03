#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

#include <vector>
using std::vector;

#include "../lib/Livro.h"
#include "../lib/Usuario.h"
#include "../src/Livro.cpp"
#include "../src/Usuario.cpp"

class Biblioteca
{
    private:
        vector<Livro> livros;
        vector<Usuario> usuarios;
    public:
        Biblioteca();
        bool login();
        void cadastrarLivro();
        void cadastrarUsuario();
        void realizarEmprestimo();
        int pesquisarLivro() const;
        int pesquisarUsuario() const;
        void verEstoque() const;
        void verUsuarios() const;
};

#endif