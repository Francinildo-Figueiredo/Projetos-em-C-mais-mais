#ifndef LIVRO_H
#define LIVRO_H

#include <string>
using std::string;

class Livro
{
    private:
        string nome;
        string autor;
        string id;
        bool estado;
    public:
        Livro(string = "", string = "", string = "", bool = true);
        void setNome(string);
        void setAutor(string);
        void setID(string);
        void setEstado(bool);
        string getNome() const;
        string getAutor() const;
        string getID() const;
        bool getEstado() const;
        void imprimeDados() const;
};
#endif