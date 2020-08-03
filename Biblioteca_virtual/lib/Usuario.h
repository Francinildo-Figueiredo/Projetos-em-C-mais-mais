#ifndef USUARIO_H
#define USUARIO_H

#include <string>
using std::string;

class Usuario
{
    private:
        string nome;
        string email;
        int senha;
        int q_livros;
    public:
        Usuario(string = "", string = "", int = 0, int = 0);
        void setNome(string);
        void setEmail(string);
        void setSenha(int);
        void setQLivros(int);
        string getNome() const;
        string getEmail() const;
        int getSenha() const;
        int getQLivros() const;
        void imprimeDados() const;
};

#endif