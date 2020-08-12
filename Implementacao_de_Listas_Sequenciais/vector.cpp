#include "vector.hpp"

#include <algorithm>
#include <limits>
#include <iostream>

// Construir lista vazia, mas com capacidade máxima informada.
vector::vector(unsigned int capacidade) {
    vetor = new int[capacidade];
    tamanho = 0;
    this->capacidade = capacidade;
}

// Construir lista com "tamanho" cópias do valor "inicial".
vector::vector(unsigned int tamanho, int inicial) {
    vetor = new int[tamanho];
    capacidade = tamanho;
    this->tamanho = tamanho;

    for(unsigned int i = 0; i < tamanho; i++) {
        vetor[i] = inicial;
    }
}


// --- Métodos de "Coleção" ---


// Inserir "elemento" na coleção. Sempre deve executar a inserção.
// FIXME Fazer realocação quando não houver espaço.
// NOTE  Observe que aumentar em apenas uma unidade não nos alivia da pressão que tínhamos antes...
void vector::inserir(int elemento) {
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
bool vector::remover(int elemento) {
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
bool vector::pertence(int elemento) {
    for(unsigned int i = 0; i < tamanho; i++) {
        if(vetor[i] == elemento) {
            return true;
        }  
    }
    return false;       

}


// --- Métodos de "Lista" ---

// Inserir "elemento" na lista de forma que ele passe a constar no índice "indice".
// NOTE Necessário preservar a ordem relativa dos demais elementos.
void vector::inserir_em(unsigned int indice, int elemento) {
    if (tamanho == capacidade) return;

    int aux = indice; 

    for(int i = tamanho; i >= aux; i--) {
        vetor[i + 1] = vetor[i];
    }
    
    vetor[aux] = elemento;
    tamanho++;
}

// Remover o elemento associado a "indice".
// Retornar indicativo de sucesso da remoção.
bool vector::remover_de(unsigned int indice) {
    if(indice >= tamanho || tamanho == 0) return false;

    for(unsigned int i = (indice + 1); i < tamanho; i++) {
        vetor[i - 1] = vetor[i];
    }

    tamanho--;
    
    return true;
}

// Retornar o valor associado ao índice "indice".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<int>::max()`
//      (forma de obter o maior valor representável).
int vector::obter_elemento_em(unsigned int indice) {
    if (indice < 0 || tamanho == 0 || indice >= tamanho) {
        return std::numeric_limits<int>::max();
    } else {
        for (unsigned int i = 0; i < tamanho; i++) {
            if (vetor[i] == vetor[indice]) {
                return vetor[indice];
            }
                
        }
    }

    return std::numeric_limits<int>::max();
}

// Retornar o índice associado a "elemento".
// NOTE Quando o índice for inválido, retornar `std::numeric_limits<unsigned int>::max()`
//      (forma de obter o maior valor representável).
unsigned int vector::obter_indice_de(int elemento) {
    for (unsigned int i = 0; i < tamanho; i++) {
        if (vetor[i] == elemento) {
            return i;
        }
    }
    
    return std::numeric_limits<unsigned int>::max();
}
