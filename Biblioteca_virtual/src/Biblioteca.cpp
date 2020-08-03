#include "../lib/Biblioteca.h"

#include <iostream>
using std::wcout;
using std::cout;
using std::cin;
using std::endl;

Biblioteca::Biblioteca()
{
}

bool Biblioteca::login()
{
    string email;
    int senha, contador(0);
    cout << "Para realizar o login informe os seguintes dados:\n"
        << "Insira o e-mail: ";
    //cin.ignore();
    getline(cin, email);
    cout << "Insira a senha: ";
    cin >> senha;
    for(size_t i(0); i < usuarios.size(); i++)
    {
        if(email == usuarios[i].getEmail() && senha == usuarios[i].getSenha())
            contador++;
    }
    system("cls");
    if(contador == 0)
    {
        cout << "E-mail ou senha incorretos!" << endl;
        return false;
    }
    else
        return true;
}

void Biblioteca::cadastrarLivro()
{
    string nome, autor, id;
    cout << "Informe os seguintes dados do livro:"
        << "\nNome: ";
    getline(cin, nome);
    cout << "Autor: ";
    getline(cin, autor);
    cout << "Identificador: ";
    getline(cin, id);
    cout << "Livro cadastrado!" << endl;
    system("pause");
    Livro livro(nome, autor, id);
    livros.push_back(livro);
}

void Biblioteca::cadastrarUsuario()
{
    string nome, email;
    int senha;
    cout << "Informe os seguintes dados para cadastrar-se: "
        << "\nNome: ";
    getline(cin, nome);
    cout << "E-mail: ";
    getline(cin, email);
    wcout << L"Senha numérica: ";
    cin >> senha;
    cin.ignore();
    wcout << L"\nUsuário cadastrado!" << endl;
    system("pause");
    Usuario usuario(nome, email, senha);
    usuarios.push_back(usuario);
}

void Biblioteca::realizarEmprestimo()
{
    int indice_u = pesquisarUsuario();
    int indice_l = pesquisarLivro();
    system("pause");
    system("cls");
    if(indice_l != -1 && indice_u != -1)
    {
        if(livros[indice_l].getEstado() == true)
        {
            livros[indice_l].setEstado(false);
            usuarios[indice_u].setQLivros(usuarios[indice_u].getQLivros() + 1);
            wcout << L"Empréstimo realizado!\n" << endl;
            system("pause");
        }
        else
        {
            wcout << L"Livro indisponível!\n" << endl;
            system("pause");
        }
    }
}

int Biblioteca::pesquisarLivro() const
{
    string nome;
    size_t contador(0);
    cout << "Insira o nome do livro: ";
    getline(cin, nome);
    system("cls");
    for(size_t i(0); i < livros.size(); i++)
    {
        if(nome == livros[i].getNome())
        {
            cout << "Dados do livro pesquisado:\n" << endl;
            livros[i].imprimeDados();
            cout << endl;
            contador++;
            return i;
        }
        else
            wcout << L"O livro informado não existe!" << endl;
    }
    if(contador == 0)
        return -1;
}

int Biblioteca::pesquisarUsuario() const
{
    string nome;
    size_t contador(0);
    wcout << L"Insira o nome do usuário: ";
    getline(cin, nome);
    system("cls");
    for(size_t i(0); i < usuarios.size(); i++)
    {
        if(nome == usuarios[i].getNome())
        {
            wcout << L"Dados do usuário pesquisado:\n" << endl;
            usuarios[i].imprimeDados();
            cout << endl;
            contador++;
            return i;
        }
    }
    if(contador == 0)
    {
        wcout << L"O usuário informado não existe!" << endl;
        return -1;
    }
}

void Biblioteca::verEstoque() const
{
    cout << "Livros em estoque:\n\n";
    for(size_t i(0); i < livros.size(); i++)
    {
        wcout << i+1 << L"º Livro\n";
        livros[i].imprimeDados();
    }
    cout << endl;
    system("pause");
}

void Biblioteca::verUsuarios() const
{
    wcout << L"Usuários cadastrados:\n\n";
    for(size_t i(0); i < usuarios.size(); i++)
    {
        wcout << i+1 << L"º Usuário\n";
        usuarios[i].imprimeDados();
        cout << endl;
    }
    cout << endl;
    system("pause");
}
