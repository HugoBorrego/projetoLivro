#include <iostream>
#include <string>

using namespace std;

class Pessoa {
private:
    string nome;
    int idade;
    char sexo;

public:
    Pessoa(string nome, int idade, char sexo) {
        this->nome = nome;
        this->idade = idade;
        this->sexo = sexo;
    }

    void fazerAniversario() {
        this->idade++;
    }

    void setNome(string nome) {
        this->nome = nome;
    }

    string getNome() {
        return nome;
    }

    void setIdade(int idade) {
        this->idade = idade;
    }

    int getIdade() {
        return idade;
    }

    void setSexo(char sexo) {
        this->sexo = sexo;
    }

    char getSexo() {
        return sexo;
    }
};

class Publicacao {
public:
    virtual void abrir() = 0;
    virtual void fechar() = 0;
    virtual void folhear(int pagina) = 0;
    virtual void avancarPagina() = 0;
    virtual void voltarPagina() = 0;
};

class Livro : public Publicacao {
private:
    string titulo;
    string autor;
    int totalPaginas;
    int paginaAtual;
    bool aberto;
    Pessoa* leitor;

public:
    Livro(string titulo, string autor, int totalPaginas, Pessoa* leitor) {
        this->titulo = titulo;
        this->autor = autor;
        this->totalPaginas = totalPaginas;
        this->aberto = false;
        this->paginaAtual = 0;
        this->leitor = leitor;
    }

    void setTitulo(string titulo) {
        this->titulo = titulo;
    }

    string getTitulo() {
        return titulo;
    }

    void setAutor(string autor) {
        this->autor = autor;
    }

    string getAutor() {
        return autor;
    }

    void setTotalPaginas(int totalPaginas) {
        this->totalPaginas = totalPaginas;
    }

    int getTotalPaginas() {
        return totalPaginas;
    }

    void setPaginaAtual(int paginaAtual) {
        this->paginaAtual = paginaAtual;
    }

    int getPaginaAtual() {
        return paginaAtual;
    }

    void setAberto(bool aberto) {
        this->aberto = aberto;
    }

    bool getAberto() {
        return aberto;
    }

    void setLeitor(Pessoa* leitor) {
        this->leitor = leitor;
    }

    Pessoa* getLeitor() {
        return leitor;
    }

    void abrir() override {
        this->aberto = true;
    }

    void fechar() override {
        this->aberto = false;
    }

    void folhear(int pagina) override {
        if (pagina <= totalPaginas) {
            this->paginaAtual = pagina;
        }
    }

    void avancarPagina() override {
        if (paginaAtual < totalPaginas) {
            paginaAtual++;
        }
    }

    void voltarPagina() override {
        if (paginaAtual > 0) {
            paginaAtual--;
        }
    }
};

int main() {
    Pessoa pessoa1("Maria", 30, 'F');
    Pessoa pessoa2("Joao", 25, 'M');
    Pessoa pessoa3("Ana", 28, 'F');

    Livro livro1("O Alquimista", "Paulo Coelho", 208, &pessoa1);
    Livro livro2("Dom Casmurro", "Machado de Assis", 256, &pessoa2);

    livro1.abrir();
    livro1.folhear(50);

    cout << "Livro: " << livro1.getTitulo() << endl;
    cout << "Autor: " << livro1.getAutor() << endl;
    cout << "Pagina Atual: " << livro1.getPaginaAtual() << endl;
    cout << "Leitor: " << livro1.getLeitor()->getNome() << endl;

    return 0;
}
