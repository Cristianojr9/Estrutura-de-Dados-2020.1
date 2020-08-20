#include "set.hpp"
#include <limits>

// Construir lista vazia, mas com capacidade máxima informada.
set::set(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção.
// Retornar indicativo de sucesso da inserção.
// NOTE Deve aumentar a capacidade caso necessário.
// NOTE Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
bool set::inserir(int elemento) {
    // TODO Implementação.
        // TODO Reorganizar o código
    if(tamanho < capacidade) {
        vetor[tamanho] = elemento;
        tamanho++;
    } else {
        int* aux = new int[capacidade * 2];        
        for(unsigned int i = 0; i < capacidade; i++) {
            aux[i] = vetor[i];
        }       
        aux[capacidade] = elemento;
        delete[] vetor;
        vetor = aux;
        remover(0);
        tamanho++;
        capacidade *= 2;
    }
}

// Remover "elemento" da coleção.
// Retornar indicativo de sucesso da remoção.
// NOTE Necessário preservar a ordem relativa dos que restarem.
bool set::remover(int elemento) {
    // TODO Implementação.
    if (pertence(elemento)) {
        for (unsigned int i = 0; i < tamanho; i++) {
            if(vetor[i] == elemento) {
                for(unsigned int j = i; j < tamanho; j++) {
                    int aux = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = aux;
                }
                tamanho--;
                return true;
            }
        }
        return false;
    } else {
        return false;
    }
}

// Determinar se "elemento" é um dos elementos ainda na coleção.
bool set::pertence(int elemento) const {
    // TODO Implementação.
    for(unsigned int i = 0; i < tamanho; i++) {
        if(vetor[i] == elemento) {
            return true;
        }  
    }
    return false;       
}


// --- Métodos de "Conjunto" ---

// Tornar o próprio conjunto (`this`) o resultado de sua união com o outro informado.
void set::uniao_com(set const &conjunto) {
    // TODO Implementação.
}

// Tornar o próprio conjunto (`this`) o resultado de sua intersecção com o outro informado.
void set::intersecao_com(set const &conjunto) {
    // TODO Implementação.
    for(unsigned l = 0; l < conjunto.tamanho; l++) {
        if(!pertence(conjunto.vetor[l])) {
            remover(conjunto.vetor[l]);
        }
    }
}

// Testar se este conjunto (`this`) está contido no outro informado.
bool set::esta_contido_em(set const &conjunto) const {
    // TODO Implementação.
}
